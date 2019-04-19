#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define MOD 1000000007
#define MAX_N 100005
#define f first
#define s second

using namespace std;

long long ar[MAX_N];
long long N, M, K;

int main() {
    cin >> N >> M >> K;
    
    long long ind = 0;
    
    for (long long i = 0; i < N; i ++) {
        cin >> ar[i];
        
        if (ar[i] > ar[ind])
            ind = i;
    }
    
    long long ind2;
    
    if (ind == 0)
        ind2 = 1;
    else
        ind2 = 0;
    
    for (long long i = 0; i < N; i ++) {
        if (i == ind)
            continue;
        
        if (ar[i] > ar[ind2])
            ind2 = i;
    }
    
    long long num1 = M / (K + 1);
    long long num2 = M % (K + 1);

    cout << ((ar[ind] * K + ar[ind2]) * num1 + ar[ind] * num2) << endl;
    return (0);    
}
