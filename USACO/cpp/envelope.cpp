#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

#define INF 200000000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

long long DP[MAX_N][205];
long long N, M, K;

class SegTree {
    private:
        ii lazy[4 * (MAX_N)];
        ii tree[4 * MAX_N];

    public:
        SegTree(long long N) {

        }
        
        ii comb(ii a, ii b) {
            if (a.f > b.f)
                return (a);
            if (a.f == b.f)
                return (a.s > b.s ? a : b);
            
            return (b);
        }

        ii get_val(long long l, long long r, long long l1, long long r1, long long ind) {
            if (l1 > r || r1 < l) { return (ii(0, 0)); }
            if (l <= l1 && r1 <= r) { return (tree[ind]); }

            if (!(lazy[ind].f == 0 && lazy[ind].s == 0)) {
                lazy[2 * ind] = comb(lazy[2 * ind], lazy[ind]);
                tree[2 * ind] = comb(tree[2 * ind], lazy[ind]);

                lazy[2 * ind + 1] = comb(lazy[2 * ind + 1], lazy[ind]);
                tree[2 * ind + 1] = comb(tree[2 * ind + 1], lazy[ind]);

                lazy[ind] = ii(0, 0);
            }

            ii leftS = get_val(l, r, l1, (r1 + l1) / 2, (2 * ind));
            ii rightS = get_val(l, r, (r1 + l1) / 2 + 1, r1, 2 * ind + 1);

            return (comb(leftS, rightS));
        }

        ii query(long long a, long long b)
        { return (get_val(a, b, 0, MAX_N, 1)); }

        void change_val(long long l, long long r, ii newVal, long long ind, long long a, long long b) {
            if (l > b || r < a) { return; }
            if (a <= l && r <= b) {
                lazy[ind] = comb(lazy[ind], newVal);
                tree[ind] = comb(tree[ind], newVal);
                
                return;
            }

           if (!(lazy[ind].f == 0 && lazy[ind].s == 0)) {
                lazy[2 * ind] = comb(lazy[2 * ind], lazy[ind]);
                tree[2 * ind] = comb(tree[2 * ind], lazy[ind]);

                lazy[2 * ind + 1] = comb(lazy[2 * ind + 1], lazy[ind]);
                tree[2 * ind + 1] = comb(tree[2 * ind + 1], lazy[ind]);

                lazy[ind] = ii(0, 0);
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, a, b);
            
            tree[ind] = comb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(long long a, long long b, long long val1, long long val2)
        { change_val(0, MAX_N, ii(val1, val2), 1, a, b); }
}; 

int main() {
    cin >> N >> M >> K;
    
    SegTree seg(MAX_N);
    
    long long s, t, d, w;
    for (long long i = 0; i < K; i ++) {
        cin >> s >> t >> d >> w;
        seg.update(s, t, w, d);
    }
    
    for (long long i = 0; i < MAX_N; i ++)    
        for (long long j = 0; j < 205; j ++)
            DP[i][j] = INF;
    
    long long lft = 0;
    long long rght = 0;
    
    DP[1][0] = 0;
    
    for (long long i = 1; i <= N; i ++) {
        ii cur = seg.query(i, i);
        
        if (cur.f == 0 && cur.s == 0) {
            for (long long j = 0; j <= M; j ++)
                DP[i + 1][j] = min(DP[i + 1][j], DP[i][j]);
            
            continue;
        }
        
        for (long long j = 0; j <= M; j ++) {
            DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j]);
            DP[cur.s + 1][j] = min(DP[cur.s + 1][j], DP[i][j] + cur.f);
        }
    }
    
    long long ans = INF;
    
    for (int i = 0; i <= M; i ++)
        ans = min(ans, DP[N + 1][i]);
    
    cout << ans << endl;
    return (0);
}