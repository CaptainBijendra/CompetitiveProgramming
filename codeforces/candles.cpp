#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int ar[MAX_N], C[MAX_N];
int N, M;

class SegTree {
    private:
        int tree[4 * MAX_N];
        int lazy[4 * MAX_N];

    public:
        SegTree(int N) {

        }
        
        int val(int l, int r, int ind, int tmp) {
            if (tmp < l || tmp > r)
                return (0);
            if (l == r)
                return (tree[ind]);

            if (lazy[ind] != 0) {
                lazy[2 * ind] += lazy[ind];
                tree[2 * ind] += lazy[ind] * ((l + r) / 2 - l + 1);
                
                lazy[2 * ind + 1] += lazy[ind];
                tree[2 * ind + 1] += lazy[ind] * (r - (l + r) / 2);

                lazy[ind] = 0;
            }
            
            int leftS = val(l, (l + r) / 2, 2 * ind, tmp);
            int rightS = val((l + r) / 2 + 1, r, 2 * ind + 1, tmp);
            
            return (leftS + rightS);
        }
        
        ii query(int l, int r, int sum, int ind) {
            if (l == r)
                return (ii(l, sum));

            if (lazy[ind] != 0) {
                lazy[2 * ind] += lazy[ind];
                tree[2 * ind] += lazy[ind] * ((l + r) / 2 - l + 1);
                
                lazy[2 * ind + 1] += lazy[ind];
                tree[2 * ind + 1] += lazy[ind] * (r - (l + r) / 2);

                lazy[ind] = 0;
            }
            
            if (sum >= tree[2 * ind])
                return (query((l + r) / 2 + 1, r, sum - tree[2 * ind], 2 * ind + 1));
            else    
                return (query(l, (l + r) / 2, sum, 2 * ind));
        }
        
        void change_val(int l, int r, int newVal, int ind, int a, int b) {
            if (a > r || b < l) { return; }
            if (a <= l && r <= b) {
                lazy[ind] += newVal;
                tree[ind] += newVal * (r - l + 1);
                return;
            }
            
            if (lazy[ind] != 0) {
                lazy[2 * ind] += lazy[ind];
                tree[2 * ind] += lazy[ind] * ((l + r) / 2 - l + 1);
                
                lazy[2 * ind + 1] += lazy[ind];
                tree[2 * ind + 1] += lazy[ind] * (r - (l + r) / 2);

                lazy[ind] = 0;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, a, b);

            tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
        }

        void update(int a, int b, int val)
        { change_val(0, MAX_N, val, 1, a, b); }
};

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < M; i ++)
        cin >> C[i];
    
    SegTree seg(MAX_N);
    
    int end = MAX_N;
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        seg.update(MAX_N - ar[i] - 5, MAX_N - ar[i] - 5, 1);
    
        end = min(end, MAX_N - ar[i] - 5);
    }
    
    for (int i = 0; i < M; i ++) {
        ii q = seg.query(0, MAX_N, C[i], 1);
        seg.update(end, q.f - 1, -1);
        seg.update(q.f, q.f, -1 * q.s);
    } 

    return (0);
}