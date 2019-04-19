#include <iostream>
#include <algorithm>

#define MAX_N 200005
#define MOD 998244353

using namespace std;

long long fact[MAX_N];
long long A, B;

int N, M;

int main() {
    cin >> N >> M;
    
    fact[0] = 1;

    for (int i = 1; i < MAX_N; i ++)
        fact[i] = (fact[i - 1] * 2) % MOD;
    
    string str_a, str_b;
    
    cin >> str_a;
    cin >> str_b;
    
    for (int i = 0; i < N; i ++) {
        if (str_a[i] == '1') { 
            ans_a += fact[i];
            ans_a %= MOD;
        }
    }
    
    return (0);
}