#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 50005
#define f first
#define s second

using namespace std;

struct state {
    int pre, suf, sz;
    int left_s, right_s, st;
};

typedef pair<int, int> ii;

int N, M;

class SegTree {
    private:
        state tree[4 * MAX_N];
        state default_state;

        int lazy[4 * MAX_N];

    public:
        SegTree(int N) {
            default_state.pre = 0;
            default_state.suf = 0;
            default_state.sz = 0;
            default_state.left_s = 0;
            default_state.right_s = 0;

            for (int i = 1; i < 4 * 70005; i ++) {
                tree[i] = default_state;
                lazy[i] = 0;
            }

            build_tree(0, MAX_N, 1); 
        }

        void build_tree(int l, int r, int ind) {
            if (l == r) {
                tree[ind].left_s = l;
                tree[ind].right_s = r;
                
                return;
            }

            build_tree(l, (r + l) / 2, 2 * ind);
            build_tree((r + l) / 2 + 1, r, 2 * ind + 1);

            tree[ind].left_s = l; tree[ind].right_s = r;
            return;
        }
        
        void upd_lazy(int ind, int l, int r) {
            if
                lazy[2 * ind] = lazy[ind];
                lazy[2 * ind + 1] = lazy[ind];
            
            int conv = (lazy[ind] == 2 ? 1 : 0);

            tree[ind].sz = conv * (r - l + 1);
            tree[ind].pre = conv * (r - l + 1);
            tree[ind].suf = conv * (r - l + 1);
            lazy[ind] = 0;
        }
    
        state comb(state l, state r) {
            state ans;        

            if (l.pre == l.right_s - l.left_s + 1)
                ans.pre = l.pre + r.pre;
            else
                ans.pre = l.pre;

            if (r.suf == r.right_s - r.left_s + 1)
                ans.suf = l.suf + r.suf;
            else
                ans.suf = r.suf;
                
            ans.sz = max(max(max(ans.pre, ans.suf), max(l.sz, r.sz)), l.suf + r.pre);

            if (ans.pre + ans.suf >= ans.right_s - ans.left_s + 1) {
                ans.sz = ans.right_s - ans.left_s + 1; 
                ans.pre = ans.sz;
                ans.suf = ans.sz;
            }
    
            return (ans);
        }

        int find_val(int l, int r, int a, int ind) {
            if (l == r)
                return (tree[ind].left_s);

            if (tree[ind].sz >= a && tree[ind].sz == r - l + 1)
                return (tree[ind].left_s);

            if (lazy[ind] != 0) 
                upd_lazy(ind, l, r);

            if (tree[2 * ind].sz >= a)
                return (find_val(l, (l + r) / 2, a, 2 * ind));
            else if (tree[2 * ind].suf + tree[2 * ind + 1].pre >= a && tree[2 * ind].suf > 0) 
                return (tree[2 * ind].right_s - tree[2 * ind].suf + 1);    
            else if (tree[2 * ind + 1].pre >= a)
                return (tree[2 * ind + 1].left_s);
            else if (tree[2 * ind + 1].sz >= a)
                return (find_val((l + r) / 2 + 1, r, a, 2 * ind + 1));

            return (-1);
        }

        int find(int a) 
        { return (find_val(0, MAX_N, a, 1)); }

        state get_val(int l, int r, int a, int b, int ind) {
            if (a > r || b < l) {
                default_state.left_s = l;
                default_state.right_s = r;
                return (default_state); 
            }
            
            if (lazy[ind] != 0)
                upd_lazy(ind, l, r);
            
            if (a <= l && r <= b) { return (tree[ind]); }
            
            state leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            state rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (comb(leftS, rightS));
        }

        state query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(int l, int r, int ind, int a, int b, int c) {
            if (ind >= 4 * MAX_N)
                return;
                
            if (lazy[ind] != 0) 
                upd_lazy(ind, l, r);

            if (a > r || b < l) { return; }
            
            if (a <= l && r <= b) { 
                lazy[ind] = c;
                upd_lazy(ind, l, r);
                return;
            }
            
            cout << l << " " << r << " " << ind << " " << a << " " << b << " " << c << endl;
            
            change_val(l, (r + l) / 2, 2 * ind, a, b, c);
            change_val((r + l) / 2 + 1, r, 2 * ind + 1, a, b, c);
        
            tree[ind] = comb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int a, int b, int c)
        { change_val(0, MAX_N, 1, a, b, c); }
};

int main() {
    freopen("seating.in", "r", stdin);
    freopen("seating.out", "w", stdout);

    scanf("%d%d\n", &N, &M);
    
    
    SegTree ans(N);
    ans.update(0, N - 1, 2);

    char a;
	int b, c;
   	
	int go_away = 0, pos;
 
	for (int i = 0; i < M; i ++) {
        scanf("%c", &a);
        
        if (a == 'A') {
            scanf("%d", &b);
            getchar();
            
            if (ans.query(0, N - 1).sz < b)            
        		go_away ++;
        	else {
                pos = ans.find(b);
        	    ans.update(pos, pos + b - 1, 1);
        	}	    
        }

        else {
            scanf("%d%d", &b, &c);
            getchar();
            
            ans.update(b - 1, c - 1, 2);
        }
    }
    
    printf("%d\n", go_away);
	return (0); 
}
