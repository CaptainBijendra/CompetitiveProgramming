#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define MAX_N 300005
#define f first
#define s second

using namespace std;

long long ar[MAX_N], powr[MAX_N], pre[MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
    
        if (i == 0)
            pre[i] = ar[i];
        else
            pre[i] = pre[i - 1] + ar[i];
    }

    sort(ar, ar + N);
    
    powr[0] = 1ll;
    
    for (int i = 1; i < MAX_N; i ++)
        powr[i] = (powr[i - 1] * 2) % MOD;
    
    long long ans = 0ll, cur_prefix = ar[0];

    for (int i = 1; i < N; i ++) {
        ans += ((ar[i] * (powr[i] - 1) - cur_prefix + MOD) % MOD);
        ans %= MOD;
    
        cur_prefix *= 2; cur_prefix += ar[i];
        cur_prefix %= MOD;
    }
    
    cout << ans << endl;
    return (0);
}