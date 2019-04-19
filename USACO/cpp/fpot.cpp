#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

#define INF 2000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

ii points[MAX_N];

int N, D;

class SegTree {
    private:
        ii tree[(1 << 18)];

    public:
        SegTree(int N) {
            for (int i = 0; i < (1 << 18); i ++) {
                tree[i].f = INF;
                tree[i].s = -INF;
            }
        }

        ii get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (ii(INF, -INF)); }

            ii leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            ii rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (ii(min(leftS.f, rightS.f), max(leftS.s, rightS.s)));
        }

        ii query(int a, int b)
        { return (get_val(0, N - 1, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind].f = min(tree[ind].f, newVal);
                tree[ind].s = max(tree[ind].s, newVal);;

                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = ii(min(tree[2 * ind].f, tree[2 * ind + 1].f), max(tree[2 * ind].s, tree[2 * ind + 1].s));
        }

        void update(int ind, int val)
        { change_val(0, N - 1, val, 1, ind); }
};

int main() {
    cin >> N >> D;

    SegTree ans(N);

    for (int i = 0; i < N; i ++) 
        cin >> points[i].f >> points[i].s;

    sort(points, points + N);
    
    for (int i = 0; i < N; i ++) 
        ans.update(i, points[i].s);

    int final_ans = INF;

    for (int i = 0; i < N; i ++) {
        int low = i;
        int hi = N - 1;

        while (low < hi) {
            int mid = (low + hi) / 2;

            if (ans.query(i, mid).s - ans.query(i, mid).f >= D)
                hi = mid;
            else
                low = mid + 1;
        }
        
        if (low != N - 1)
            final_ans = min(final_ans, points[low].f - points[i].f);
    }

    cout << (final_ans == INF ? -1 : final_ans) << endl;
    return (0);
}