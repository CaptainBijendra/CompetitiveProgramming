#include <stdio.h>

#define MAX_N 505
#define MAX_M 5005
#define f first
#define s second

int fact[MAX_M * 100], DP[MAX_M][MAX_M];
int N, M;

int min(int a, int b) {
    return (a < b ? a : b);
}

int main() {
    scanf("%d %d", &N, &M);
    
    fact[0] = 1;
    
    for (int i = 1; i < MAX_M; i ++) {
        fact[i] = fact[i - 1] * 10;
        fact[i] %= N;
    }
    
    for (int i = 0; i < MAX_N; i ++) 
        for (int j = 0; j < MAX_M; j ++) 
            DP[i][j] = 20000009;
    
    DP[0][0] = 0;
    
    for (int j = 0; j <= M; j ++) {
        for (int i = 0; i <= N; i ++) {
            for (int k = 0; k <= 9; k ++) {
                int cur_mod;
                
                if (j + k < MAX_M && DP[i][j] < 20000009) { 
                    for (int l = 0; l < 300; l ++) { 
                        cur_mod = (k * fact[l + DP[i][j]] + i) % N;
                        DP[cur_mod][j + k] = min(DP[cur_mod][j + k], l + DP[i][j] + 1);
                    }
                }        
            }
        }
    }
    
    if (DP[0][M] == 20000009) {
        printf ("-1\n");
        return (0);
    }
    
    int c_mod = 0;
    int c_sum = M;

    while (DP[c_mod % N][c_sum] != 0) {
        int flag = 0;
        
        for (int i = 1; i <= 9; i ++) {
            for (int j = DP[c_mod % N][c_sum] - 1; j >= 0; j --) { 
                int nxt_mod = ((c_mod - ((i * fact[DP[c_mod % N][c_sum] - 1]) % N) + N) % N + N) % N;

                if (DP[nxt_mod % N][c_sum - i] == j) {
                    printf("%d", i);

                    for (int k = 0; k < (DP[c_mod % N][c_sum] - 1 - j); k ++) 
                        printf ("0");

                    c_mod = nxt_mod;
                    c_sum -= i;

                    flag = 1;
                    break;
                }
            }
            
            if (flag)
                break;
        }
    }
    
    if (c_sum > 0)
        printf("%d", c_sum);
    
    printf("\n");
    return (0);
}