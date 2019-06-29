#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 10005
#define f first
#define s second

using namespace std;

int ar[55][MAX_N];
int M, N;

int main() {
    cin >> M >> N;
    
    int cnt;
    for (int i = 0; i < M; i ++) {
        cin >> cnt;
    
        for (int j = 0; j < cnt; j ++)
            cin >> ar[i][j];
        
        sort(ar[i], ar[i] + cnt);
    }   
    
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < M; j ++) {
            if (i == j) { continue; }
            
            vector<bool> vis(MAX_N);
            for (int k = 0; k < N; k ++)
                vis[ar[i][k]] = true;
        
            bool flag = false;
            for (int k = 0; k < N; k ++) {
                if (ar[j][k] == 0) { break; }
                if (vis[ar[j][k]]) {
                    flag = true;
                    break;
                }
            }
            
            if (!flag) {
                cout << "impossible" << endl;
                return (0);
            }
        }
    }
    
    cout << "possible" << endl;
    return (0);
}