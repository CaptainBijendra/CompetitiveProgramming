#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <string.h>
#include <math.h>

#define MOD   1000000007
#define MAX_V 1000005
#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii; 

long long cnt[MAX_V], f[MAX_V], DP[MAX_V];

int ar[MAX_N];
int N;

int main() {
    cin >> N;

    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        cnt[ar[i]] ++;
    }

    long long x = 1;
    
    for (int i = 1; i < MAX_V; i ++) {
        f[i] = (i * x) % MOD;
        
        x *= 2;
        x %= MOD;
    }
    
    long long ans = 0ll;
    
    for (int i = MAX_V - 1; i >= 2; i --) { //What is the gcd value
        long long occ = cnt[i];

        for (int j = 2 * i; j < MAX_V; j += i) {
            DP[i] = (DP[i] - DP[j] + MOD) % MOD;    
            occ += cnt[j];            
        }
        
        DP[i] += f[occ];
        
        ans += (DP[i] * i) % MOD;
        ans %= MOD;
    }
    
    cout << ans << endl;
    return (0);
}