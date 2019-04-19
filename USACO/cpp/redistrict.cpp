#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 30005

#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

string str;

int pre[MAX_N], DP[MAX_N];
int N, K;

class SegTree {
    private:
        ii tree[4 * MAX_N];
        ii range[4 * MAX_N];

    public:
        SegTree(long long N) {
            build_tree(0, MAX_N, 1);
        }

        void build_tree(long long l, long long r, long long ind) {
            if (l == r) {
                range[ind].first = l; range[ind].second = r;

                tree[ind].f = INF;
                tree[ind].s = INF;

                return;
            }

            build_tree(l, (r + l) / 2, 2 * ind);
            build_tree((r + l) / 2 + 1, r, 2 * ind + 1);

            range[ind].first = l; range[ind].second = r;
            tree[ind].f = INF;
            tree[ind].s = INF;
        }

        ii get_val(long long l, long long r, long long ind) {
            if (l <= range[ind].first && range[ind].second <= r) { return (tree[ind]); }
            if (l > range[ind].second || r < range[ind].first) { return (ii(INF, INF)); }

            ii leftS = get_val(l, r, 2 * ind);
            ii rightS = get_val(l, r, 2 * ind + 1);

            if (leftS.f < rightS.f)
                return (leftS);
            else if (leftS.f > rightS.f)
                return (rightS);
            else {
                if (leftS.s < rightS.s)
                    return (leftS);
                else
                    return (rightS);
            }

            return (rightS);
        }

        ii query(long long a, long long b)
        { return (get_val(a, b, 1)); }

        void change_val(long long l, long long r, long long newVal, long long newVal2, long long ind, long long tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) { tree[ind].f = newVal; tree[ind].s = newVal2; return; }

            change_val(l, (r + l) / 2, newVal, newVal2, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, newVal2, 2 * ind + 1, tmp);

            if (tree[2 * ind].f < tree[2 * ind + 1].f)
                tree[ind] = tree[2 * ind];
            else if (tree[2 * ind].f > tree[2 * ind + 1].f)
                tree[ind] = tree[2 * ind + 1];
            else {
                if (tree[2 * ind].s < tree[2 * ind + 1].s)
                    tree[ind] = tree[2 * ind];
                else
                    tree[ind] = tree[2 * ind + 1];
            }
        }

        void update(long long ind, long long val, long long val2)
        { change_val(0, MAX_N, val, val2, 1, ind); }
};

int main() {
    ifstream cin ("redistricting.in");
    ofstream cout ("redistricting.out");

    cin >> N >> K;
    cin >> str;

    SegTree ans(MAX_N);

    pre[0] = (str[0] == 'H' ? 1 : -1);
    DP[0] = (str[0] == 'G');
    ans.update(0, DP[0], pre[0]);

    for (int i = 1; i < N; i ++)
        pre[i] = pre[i - 1] + (str[i] == 'H' ? 1 : -1);

    for (int i = 1; i < N; i ++) {
        DP[i] = INF;
        
        if (i - K < 0)
            DP[i] = min(DP[i], (pre[i] <= 0));

        ii cur = ans.query(max(0, i - K), i);

        if (cur.s >= pre[i])
            DP[i] = min(DP[i], cur.f + 1);
        else
            DP[i] = min(DP[i], cur.f);

        ans.update(i, DP[i], pre[i]);
    }
    
    cout << DP[N - 1] << endl;
    return (0);
}

