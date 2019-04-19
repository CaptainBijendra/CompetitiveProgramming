#include <iostream>
#include <fstream>

#define MAX_N 100005

int A[MAX_N];
int N, ans;

using namespace std;

int min(int a, int b) { return (a < b ? a : b); }

void partition (int st, int end) {
    if (st >= end) { return; }
    
    int i, j, k, MIN = 100005;

    for (i = st; i <= end; i ++) { MIN = min(MIN, A[i]); }    
    for (j = st; j < i; j ++) { A[j] -= MIN; }
    
    while (A[k] != 0) { k ++; }
    
    for (i = 0; i < N; i ++) { cout << A[i] << " "; }
    
    cout << endl;
    cout << i << " " << k << endl;
    
    ans ++;
    
    partition(st, k - 1);
    partition(k + 1, end);
}

int main() {
    ifstream fin ("poker.in");
    ofstream fout ("poker.out");
    
    fin >> N;
    
    for (int i = 0; i < N; i ++) { fin >> A[i]; }
    
    partition (0, N - 1);
}