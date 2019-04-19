#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define eps 0.000000000001
#define f first
#define s second

using namespace std;

long long ar[MAX_N];
long long N, K;

long long sim(long double ben) {
    long long tot = 0;
    for (int i = 0; i < N; i ++) {
        tot += (long long)(((-1.0 + sqrt(1 + ar[i] / ben)) / 2.0) + 1);
    }
    
    return (tot);
}

int main() {
    ifstream fin ("tallbarn.in");
    ofstream fout ("tallbarn.out");
    
    fin >> N >> K;
    
    for (int i = 0; i < N; i ++)
        fin >> ar[i];
    
    long double low = 0.0;
    long double hi = 1000000000000000.0;
    
    while (hi - low > eps) {
        long double mid = (low + hi) / 2.0;
        
        if (sim(mid) >= K)
            low = mid;
        else
            hi = mid;
    }
    
    long double ans = 0;
    long double cow_req;
    
    for (int i = 0; i < N; i ++) {
        cow_req = (long long)(((-1.0 + sqrt(1 + ar[i] / low)) / 2.0) + 1);
        ans += (ar[i] * 1.0 / cow_req * 1.0);
    }
    
    ans += 0.5;
    
    fout << (long long)(ans) << endl;
    return (0);
}