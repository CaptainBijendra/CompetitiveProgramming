#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MOD 98189036755454
#define MAX_N 100005
#define f first
#define s second

using namespace std;

map<long long, int> fnd;

long long pre[MAX_N][31], ar[MAX_N], powr[50];
long long N, K;

int main() {
    cin >> N >> K;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
    
        for (int j = 0; j < K; j ++) {
            if (i > 0)
                pre[i][j] = pre[i - 1][j];
            
            if (ar[i] & (1 << j)) {
                if (i > 0)
                    pre[i][j] ++;
                else
                    pre[i][j] = 1;
            }           
        }
    }
    
    powr[0] = 1;
    for (int i = 1; i < 50; i ++) {
        powr[i] = powr[i - 1] * 23;
        powr[i] %= MOD;
    }   
    
    fnd[0] = 1;
    
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        long long sml = MAX_N;
        
        for (int j = 0; j < K; j ++)
            sml = min(sml, pre[i][j]);
    
        long long c_num = 0;
        
        for (int j = 0; j < K; j ++) {
            c_num += powr[j] * (pre[i][j] - sml);
            c_num %= MOD;
        }
        
        if (fnd[c_num]) 
            ans = max(ans, i - (fnd[c_num]) + 2);
        else
            fnd[c_num] = (i + 2);
    }   
    
    cout << ans << endl;
    return (0);    
}