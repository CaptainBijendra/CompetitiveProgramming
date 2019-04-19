#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 255

using namespace std;

bool ar[MAX_N][MAX_N];

int DP[MAX_N][MAX_N], cnt[MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        string str;
        cin >> str;
    
        for (int j = 0; j < N; j ++) 
            ar[i][j] = (str[j] == '1');
    }
    
    for (int i = 0; i < N; i ++) 
        for (int j = 0; j < N; j ++) 
            DP[i][j] = ar[i][j];
    
    for (int i = N - 2; i >= 0; i --) 
        for (int j = N - 2; j >= 0; j --) 
            if (ar[i + 1][j] && ar[i][j + 1] && ar[i + 1][j + 1] && ar[i][j]) 
                DP[i][j] = min(min(DP[i + 1][j], DP[i][j + 1]), DP[i + 1][j + 1]) + 1;
                
    for (int i = 0; i < N - 1; i ++) {
        for (int j = 0; j < N - 1; j ++) {
            for (int k = 2; k <= DP[i][j]; k ++) {
                cnt[k] ++;
            }
            
            cout << i << " " << j << " " << DP[i][j] << endl;
        }
    }
    
    for (int i = 2; i <= N; i ++) {
        if (cnt[i] == 0)
            break;
        
        cout << i << " " << cnt[i] << endl;
    }

    return (0);
}