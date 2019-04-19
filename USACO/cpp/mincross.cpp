#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>

#define MAX_N 1000005

using namespace std;

long long BIT[3 * MAX_N], ar[MAX_N], A[MAX_N], B[MAX_N], loc[MAX_N];
long long N, X;

void update(long long ind, long long val) {
    ind += MAX_N;
    
    while (ind <= 3 * MAX_N) {
        BIT[ind] += val;
        ind += (ind & -ind);
    }
}

long long query(long long ind) {
    long long sum = 0;

    ind += MAX_N;
        
    while (ind > 0) {
        sum += BIT[ind];
        ind -= (ind & -ind);
    }

    return (sum);
}

long long sum() {
    memset(BIT, 0, sizeof(BIT));
    
    long long ans = 0;
    
    for (long long i = 0; i < N; i ++) {
        ans += query(-ar[i]);
        update(-ar[i], 1);
    }
    
    return (ans);
}

int main() {
    ifstream fin ("mincross.in");
    ofstream fout ("mincross.out");

    fin >> N;
    
    for (long long i = 0; i < N; i ++)  {
        fin >> A[i];
        loc[A[i]] = i;
    }
    
    for (long long i = 0; i < N; i ++)
        fin >> B[i];
    
    for (long long i = 0; i < N; i ++) 
        ar[i] = loc[B[i]];
    
    long long ans = sum();
    long long fin_ans = MAX_N * 10000ll;

    for (long long i = 0; i < N; i ++) {
        ans += -1 * (ar[i]) + (N - ar[i] - 1);
        fin_ans = min(fin_ans, ans);
    }
    
    for (int i = 0; i < N; i ++)
        loc[B[i]] = i;
    
    for (long long i = 0; i < N; i ++) 
        ar[i] = loc[A[i]];
    
    ans = sum();
    for (long long i = 0; i < N; i ++) {
        ans += -1 * (ar[i]) + (N - ar[i] - 1);
        fin_ans = min(fin_ans, ans);
    }
    
    fout << fin_ans << endl;
    return (0);
}
