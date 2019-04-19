#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

int ar[MAX_N];
int N, M;

long long sumOdd(long long a, long long b) {
    long long x = max(0ll, 2 * a - 1);
    long long y = 2 * b - 1;

    long long rep = (x + y) % MOD;
    long long di = ((b - a + 1) / 2) % MOD;

    if ((b - a + 1) % 2 == 1)
        return (((rep * di) % MOD + rep / 2) % MOD);
    else
        return ((rep * di) % MOD);
}

long long sumEven(long long a, long long b) {
    long long a1 = (((b % MOD) * ((b + 1) % MOD)) % MOD);
    long long b1 = (((a % MOD) * ((a - 1) % MOD)) % MOD);
    return ((a1 - b1 + MOD) % MOD + MOD) % MOD;
}

long long solve(long long num) {
    if (num == 1ll)
        return (1);
    if (num == 0)
        return (0);
    
    long long mult = 1ll;
    long long odd = 0ll, even = 0ll;
    int cnt = 1;
    
    for (int i = 0; i < 62; i ++) {
        if (odd + even + mult >= num)
            break;
        
        if (cnt % 2 == 1)
            odd += mult;
        else
            even += mult;
        
        mult *= 2ll;
        cnt ++;
    }
    
    long long ans = 0ll;
    
    if (cnt % 2 == 1)
        ans = sumOdd(odd + 1, odd + num - (odd + even));
    else
        ans = sumEven(even + 1, even + num - (odd + even));
        
    cnt --;
    ans = (ans + sumEven(1, even)) % MOD;
    ans = (ans + sumOdd(1, odd)) % MOD;
    
    return (ans);
}

int main() {
    long long L, R;
    cin >> L >> R;
    
    cout << ((solve(R) - solve(L - 1) + MOD) % MOD + MOD) % MOD << endl;
    return (0);
}

