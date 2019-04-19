#include <iostream>
#include <algorithm>
#include <string.h>

#define MOD 1000000007

using namespace std;

struct matrix {
    long long ar[2][2];
};

matrix st, c, tmp;

long long N;

matrix mult(matrix a, matrix b) {
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 2; j ++)
            c.ar[i][j] = 0ll;

    for (int i = 0; i < 2; i ++) 
        for (int j = 0; j < 2; j ++) 
            for (int k = 0; k < 2; k ++) 
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

int main() {
    cin >> N;

    st.ar[0][0] = 4; st.ar[0][1] = 2;
    st.ar[1][0] = 1; st.ar[1][1] = 1;

    matrix a = fast_exp(N, st);
    
    cout << (a.ar[1][0] % MOD) << endl;
    return (0);
}