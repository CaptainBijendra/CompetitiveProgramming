#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

int q[MAX_N];
int Q;

class SegTree {
    private:
        int tree[(1 << 23)];
        int sum[(1 << 23)];

    public:
        SegTree(int N) {
            
        }

        int get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (0); }

            int leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            int rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);
            
            bool pos = !((b < ((l + r) / 2 + 1)) || (a > r)) && rightS != 0;
            
            return (max(rightS, leftS + (pos ? sum[2 * ind + 1] : 0)));
        }

        int query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(int l, int r, int newVal, int newVal2, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind] = newVal + newVal2;;
                sum[ind] = newVal2;
                
                return;
            }

            change_val(l, (r + l) / 2, newVal, newVal2, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, newVal2, 2 * ind + 1, tmp);

            tree[ind] = max(tree[2 * ind + 1], sum[2 * ind + 1] + tree[2 * ind]);
            sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
        }

        void update(int ind, int val, int val2)
        { change_val(0, MAX_N, val, val2, 1, ind); }
}; 

int main() {
    cin >> Q;
    
    SegTree ans(MAX_N);

    char a;
    int x, y;

    for (int i = 0; i < Q; i ++) {
        cin >> a;
        
        if (a == '?') {
            cin >> x;
            cout << max(0, ans.query(0, x) - x) << endl;
        }
        
        if (a == '+') {
            cin >> x >> y;
            q[i] = x;

            ans.update(x, x, y);
        }
        
        if (a == '-') {
            cin >> x;
            ans.update(q[x - 1], 0, 0);
        }
    }
    
    return (0);
}