//x = 2^k * n [ [ n * (x + 1) - (n - 1)(x - 2^k + 1) ]

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MOD 1000000007

using namespace std;

long long fast_expo (long long base, long long pow) {
    if (pow == 1)
        return (base);
    if (pow == 0)
        return (1);
    
    if (pow % 2 == 0) {
        long long a = fast_expo(base, pow / 2);
        return ((a * a) % MOD);
    }
    
    else {
        long long a = fast_expo(base, (pow - 1) / 2);
        return ((((a * a) % MOD) * base) % MOD);
    }
}

long long N, K;

int main() {
    cin >> N >> K;
    
    if (N == 0) {
        cout << 0 << endl;
        return (0);
    }
    
    N %= MOD;
 
    long long x = (fast_expo(2, K) * N) % MOD;
    long long extra = (fast_expo(2, K));
    long long prod1 = x - extra + 1;
    
    prod1 = (((prod1 + MOD) % MOD + MOD) % MOD + MOD) % MOD;
    
    long long answer = ((N * (x + 1)) % MOD);
    answer -= ((N - 1) * (prod1) % MOD);
    
    answer = ((answer + MOD) % MOD);
    
    cout << answer << endl;
    return (0);
}