#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int vis[MAX_N];
int ans;
int N, K;

int DFS (int ind) {
    vis[ind] = true;
    
    if (con[ind].size() == 1 && ind != 0)
        return (1);
    
    int a = 0;
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            a += DFS (con[ind][i]);
        }
    }
    
    if (ind == 0 && con[ind].size() == 1)
        ans += (a > 0);
    
    if (a <= 2 * K)
        ans += (a / 2);
    
    if (a > 2 * K) {
        ans += K;
        return (0);
    }

    if (a % 2 == 1)
        return (1);

    return (0);
}

int main() {
    cin >> N >> K;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    DFS (0);
    
    cout << ans << endl;
    return (0);
}