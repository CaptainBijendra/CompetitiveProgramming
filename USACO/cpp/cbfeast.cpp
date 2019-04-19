#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 20005
#define f first
#define s second

using namespace std;

struct node {
    int pre, sum, suf, bst;   
};

class SegTree {
    private:
        node tree[(1 << 16)];
        node default_node;

    public:
        SegTree(int N) {
            default_node.pre = 0;
            default_node.suf = 0;
            default_node.sum = 0;
            default_node.bst = 0;
            
            for (int i = 0; i < (1 << 16); i ++) 
                tree[i] = default_node;
        }

        node comb(node a, node b) {
            node res;
            
            if (b.pre == 0 && b.suf == 0 && b.sum == 0 && b.bst == 0)
                return (a);
            else
                return (b);
        }

        node get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (default_node); }

            node leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            node rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (comb(leftS, rightS));
        }

        node query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val1(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind].pre = max(0, tree[ind].pre + newVal);
                tree[ind].sum = tree[ind].sum + newVal;
                tree[ind].bst = max(max(0, tree[ind].bst), max(tree[ind].pre, max(tree[ind].suf, tree[ind].sum)));
                return;
            }

            change_val1(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val1((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = comb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update1(int ind, int val)
        { change_val1(0, MAX_N, val, 1, ind); }
        
        void change_val2(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind].suf = max(0, tree[ind].suf + newVal);
                tree[ind].sum = tree[ind].sum + newVal;
                tree[ind].bst = max(max(0, tree[ind].bst), max(tree[ind].pre, max(tree[ind].suf, tree[ind].sum)));
                return;
            }

            change_val2(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val2((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = comb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update2(int ind, int val)
        { change_val2(0, MAX_N, val, 1, ind); }
        
};

int Q, K;

int main() {
    cin >> Q >> K;
    
    SegTree ans(MAX_N);

    int a, b, c;
    int prev = 0;
    
    for (int i = 0; i < Q; i ++) {
        cin >> a;
        
        if (a == 1) {
            cin >> b >> c;
            
            for (int i = 1 - b; i <= K; i ++)
                ans.update1(b + i, c);
        }
        
        if (a == 2) {
            cin >> b >> c;
            
            for (int i = 1 - b; i <= K; i ++) 
                ans.update2(b + i, c);
        }
        
        if (a == 3) {
            cin >> c;
            c = c ^ prev;
            
            cout << ans.query(c, c).bst << endl;
            prev = ans.query(c, c).bst;
        }
    }

    return (0);
}