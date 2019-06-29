#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

class SegSum {
    private:
        ii tree[4 * MAX_N];

    public:
        SegSum(int N) {

        }

        ii cmb(ii a, ii b) {
            if (a.f < b.f)
                return (b);
            
            return (a);
        }
    
        ii get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (ii(0, -1)); }

            ii leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            ii rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (cmb(leftS, rightS));
        }

        ii query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind] = ii(newVal, tmp);
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = cmb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int ind, int val)
        { change_val(0, MAX_N, val, 1, ind); }
};

SegSum seg(MAX_N);
SegSum seg2(MAX_N);

int ar[MAX_N], ar2[MAX_N];
int N, K, T;

long long ans;

//# of intervals where max is >= ar2[i] + K
//# of intervals where max is < ar2[i] - K

void divide(int l, int r) {
    int m = seg2.query(l, r).s;
    
    divide(l, m); 
    divide(m + 1, r);
        
    int low = l;
    int hi = m;
    
    while (low < hi) {
        int mid = (low + hi) / 2;
        
        if (seg2.query(mid, m).f <= ar2[m] + K)
            
    }
}

int main() {
    cin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        cin >> N >> K;

        for (int i = 0; i < N; i ++) {
            cin >> ar[i];
            seg.update(i, ar[i]);
        }
    
        for (int i = 0; i < N; i ++) {
            cin >> ar2[i];
            seg2.update(i, ar2[i]);            
        }
        
        ans = 0ll;
        divide(0, N - 1);
        
        cout << "Case #" << (ii + 1) << ": " << ans << endl;
    }

    return (0);
}