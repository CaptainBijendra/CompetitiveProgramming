#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>

#define MOD2 1610612741
#define MOD 1000000007
#define MAX_N 3005
#define f first
#define s second

using namespace std;

unordered_map<long long, int> cmp[MAX_N];

long long DP[MAX_N], ar[MAX_N];
int N;

int main() {
    cin >> N;
    
    long long ans = 0ll;
    long long hsh = 0ll;
    
    int x, y;
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        DP[i + 1] = 1;
        hsh = 0ll;

        for (int j = i; j >= 0; j --) {
            DP[j] = 0;
            hsh = hsh * 769 + ar[j] + 1;
            hsh %= MOD2;
            
            for (int len = 1; len <= 4; len ++) {
                if (j + len > (i + 1))
                    break;
                    
                if (len != 4)
                    DP[j] = (DP[j] + DP[j + len]) % MOD;
                else {
                    y = 8 * ar[j] + 4 * ar[j + 1] + 2 * ar[j + 2] + ar[j + 3];
                
                    if (y != 3 && y != 5 && y != 14 && y != 15)
                        DP[j] = (DP[j] + DP[j + len]) % MOD;
                }
            }
            
            if (!cmp[i - j + 1][hsh]) {
                ans = (ans + DP[j]) % MOD;
                cmp[i - j + 1][hsh] = 1;
            }
            
            ans %= MOD;
        }
        
        cout << ans << endl;
    }

    return (0);
}