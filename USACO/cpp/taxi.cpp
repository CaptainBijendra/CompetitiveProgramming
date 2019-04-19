#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int A[MAX_N], B[MAX_N];
int N, M;

int main() {
    ifstream fin ("taxi.in");
    ofstream fout ("taxi.out");
    
    fin >> N >> M;
    
    long long ans = 0ll;
    
    for (int i = 0; i < N; i ++) {
        fin >> A[i] >> B[i];
        ans += abs(A[i] - B[i]);
    }
    
    A[N] = M;
    B[N] = 0;
    
    N ++;
    
    sort(A, A + N);
    sort(B, B + N);
    
    for (int i = 0; i < N; i ++) {
        ans += abs(A[i] - B[i]);
    }
    
    fout << ans << endl;
    return (0);
}