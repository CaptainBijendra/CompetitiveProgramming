#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define MOD 1000000007
#define MAX_N 100005
#define f first
#define s second

using namespace std;

struct matrix {
    long long ar[101][101];
};

matrix st, c, tmp;

matrix mult(matrix a, matrix b) {
    for (int i = 0; i < 101; i ++)
        for (int j = 0; j < 101; j ++)
            c.ar[i][j] = 0ll;

    for (int i = 0; i < 101; i ++) 
        for (int j = 0; j < 101; j ++) 
            for (int k = 0; k < 101; k ++) 
                c.ar[i][j] = (c.ar[i][j] + ((a.ar[i][k] * b.ar[k][j]) % MOD)) % MOD;
    
    return (c);
}

matrix fast_exp (long long ind, matrix a) {
    if (ind == 1) { return (a); }
    if (ind % 2) {
        return (mult(a, fast_exp(ind - 1, a)));
    }
    
    else {
        tmp = fast_exp(ind / 2, a);
        return (mult(tmp, tmp));
    }
}

long long N, M;

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i ++)
        st.ar[0][i] = 0;

    st.ar[0][0] = 1;
    st.ar[0][M - 1] = 1;
    
    for (int i = 0; i < M - 1; i ++)
        st.ar[i + 1][i] = 1;
    
    matrix a = fast_exp(N, st);
    
    cout << a.ar[0][0] << endl;
    return (0);    
}
