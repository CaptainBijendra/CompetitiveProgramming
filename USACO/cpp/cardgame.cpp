#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 150005
#define f first
#define s second

using namespace std;

struct node {
    int P;
    int X, O;
};

class SegTree {
    private:
        node tree[(1 << 19)];
        node default_n;
    
    public:
        SegTree(int N) {
            default_n.P = 0;
            default_n.X = 0;
            default_n.O = 0;
        }

        node get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (default_n); }

            node leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            node rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (cmb(leftS, rightS));
        }

        node query(int a, int b)
        { return (get_val(0, MAX_N - 1, a, b, 1)); }

        node cmb(node a, node b) {
            node res;
            res.P = a.P + b.P;
            
            if (b.O >= a.X) {
                res.O = b.O - a.X + a.O;
                res.X = b.X;
                res.P += a.X;
            }
            
            else {
                res.O = a.O;
                res.X = a.X - b.O + b.X;
                res.P += b.O;
            }
            
            return (res);
        }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {   
                if (newVal == 1) {
                    tree[ind].O = 0;
                    tree[ind].X = 1;
                }
                
                else if (newVal == 2) {
                    tree[ind].O = 1;
                    tree[ind].X = 0;
                }
                
                else {
                    tree[ind].O = 0;
                    tree[ind].X = 0;
                }
                
                tree[ind].P = 0;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = cmb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int ind, int val)
        { change_val(0, MAX_N - 1, val, 1, ind); }
};

bool used[2 * MAX_N];

int ar[MAX_N], ot[MAX_N];
int N;

int main() {
    ifstream fin ("cardgame.in");
    ofstream fout ("cardgame.out");
    
    fin >> N;
    
    for (int i = 0; i < N; i ++) {
        fin >> ar[i];
        used[ar[i]] = true;
    }
    
    int ind = 0;
    for (int i = 2 * N; i >= 1; i --) {
        if (!used[i]) {
            ot[ind] = i;
            ind ++;
        }
    }
    
    SegTree hi(MAX_N);
    SegTree low(MAX_N);
    
    for (int i = 0; i < N; i ++) {
        low.update(2 * N - ar[i], 1);
        low.update(2 * N - ot[i], 2);
    }
    
    int ans = hi.query(0, MAX_N).P + low.query(0, MAX_N).P;
    
    for (int i = 0; i < N; i ++) {
        hi.update(ar[i], 1); low.update(2 * N - ar[i], 3);
        hi.update(ot[i], 2); low.update(2 * N - ot[i], 3); 
        
        ans = max(ans, hi.query(0, MAX_N).P + low.query(0, MAX_N).P);
    } 
    
    fout << ans << endl;
    return (0);
}