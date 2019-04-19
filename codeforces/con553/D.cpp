#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;
typedef pair<ii, long long> pii;

ii ar[MAX_N];
long long N, M;

bool cmp(ii a, ii b) {
    return ((-a.s + a.f - b.f + b.s) > 0);
}

int main() {
    cin >> N;
    
    for (long long i = 0; i < N; i ++)
        cin >> ar[i].f >> ar[i].s;
        
    sort(ar, ar + N, cmp);
    
    long long ans = 0ll;
    
    for (long long i = 0; i < N; i ++) {
        ans += ((long long)ar[i].f * i + (long long)ar[i].s * (N - i - 1));
    }
    
    cout << ans << endl;
    return (0);
}

