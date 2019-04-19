#include <iostream>
#include <algorithm>
#include <map>

#define MAX_N 11
#define MAX_M 100005
#define f first
#define s second

using namespace std;

map<int, int> pos[MAX_N];

bool in[MAX_M];

int ar[MAX_N][MAX_M];
int N, M;

int main() {
    cin >> M >> N;
    
    for (int i = 0; i < N; i ++) {
        int a;
        
        for (int j = 0; j < M; j ++) {
            cin >> a;
            pos[i][a] = j;
        }
    }
    
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < M; j ++)
            ar[i][j] = pos[i][j + 1];
    
    int streak = 1;
    int prev = 0;
    
    long long ans = 0;
    bool change = false;
    
    for (int i = 1; i < M; i ++) {
        if (streak >= 1) {
            int diff = ar[0][i] - ar[0][prev];
            bool pos = true;
            
            for (int j = 1; j < N; j ++)
                if (ar[j][i] - ar[j][prev] != diff) {
                    pos = false;
                    break;
                }
            
            if (!pos) {
                if (change)
                    prev = i;
            }
            
            else {
                prev = i;
                in[i] = true;
                
                streak ++;
                change = true;
            }
        }
    }

    for (int i = 0; i < M; i ++)
        if (in[i])
            cout << i << endl;

    cout << ans << endl;
    return (0);
}