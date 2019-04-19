#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <math.h>
#include <time.h>

#define MOD 99999999977 
#define MAX_N 1000005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;
ii ar[MAX_N];

vector<ii> in;
vector<ii> out;

bool vis[MAX_N];

long long DP[MAX_N];
long long N, Q;

bool cmp(ii a, ii b) {
    return (a.s < b.s);
}

void add(long long num) {
    for (long long i = N; i >= 1; i --) {
        DP[i + num] += DP[i];
        
        if (DP[i + num] >= MOD)
            DP[i + num] -= MOD;
    }

    DP[num] ++;
}

void rem(long long num) {
    DP[num] = max(0ll, DP[num] - 1);

    for (long long i = 1; i <= N - num; i ++) {
        DP[i + num] -= DP[i];
        DP[i + num] = (DP[i + num] + MOD) % MOD;
    }
}

int main() {
    cin >> N >> Q;
    
    long long c;
    for (long long i = 0; i < Q; i ++) {
        cin >> ar[i].f >> ar[i].s >> c;
        in.push_back(ii(ar[i].f, c));
        out.push_back(ii(ar[i].s, c));
    }
    
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());

    long long lft = 0;
    long long lft2 = 0;
    
    for (long long i = 1; i <= N; i ++) {
        while (lft < in.size() && in[lft].f == i) {
            add(in[lft].s);
            lft ++;
        }
        
        for (int j = 1; j <= N; j ++)
            if (DP[j] > 0) 
                vis[j] = true;
    
        while (lft2 < out.size() && out[lft2].f == i) {
            rem(out[lft2].s);
            lft2 ++;
        }
    }
    
    long long tot = 0;
    
    for (long long i = 1; i <= N; i ++)
        if (vis[i])
            tot ++;
    
    cout << tot << endl;
    
    for (long long i = 1; i <= N; i ++)
        if (vis[i])
            cout << i << " ";
            
    cout << endl;
    return (0);
}