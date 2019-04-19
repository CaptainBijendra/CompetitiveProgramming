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

int cnt[MAX_N], DP1[MAX_N], DP2[MAX_N];
int N, M;

class SegTree {
    private:
        int tree[(1 << 20)];

    public:
        SegTree(int N) {
            
        }

        int get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (0); }

            int leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            int rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (leftS + rightS);
        }

        int query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

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
        { change_val(0, MAX_N, val, 1, ind); }
};

class SegMax {
    private:
        int tree[(1 << 20)];

    public:
        SegMax(int N) {

        }

        int get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (0); }

            int leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            int rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (max(leftS, rightS));
        }

        int query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind] = newVal;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int ind, int val)
        { change_val(0, MAX_N, val, 1, ind); }
};

int main() {
    cin >> N >> M;
    
    SegTree seg(MAX_N);
    
    int a, b;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
        seg.update(a - 1, 1);
        seg.update(b, -1);
    }
    
    int big = 0;
    
    for (int i = 0; i < M; i ++) {
        cnt[i] = seg.query(0, i);
        big = max(big, cnt[i]);
    }
    
    SegMax forward(MAX_N);
    SegMax backward(MAX_N);
    
    DP1[0] = 1;
    forward.update(cnt[0], 1);
    for (int i = 1; i < M; i ++) {
        DP1[i] = forward.query(0, cnt[i]) + 1;
        forward.update(cnt[i], DP1[i]);
    }
    
    DP2[M - 1] = 1;
    backward.update(cnt[M - 1], 1);
    for (int i = M - 2; i >= 0; i --) {
        DP2[i] = backward.query(0, cnt[i]) + 1;
        backward.update(cnt[i], DP2[i]);
    }
    
    int big_lft = -1;
    int ans = 0;
    
    for (int i = 0; i < M; i ++) {
        if (big_lft < DP1[i]) {
            ans = max(ans, DP1[i] + DP2[i] - 1);
            big_lft = DP1[i];
        }
        
        else {
            ans = max(ans, big_lft + DP2[i]);
        }
    }
        
    cout << ans << endl;
    return (0);
}