#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

class SegMax {
    private:
        ii tree[4 * MAX_N];

    public:
        SegMax(int N) {

        }

        ii cmb(ii l, ii r) {
            if (l.f < r.f)
                return (r);
            else
                return (l);
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

SegMax seg(MAX_N);

bool vis[MAX_N];

int ar[MAX_N];
int N, ans;

void solve(int l, int r) {
    if (r - l + 1 < 3) {
        vis[ar[l]] = true;
        vis[ar[r]] = true;
        return;
    }
    
    if (r - l + 1 == 3) {
        vis[ar[l]] = true;
        vis[ar[l + 1]] = true;
        vis[ar[l + 2]] = true;
        
        ans += ((ar[l] + ar[l + 2]) == max(max(ar[l], ar[l + 1]), ar[l + 2]));
        return;
    }
    
    int m = seg.query(l, r).s;
    
    if (r == m) {
        solve(l, m - 1);
        vis[ar[m]] = true;
        return;
    } else if (l == m) {
        solve(m + 1, r);
        vis[ar[m]] = true;
        return;
    }
    
    solve(l, m - 1);
    
    for (int i = m + 1; i <= r; i ++)
        ans += (vis[ar[m] - ar[i]]);
    for (int i = l; i <= m; i ++)
        vis[ar[i]] = false;
                
    solve(m + 1, r);
    
    for (int i = l; i <= m; i ++)
        vis[ar[i]] = true;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        seg.update(i, ar[i]);
    }
    
    ans = 0;
    solve(0, N - 1);
    
    cout << ans << endl;
    return (0);
}