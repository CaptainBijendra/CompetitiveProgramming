#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <vector>

#define MAX_A 200005
#define MAX_N 105
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
 
ii cow[MAX_N];

map<int, int> mp;
 
int pos[MAX_A];

int DP[MAX_N][MAX_N][MAX_N];
int N, S;
 
int height(int a, int b){
    return (S / max(1, cow[b].f - cow[a].f));
}
 
int solve(int l, int r, int x){
    if(l > r) 
        return 0;
    
    if (DP[l][r][pos[x]] != -1)
        return DP[l][r][pos[x]];
    if (cow[l].s <= x)
        return DP[l][r][pos[x]] = solve(l + 1, r, x);
    if (cow[r].s <= x) 
        return DP[l][r][pos[x]] = solve(l, r - 1, x);
    
    int result = 1e9;
    
    if (pos[height(l, r)] > pos[x]){
        result = solve(l, r, height(l, r)) + 1;
    }
    
    for(int i = l; i < r; i ++){
        result = min(result, solve(l, i, x) + solve(i + 1, r, x));
    }

    return DP[l][r][pos[x]] = result;
}
 
int main(){
    cin >> N >> S;
    
    for (int i = 0; i < MAX_N; i ++) 
        for (int j = 0; j < MAX_N; j ++) 
            for (int k = 0; k < MAX_N; k ++)
                DP[i][j][k] = -1;
    
    int a, b;    
    for(int i = 1; i <= N; i ++){
        cin >> a >> b;
        mp[a] = max(mp[a], b);
    }
    
    int p = 0;
    
    map<int, int> ::iterator it = mp.begin();
    
    while (it != mp.end()) {
        cow[++p] = *it;
        pos[it->second] = 1;
        it++;
    }
    
    for(int i = 1; i <= S; i ++)
        pos[i] += pos[i-1];
        
    cout << solve(1, p, 0) << endl;
    return (0);
}