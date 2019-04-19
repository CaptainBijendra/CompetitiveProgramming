#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_N 100005
#define MOD 976543312183
#define BASE 57
#define f first
#define s second

using namespace std;

long long ar[MAX_N], tar[MAX_N], h[MAX_N], tar_h[MAX_N], pow_f[MAX_N];
long long N, M;

long long H(long long a) {
    return (a);
}

long long sub_h(long long i, long long j) {
    return ((((h[j] - (i == 0 ? 0 : h[i - 1]) * pow_f[j - i + 1]) + MOD) % MOD + MOD) % MOD);
}

long long sub_tar(long long i, long long j) {
    return ((((tar_h[j] - (i == 0 ? 0 : tar_h[i - 1]) * pow_f[j - i + 1]) + MOD) % MOD + MOD) % MOD);
}

void build_h() {
    h[0] = H(ar[0]);
    tar_h[0] = H(tar[0]);
    pow_f[0] = 1;

    for (long long i = 1; i < N; i ++) {
        h[i] = ((h[i - 1] * BASE + H(ar[i])) % MOD);
        pow_f[i] = ((pow_f[i - 1] * BASE) % MOD);
    }
    
    for (long long i = 1; i < M; i ++)
        tar_h[i] = ((tar_h[i - 1] * BASE + H(tar[i])) % MOD);
}

bool pos(long long len, long long ind) {
    for (long long i = 0; i < N; i ++) {
        if (sub_h(i, i + len) == sub_tar(ind, ind + len))
            return (true);
    } 

    return (false);
}

long long gen_len(long long ind) {
    long long low = 0;
    long long hi = M;

    while (low < hi) {
        long long mid = (low + hi) / 2;

        if (pos(mid, ind))
            low = mid + 1;
        else
            hi = mid;
    }
    
    return (low + 1);
}

int main() {
    cin >> N >> M;
    
    string str;
    long long ln = 0;

    while (cin >> str) {
        for (long long i = 0; i < str.size(); i ++)
            ar[i + ln] = (long long)(str[i] - 'A');
    
        ln += str.size();
    
        if (ln == N)
            break;
    }
    
    ln = 0;
    
    while (cin >> str) {
        for (long long i = 0; i < str.size(); i ++)
            tar[i + ln] = (long long)(str[i] - 'A');
        
        ln += str.size();
        
        if (ln == M)
            break;
    }

    build_h();
    
    long long cnt = 0;

    for (long long i = 0; i < M; ) {
        cnt ++;
        i += gen_len(i);
    }

    cout << (cnt) << endl;
    return (0);
}

