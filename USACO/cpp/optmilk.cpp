#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

#define MAX_N 50005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

struct cow {
    int lr, nlr, nrl, n;
};

int M[MAX_N];
int N, D;

class SegTree {
    private:
        cow tree[(1 << 18)];
        ii range[(1 << 18)];
        cow default_c;
        
    public:
        SegTree(int N) {
            default_c.lr = 0; default_c.nrl = 0;
            default_c.nlr = 0; default_c.n = 0;
            build_tree(0, MAX_N, 1);
        }

        void build_tree(int l, int r, int ind) {
            if (l == r) {
                range[ind].first = l; range[ind].second = r;
                tree[ind] = default_c;
                return;
            }

            build_tree(l, (r + l) / 2, 2 * ind);
            build_tree((r + l) / 2 + 1, r, 2 * ind + 1);

            range[ind].first = l; range[ind].second = r;
            tree[ind] = default_c;
            return;
        }

        cow comb(cow a, cow b) {
            cow n_c;
            
            n_c.lr = max(a.nrl + b.nlr, max(a.lr + b.nlr, a.nrl + b.lr));
            n_c.n = max(a.n + b.n, max(a.nlr + b.n, a.n + b.nrl));
            n_c.nlr = max(a.n + b.nlr, max(a.nlr + b.nlr, a.n + b.lr));
            n_c.nrl = max(a.lr + b.n, max(a.nrl + b.nrl, a.lr + b.n));
            
            return (n_c); 
        }

        cow get_val(int l, int r, int ind) {
            if (l <= range[ind].first && range[ind].second <= r) { return (tree[ind]); }
            if (l > range[ind].second || r < range[ind].first) { return (default_c); }

            cow leftS = get_val(l, r, 2 * ind);
            cow rightS = get_val(l, r, 2 * ind + 1);
            
            return (comb(leftS, rightS));
        }

        cow query(int a, int b)
        { return (get_val(a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) { 
                tree[ind].lr = newVal;
                tree[ind].nlr = 0;
                tree[ind].nrl = 0;
                tree[ind].n = 0;
                
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);
            
            tree[ind] = comb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int ind, int val)
        { change_val(0, MAX_N, val, 1, ind); }
};

int main() {
    cin >> N >> D;
    
    SegTree ans (MAX_N);

    for (int i = 0; i < N; i ++) {
        cin >> M[i];
        ans.update(i, M[i]);
    }
    
    long long tot = 0;
    
    int a, b;
    for (int i = 0; i < D; i ++) {
        cin >> a >> b;
        ans.update(a - 1, b);
        
        cow x = ans.query(0, N - 1);
        tot += max(max(x.lr, x.n), max(x.nlr, x.nrl));
    }
    
    cout << tot << endl;
    return (0);
}