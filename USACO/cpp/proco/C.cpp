#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

long long a[MAX_N], b[MAX_N], pre1[MAX_N], pre2[MAX_N];
int N, M, X, Y, C;

int main() {
    cin >> M >> X;
    pre1[0] = 0;
    for(int i=0; i<M; i++) {
        cin >> a[i];
    }
    sort(a, a+M);
    reverse(a, a + M);
    for(int i=0; i<M; i++)
        pre1[i+1] = pre1[i] + a[i];
    
    cin >> N >> Y;
    pre2[0] = 0;
    for(int i=0; i<N; i++) {
        cin >> b[i];
    }
    sort(b, b+N);
    reverse(b, b + N);
    for(int i=0; i<N; i++)
        pre2[i+1] = pre2[i] + b[i];
    
    cin >> C;
    
    long long bestAns = 0;
    for(int i=0; i<=M && i*X<=C; i++) {
        long long remaining = ((C-i*X) / Y);
        long long cand = pre1[i] + pre2[max((long long) 0, min(remaining, (long long) N))];
        bestAns = max(cand, bestAns);
    }
    
    cout << bestAns << endl;
    return (0);    
}