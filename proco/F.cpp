#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <string.h>
#include <math.h>
#include <set>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

class SegTree {
    private:
        long double lazy[4 * MAX_N];
        long double tree[4 * MAX_N];

    public:
        SegTree(long double N) {

        }

        long double get_val(int l, int r, int l1, int r1, int ind) {
            if (l1 > r || r1 < l) { return (0.0); }
            if (l <= l1 && r1 <= r) { return (tree[ind]); }

            if (lazy[ind] >= 0.0) {
                lazy[2 * ind] = lazy[ind];
                tree[2 * ind] = lazy[ind];

                lazy[2 * ind + 1] = lazy[ind];
                tree[2 * ind + 1] = lazy[ind];

                lazy[ind] = -1.0;
            }

            long double leftS = get_val(l, r, l1, (r1 + l1) / 2, (2 * ind));
            long double rightS = get_val(l, r, (r1 + l1) / 2 + 1, r1, 2 * ind + 1);

            return ((leftS + rightS));
        }

        long double query(int a, int b)
        { return (get_val(a, b, 0, MAX_N, 1)); }

        void change_val(int l, int r, long double newVal, int ind, int a, int b) {
            if (l > b || r < a) { return; }
            if (a <= l && r <= b) {
                lazy[ind] = newVal;
                tree[ind] = newVal;
                
                return;
            }

            if (lazy[ind] >= 0.0) {
                lazy[2 * ind] = lazy[ind];
                tree[2 * ind] = lazy[ind];

                lazy[2 * ind + 1] = lazy[ind];
                tree[2 * ind + 1] = lazy[ind];

                lazy[ind] = -1.0;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, a, b);
            
            tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
        }

        void update(long double a, long double b, long double val)
        { change_val(0, MAX_N, val, 1, a, b); }
};

int N, M;

int main() {
    cin >> N >> M;
    
    SegTree seg (MAX_N);
    
    int x;
    for (int i = 0; i < N; i ++) {
        cin >> x;
        seg.update(i, i, x * 1.0);
    }
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        a --; b --;
        
        if (a == b) {
            continue;
        }
        
        long double sum = seg.query(a, b);
        
        seg.update(a + 1, b - 1, 0.0);
        seg.update(a, a, sum / 2.0);
        seg.update(b, b, sum / 2.0);
    }
    
    cout << fixed << setprecision(18) << seg.query(0, 0);
    for (int i = 1; i < N; i ++) {
        cout << " " << fixed << setprecision(18) << (long double)seg.query(i, i);
    }
    
    cout << endl;
    return (0);
}