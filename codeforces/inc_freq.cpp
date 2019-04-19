#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 600005
#define f first
#define s second

using namespace std;

vector<int> loc[MAX_N];

int ar[MAX_N], pre[MAX_N], DP[MAX_N];
int N, C;

int sum(int i, int j) {
    return (pre[j] - (i == 0 ? 0 : pre[i - 1]));
}

int calc(int ind) {
    int ans = (loc[ind].size() == 1);
    
    DP[0] = 1;

    for (int i = 1; i < loc[ind].size(); i ++) {
        DP[i] = max(DP[i - 1] + 1 - sum(loc[ind][i - 1], loc[ind][i]), 1 - sum(loc[ind][i - 1], loc[ind][i]));
        ans = max(ans, DP[i]);
    }    
    
    return (ans);
}

int main() {
    cin >> N >> C;
    
    for (int i = 0; i < N; i ++) { 
        cin >> ar[i];
        loc[ar[i]].push_back(i);
        
        pre[i] = (i == 0 ? 0 : pre[i - 1]) + (ar[i] == C);
    }
    
    int ans = 0;
    
    for (int i = 1; i < MAX_N; i ++) 
        if (i != C) 
            ans = max(ans, sum(0, N - 1) + calc(i));
    
    cout << ans << endl;
    return (0);
}