#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

#define MAX_N 100005
#define INF 2000000009
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int ar[MAX_N], ev[MAX_N];
int N, M;

class SegSum {
    private:
        ii tree[(1 << 18)];

    public:
        SegSum(int N) {

        }

        ii get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (ii(0, INF)); }

            ii leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            ii rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (ii(leftS.f + rightS.f, min(leftS.s, rightS.s)));
        }

        ii query(int a, int b)
        { return (get_val(0, (1 << 17) - 1, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind].f += newVal;
                tree[ind].s += newVal;
                
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind].f = tree[2 * ind].f + tree[2 * ind + 1].f;
            tree[ind].s = min(tree[2 * ind].s, tree[2 * ind + 1].s);
        }

        void update(int ind, int val)
        { change_val(0, (1 << 17) - 1, val, 1, ind); }
        
        void update(int l, int r, int val) {
            for (int i = l; i <= r; i ++) { 
                change_val(0, (1 << 17) - 1, val, 1, i);
            }
        }
};

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) 
        cin >> ar[i];
    
    sort(ar, ar + N);
    reverse(ar, ar + N);
    
    SegSum ans(N);
    
    for (int i = 0; i < N; i ++)
        ans.update(i, ar[i]);
        
    for (int i = 0; i < M; i ++) 
        cin >> ev[i];
    
    int p1 = 0;
    
    for (int i = 0; i < M; i ++) {
        if (p1 + ev[i] - 1 < N) {
            ans.update(p1, p1 + ev[i] - 1, -1);
            
            for (int i = 0; i < N; i ++) {
                cout << ans.query(i, i).f << endl;
            }
            
            cout << "__________________" << endl;
            
            while (ans.query(p1, p1).s == 0)
                p1 ++;
        }
        
        else { 
            cout << i << endl;
            break;
        }
    }
    
    return (0);
}