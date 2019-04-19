#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>

#define INF 2000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

long long ar[MAX_N], DP[MAX_N], pre[MAX_N];
long long N, K;

class SegTree {
    private:
        long long tree[(1 << 18)];
        ii range[(1 << 18)];

    public:
        SegTree(long long N) {
            build_tree(0, N - 1, 1);
        }

        void build_tree(long long l, long long r, long long ind) {
            if (l == r) {
                range[ind].first = l; range[ind].second = r;
                return;
            }

            build_tree(l, (r + l) / 2, 2 * ind);
            build_tree((r + l) / 2 + 1, r, 2 * ind + 1);

            range[ind].first = l; range[ind].second = r;
            return;
        }

        long long get_val(long long l, long long r, long long ind) {
            if (l <= range[ind].first && range[ind].second <= r) { return (tree[ind]); }
            if (l > range[ind].second || r < range[ind].first) { return (0); }

            long long leftS = get_val(l, r, 2 * ind);
            long long rightS = get_val(l, r, 2 * ind + 1);

            return (max(leftS, rightS));
        }

        long long query(long long a, long long b)
        { return (get_val(a, b, 1)); }

        void change_val(long long l, long long r, long long newVal, long long ind, long long tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) { tree[ind] += newVal; return; }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);
            
            tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(long long ind, long long val)
        { change_val(0, N - 1, val, 1, ind); }
};


long long sum(long long i, long long j) {
    return (pre[j] - pre[i] + ar[i]);
}

int main() {
    cin >> N >> K;

    for (long long i = 0; i < N; i ++) 
        cin >> ar[i];
    
    SegTree ans(N);

    pre[0] = ar[0];
    for (long long i = 1; i < N; i ++) 
        pre[i] = pre[i - 1] + ar[i];
    
    for (long long i = 0; i < K; i ++) {
        DP[i] = pre[i];
        ans.update(i, DP[i] + sum(i + 2, N - 1));
    }
    
    long long fin_ans = 0;
    
    for (long long i = K; i < N; i ++) {
        DP[i] = max(sum(i - K + 1, i) + (i - K - 1 < 0 ? 0 : DP[i - K - 1]), ans.query(i - K - 1, i) - (i + 1 > N - 1 ? INF : sum(i + 1, N - 1)));
        ans.update(i, DP[i] + (i + 2 > N - 1 ? -INF : sum(i + 2, N - 1)));
        
        fin_ans = max(fin_ans, DP[i]);
    }
    
    for (long long i = 0; i < N - 2; i ++) {
        fin_ans = max(fin_ans, DP[i] + sum(i + 2, min(N - 1, i + K + 1)));
    }
    
    cout << fin_ans << endl;
    return (0);
}