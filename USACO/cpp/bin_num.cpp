#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <map>

#define MOD 998244353
#define MAX_N 200005
#define f first
#define s second

using namespace std;

string A, B;

long long preA[MAX_N], preB[MAX_N];

int N, M;

int main() {
    cin >> N >> M;
    cin >> A >> B;
    
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    
    long long mult;
    
    preA[0] = (A[0] == '1');
    mult = 2;
    
    for (int i = 1; i < N; i ++) {
        preA[i] = preA[i - 1] + (A[i] == '1' ? mult : 0);
        preA[i] %= MOD;
        
        mult *= 2;    
        mult %= MOD;
    }
    
    preB[0] = (B[0] == '1');
    mult = 2;
    
    for (int i = 1; i < M; i ++) {
        preB[i] = preB[i - 1] + (B[i] == '1' ? mult : 0);
        preB[i] %= MOD;
        
        mult *= 2;
        mult %= MOD;
    }
    
    long long ans = 0;
    
    for (int i = 0; i < M; i ++) {
        if (B[i] == '1') {
            ans += preA[min(N - 1, i)];
            ans %= MOD;
        }
    }
    
    cout << ans << endl;
    return (0);
}