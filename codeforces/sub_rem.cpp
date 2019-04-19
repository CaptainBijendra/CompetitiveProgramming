#include <iostream>

#define MOD 998244353 

using namespace std;

string str;
long long N;

int main() {
    cin >> N;
    cin >> str;
    
    long long back = 1;
    long long front = 1;
    
    long long ans = 0;

    //Case 3
    for (long long i = N - 2; i >= 0; i --) {
        if (str[i] != str[i + 1])
            break;
        
        back ++;
    }

    //Case 2
    for (long long i = 1; i < N; i ++) {
        if (str[i] != str[i - 1])  
            break;
        
        front ++;
    }
    
    ans += (back);
    ans += (front);
    
    ans %= MOD;
    
    //Case 4
    long long lft_c = 0;
    
    for (long long i = 0; i < N; i ++) {
        if (str[i] != str[N - 1])
            break;
        
        lft_c ++;
    }
    
    if (lft_c == N) {
        cout << (((lft_c * (lft_c - 1)) / 2) + N % MOD) << endl;
        return (0);
    }
    
    ans += ((lft_c * back) % MOD);
    ans %= MOD;
    
    //Case 1
    ans ++;

    cout << (ans % MOD) << endl;
    return (0);
}