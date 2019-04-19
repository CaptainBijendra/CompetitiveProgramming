#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

class SegTree {
    private:
        ii tree[(1 << 19)];

    public:
        SegTree(int N) {
        
        }

        ii get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (ii(INF, 0)); }

            ii leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            ii rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (ii(min(leftS.f, rightS.f), max(leftS.s, rightS.s)));
        }

        ii query(int a, int b)
        { return (get_val(0, (1 << 17) - 1, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind].f = newVal;
                tree[ind].s = newVal;
                
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind].f = min(tree[2 * ind].f, tree[2 * ind + 1].f);
            tree[ind].s = max(tree[2 * ind].s, tree[2 * ind + 1].s);
        }

        void update(int ind, int val)
        { change_val(0, (1 << 17) - 1, val, 1, ind); }
};

vector<SegTree> DP;

int ar[MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    for (int i = 0; i < 25; i ++)
        DP.push_back(SegTree (MAX_N));
    
    for (int j = 0; j < N; j ++)
        DP[0].update(j, )
    
    for (int i = 1; i < 25; i ++) {
        
    }
    
    return (0);
}

