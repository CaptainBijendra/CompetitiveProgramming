#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 2000005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

vector<ii> ar;

ii cow[MAX_N];

long long used[MAX_N];
long long N, A, B;

int main() {
    cin >> N >> A >> B;
    
    long long sum = 0;

    for (long long i = 0; i < N; i ++) {
        cin >> cow[i].f >> cow[i].s;
        
        if (cow[i].f - cow[i].s > 0)
            ar.push_back(ii(cow[i].f - cow[i].s, i));
    
        sum += cow[i].s;
    }
    
    sort(ar.begin(), ar.end());
    reverse(ar.begin(), ar.end());
    
    for (long long i = 0; i < min(B, (long long)ar.size()); i ++) {
        used[ar[i].s] = true;
        sum += ar[i].f;
    }
    
    if (B == 0) {
        long long ans = 0ll;
        
        for (long long i = 0; i < N; i ++)
            ans += cow[i].s;
    
        cout << ans << endl;
        return (0);
    }
    
    long long final = sum;
    
    for (long long i = 0; i < N; i ++) {
        if (!used[i])
            continue;
        
        long long extra = 1ll;
        for (long long j = 0; j < A; j ++)
            extra *= 2;
        
        extra *= cow[i].f;
        final = max(final, sum - cow[i].f + extra);
    }
    
    if (ar.size() >= B)
        sum -= ar[B - 1].f;
    
    for (long long i = 0; i < N; i ++) {
        if (used[i])
            continue;
        
        long long extra = 1ll;
        for (long long j = 0; j < A; j ++)
            extra *= 2;
        
        final = max(final, (long long)(cow[i].f * extra) + sum - cow[i].s);
    }
    
    cout << final << endl;
    return (0);
}