#include <iostream>
#include <algorithm>

#define MAX_N 100005
#define INF 2000000009
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int N, Q;

class SegTree {
    private:
        int tree[(1 << 18)];
        int lazy[(1 << 18)];
        
        ii range[(1 << 18)];

    public:
        SegTree(int N) {
            build_tree(0, N - 1, 1);
        }

        void build_tree(int l, int r, int ind) {
            if (l == r) {
                range[ind].first = l; range[ind].second = r;
                tree[ind] = 0;
                return;
            }

            build_tree(l, (r + l) / 2, 2 * ind);
            build_tree((r + l) / 2 + 1, r, 2 * ind + 1);

            range[ind].first = l; range[ind].second = r;
            return;
        }

        int get_val(int l, int r, int ind) {
            if (l > range[ind].second || r < range[ind].first) { return (0); }

            if (lazy[ind] % 2 == 1) {
                tree[ind] = (range[ind].s - range[ind].f + 1 - tree[ind]);

                if (l != r) { 
                    lazy[2 * ind] += lazy[ind];
                    lazy[2 * ind + 1] += lazy[ind];
                }
                
                lazy[ind] = 0;
            }
            
            if (l <= range[ind].first && range[ind].second <= r) { return (tree[ind]); }

            int leftS = get_val(l, r, 2 * ind);
            int rightS = get_val(l, r, 2 * ind + 1);
            
            return (leftS + rightS);
        }

        int query(int a, int b)
        { return (get_val(a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int a, int b) {
            if (l > r)
                return;
                
            if (lazy[ind] % 2 == 1) {
                tree[ind] = (range[ind].s - range[ind].f + 1 - tree[ind]);

                if (l != r) { 
                    lazy[2 * ind] += lazy[ind];
                    lazy[2 * ind + 1] += lazy[ind];
                }
                
                lazy[ind] = 0;
            }    
            
            if (b < l || a > r) { return; }
    
            if (a <= l && r <= b) {
                lazy[2 * ind] += newVal;
                lazy[2 * ind + 1] += newVal;
                
                tree[ind] = (r - l + 1 - tree[ind]);
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, a, b);
        
            tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
        }

        void update(int a, int b, int val)
        { change_val(0, N - 1, val, 1, a, b); }
};

int main() {
    cin >> N >> Q;

    SegTree ans(MAX_N);

    int a, b, c;
    for (int i = 0; i < Q; i ++) {
        cin >> a >> b >> c;
        b --; c --;
        
        if (a == 0)
            ans.update(b, c, 1);
        else
            cout << ans.query(b, c) << endl;
    }

    return (0);
}