#include <iostream>
#include <algorithm>

#define MAX_N 105

using namespace std;

bool R[MAX_N][MAX_N], S[MAX_N][MAX_N];

int DP_R[MAX_N][MAX_N], DP_S[MAX_N][MAX_N];
int N, M;

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            char a;
            cin >> a;
            
            if (a == 'R') {
                R[i][j] = true;
                S[i][j] = false;
            }
            
            else {
                S[i][j] = true;
                R[i][j] = false;
            }    
        }
    }
    
    for (int ii = 0; ii < 1; ii ++) {
        int best = -1;
        int best_r, best_c, col;
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                if (R[i][j]) { DP_R[i][j] = 1; }
                else { DP_R[i][j] = 0; }
            }
        }
            
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                if (S[i][j]) { DP_S[i][j] = 1; }
                else { DP_S[i][j] = 0; }
            }
        }
            
        for (int i = N - 1; i >= 0; i --) {
            for (int j = M - 1; j >= 0; j --) {
                DP_R[i][j] = min(min(DP_R[i + 1][j + 1], DP_R[i + 1][j]), DP_R[i][j + 1]) + 1;        
                
                if (DP_R[i][j] > best) {
                    best = DP_R[i][j];
                    best_r = i; best_c = j;
                    col = 0;
                }
            }
        }        
        
        for (int i = N - 1; i >= 0; i --) {
            for (int j = M - 1; j >= 0; j --) {
                DP_S[i][j] = min(min(DP_S[i + 1][j + 1], DP_S[i + 1][j]), DP_S[i][j + 1]) + 1;        
                
                if (DP_S[i][j] > best) {
                    best = DP_S[i][j];
                    best_r = i; best_c = j;
                    col = 1;
                }
            }
        }
        
        for (int i = 0; i < N; i ++)  {
            for (int j = 0; j < M; j ++) {
                if (R[i][j]) { cout << 'R'; }
                else { cout << 'S'; }
            }
            
            cout << endl;
        }
        
        cout << "BEST: " << best << " BEST_R: " << best_r << " BEST_C: " << best_c << " COL: " << col << endl;
        cout << "DP:______________________" << endl;
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                cout << i << " " << j << " " << DP_R[i][j] << " " << DP_S[i][j] << endl;
            }
        }
        
        bool flag = true;
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                if (R[i][j] && S[i][j]) { continue; }
                else { flag = false; break; }
            }
            
            if (!flag)
                break;
        }
        
        if (flag)
            break;
    }
}