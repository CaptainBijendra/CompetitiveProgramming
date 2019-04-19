#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <math.h>

#define INF 2000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<int> ans;

int ar[MAX_N];
int N, K;

class SegTree {
    private:
        ii tree[(1 << 18)];

    public:
        SegTree(int N) {
            for (int i = 0; i < (1 << 18); i ++) {
                tree[i].f = -INF;
                tree[i].s = INF;
            }
        }

        ii comb(ii a, ii b) {
            if (a.f == b.f)
                return (ii(a.f, min(a.s, b.s)));
            if (a.f < b.f)
                return (ii(b.f, b.s));
            else
                return (ii(a.f, a.s));
        }

        ii get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (ii(-INF, INF)); }

            ii leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            ii rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (comb(leftS, rightS));
        }

        ii query(int a, int b)
        { return (get_val(0, (1 << 17) - 1, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind].f = newVal;
                tree[ind].s = tmp;

                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = comb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int ind, int val)
        { change_val(0, (1 << 17) - 1, val, 1, ind); }
};


class SegSum {
    private:
        int tree[(1 << 18)];

    public:
        SegSum(int N) {

        }

        int get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (0); }

            int leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            int rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (leftS + rightS);
        }

        int query(int a, int b)
        { return (get_val(0, (1 << 17) - 1, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind] += newVal;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
        }

        void update(int ind, int val)
        { change_val(0, (1 << 17) - 1, val, 1, ind); }
};

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i ++)
        cin >> ar[i];

    SegTree prob(N);
    SegSum sum(N);

    for (int i = 0; i < N; i ++)
        prob.update(i, ar[i]);

    for (int i = 0; i < N; i ++) {
        ii cur = prob.query(0, min(N - 1, i + K));
        K -= (cur.s - sum.query(0, max(0, cur.s - 1)));

        if (K < 0) {
            K += (cur.s - sum.query(0, max(0, cur.s - 1)));

            for (int j = 0; j < N; j ++) {
                if (prob.query(j, j).f < 0)
                    continue;

                ans.push_back(ar[j]);
            }

            break;
        }

        if (K == 0) {
            prob.update(cur.s, -INF);
            sum.update(cur.s, 1);

            ans.push_back(cur.f);

            for (int j = 0; j < N; j ++) {
                if (prob.query(j, j).f < 0)
                    continue;

                ans.push_back(ar[j]);
            }

            break;
        }

        prob.update(cur.s, -INF);
        sum.update(cur.s, 1);

        ans.push_back(cur.f);
    }

    for (int i = 1; i < N; i ++) {
        int tmp = i;
        int max_el = -1, max_ind = -1;

        for (int j = i; j <= i + K; j ++) {
            if (max_el < ans[j]) {
                max_el = ans[j];
                max_ind = j;
            }
        }

        for (int j = max_ind; j > 0; j --) {
            if (K == 0)
                break;

            if (ans[j] > ans[j - 1]) {
                int tmp = ans[j];

                ans[j] = ans[j - 1];
                ans[j - 1] = tmp;

                K --;
            }

            else
                break;
        }

        if (K == 0)
            break;
    }

    for (int i = 0; i < ans.size(); i ++)
        cout << ans[i] << " ";

    cout << endl;
    return (0);
}
