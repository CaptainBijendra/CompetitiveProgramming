#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> con[MAX_N];

bool vis[MAX_N];
int N;

int DFS (int ind) {
    vis[ind] = true;
    
    int ans = 0;
    
    for (int i = 0; i < con[ind].size(); i ++) 
        if (!vis[con[ind][i].f]) 
            ans = max(ans, DFS (con[ind][i].f) + con[ind][i].s);
    
    vis[ind] = false;
    return (ans);
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N - 1; i ++) {
        int a, b, c;
        
        cin >> a >> b >> c;
        con[a].push_back(ii(b, c));
        con[b].push_back(ii(a, c));
    }
    
    cout << DFS (0) << endl;
    return (0);
}