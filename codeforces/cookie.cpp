#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 2000005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

vector<ii> con[MAX_N];

bool vis[MAX_N];

long long time_c[MAX_N], cookie[MAX_N], DP[MAX_N], big[MAX_N];
long long N, T, ans;

class SegTree {
    private:
        long long tree[(1 << 24)];

    public:
        SegTree(long long N) {
        }

        long long get_val(long long l, long long r, long long a, long long b, long long ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (0); }

            long long leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            long long rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (leftS + rightS);
        }

        long long query(long long a, long long b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(long long l, long long r, long long newVal, long long ind, long long tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {   
                tree[ind] += newVal;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
        }

        void update(long long ind, long long val)
        { change_val(0, MAX_N, val, 1, ind); }
};

SegTree num (MAX_N);
SegTree cost (MAX_N);

void DFS (long long ind, long long sum) {
    vis[ind] = true;
    
    num.update(time_c[ind], cookie[ind]);
    cost.update(time_c[ind], cookie[ind] * time_c[ind]);
    
    long long low = 0;
    long long hi = MAX_N;
    
    while (low + 1 < hi) {
        long long mid = (low + hi) / 2;
        
        if (cost.query(0, mid) < (T - 2 * sum))
            low = mid;
        else
            hi = mid;
    }
    
    DP[ind] = num.query(0, hi) - max(0ll, ((cost.query(0, hi) - (T - 2 * sum)) + hi - 1) / hi);

    for (long long i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i].f]) {
            DFS(con[ind][i].f, sum + con[ind][i].s);
        }
    }
    
    num.update(time_c[ind], -1 * cookie[ind]);
    cost.update(time_c[ind], -1 * cookie[ind] * time_c[ind]);
    
    vis[ind] = false;
}

bool cmp(long long a, long long b) {
    return (big[a] > big[b]);
}

void DFS2(long long ind) {
    vis[ind] = true;
    vector<long long> pos;
    
    for (long long i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i].f]) {
            pos.push_back(con[ind][i].f);
            DFS2 (con[ind][i].f);
        }
    }
    
    big[ind] = DP[ind];    
    sort(pos.begin(), pos.end(), cmp);

    if (pos.size() >= 2) {
        big[ind] = max(big[ind], big[pos[1]]);
        vis[ind] = false;
    }
}

int main() {
    cin >> N >> T;
    
    for (long long i = 0; i < N; i ++)
        cin >> cookie[i];
    
    for (long long i = 0; i < N; i ++)
        cin >> time_c[i];
    
    long long a, b;
    for (long long i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(ii(i + 1, b));
    }

    DFS(0, 0);
    DFS2(0);
    ans = big[0];

    for (int i = 0; i < con[0].size(); i ++)
        ans = max(ans, big[con[0][i].f]);

    cout << ans << endl;
    return (0);
}