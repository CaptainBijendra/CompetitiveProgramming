#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_M 10000005
#define f first
#define s second

using namespace std;

bool vis[MAX_M], have[MAX_M];

int ar[MAX_M], ar2[MAX_M];
int N, M;

void DFS (int num) {
    vis[num] = true;
    
    if (have[num] && !vis[num ^ ((1 << N) - 1)])
        DFS (num ^ ((1 << N) - 1));
    
    for (int i = 0; i < N; i ++) {
        if ((num & (1 << i)) && !vis[(num ^ (1 << i))])
            DFS ((num ^ (1 << i)));
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i ++) {
        cin >> ar[i];
        have[ar[i]] = true;
    }      

    int ans = 0;
    int lft = 0;

    for (int i = 0; i < M; i ++) {
        if (!vis[ar[i]]) {
            ans ++;
            vis[ar[i]] = true;
            DFS ((ar[i] ^ ((1 << N) - 1)));
        }     
    }
    
    cout << ans << endl;
    return (0);
}