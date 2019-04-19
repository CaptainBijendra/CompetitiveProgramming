#include <iostream>
#include <algorithm>

#define MAX_N 100005
#define INF 2000000009
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int N;

class SegTree {
    private:
        int tree[(1 << 18)];
        int lazy[(1 << 18)];
        int sum[(1 << 18)];
        
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

            if (lazy[ind] != 0) {
                tree[ind] = lazy[ind];

                if (l != r) { 
                    lazy[2 * ind] = lazy[ind];
                    lazy[2 * ind + 1] = lazy[ind];
                }
                
                lazy[ind] = 0;
            }
            
            if (l <= range[ind].first && range[ind].second <= r) { return (tree[ind]); }

            int leftS = get_val(l, r, 2 * ind);
            int rightS = get_val(l, r, 2 * ind + 1);
            
            return (max(leftS, rightS));
        }

        int query(int a, int b)
        { return (get_val(a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int a, int b) {
            if (l > r)
                return;
                
            if (lazy[ind] != 0) {
                tree[ind] = lazy[ind];

                if (l != r) { 
                    lazy[2 * ind] = lazy[ind];
                    lazy[2 * ind + 1] = lazy[ind];
                }
                
                lazy[ind] = 0;
            }    
            
            if (b < l || a > r) { return; }
    
            if (a <= l && r <= b) {
                lazy[2 * ind] = newVal;
                lazy[2 * ind + 1] = newVal;
                
                tree[ind] = newVal;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, a, b);
        
            tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int a, int b, int val)
        { change_val(0, N - 1, val, 1, a, b); }
};

int main() {
    cin >> N;

    SegTree ans(N);
    
    while (true) { 
        char a;
        cin >> a;
        
        if (a == 'E')
            break;
        else {
            if (a == 'Q') { 
                int h;
                cin >> h;
                
                int low = 0;
                int hi = N - 1;     
                
                while (low < hi) {
                    int mid = (low + hi) / 2;
                    
                    if (ans.query(0, mid) <= h)
                        low = mid + 1;
                    else
                        hi = mid;
                }
                
                if (ans.query(low, low) <= h)
                    cout << low + 1 << endl; 
                else
                    cout << low << endl; 
            }
            
            else {
                int x, y, z;
                
                cin >> x >> y >> z;
                
                for (int i = x - 1; i <= y - 1; i ++) {
                    ans.update(i, y - 1, z);
                }
            }        
        }
    }

    cout << ans.query(0, N - 1) << endl;
    return (0);
}