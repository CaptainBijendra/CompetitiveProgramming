#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
map<int, ii> mp;

vector<int> con[MAX_N];

ii ans[MAX_N];

int cnt[MAX_N];
int N, M;

class SegTree {
    private:
        int tree[(1 << 18)];

    public:
        SegTree(int N) {
        
        }

        int get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (0); }

            int leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            int rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (leftS + rightS);
        }

        int query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind] += newVal;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);
        
            tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
        }

        void update(int ind, int val)
        { change_val(0, MAX_N, val, 1, ind); }
};

int main() {
    cin >> N >> M;
    
    int x;
    for (int i = 0; i < M; i ++) {
        cin >> x;
            
        int a;
        for (int j = 0; j < x; j ++) {
            cin >> a;
            cnt[a] ++;
        
            con[i].push_back(a);
        }
    }
    
    for (int i = 1; i < MAX_N; i ++) {
        ans[i].f = 0;
        ans[i].s = INF;
    }
    
    SegTree solve(MAX_N);
    
    for (int i = 0; i < M; i ++) {
        mp.clear();
        
        for (int j = 0; j < con[i].size(); j ++)
            solve.update(cnt[con[i][j]], 1);
    
        for (int j = 0; j < con[i].size(); j ++) {
            mp[con[i][j]].f = solve.query(cnt[con[i][j]] + 1, M + 5);
            mp[con[i][j]].s = solve.query(cnt[con[i][j]], M + 5) - 1;
        }

        for (int j = 0; j < con[i].size(); j ++)
            solve.update(cnt[con[i][j]], -1);
        
        for (int j = 0; j < con[i].size(); j ++) {
            ans[con[i][j]].f = max(ans[con[i][j]].f, mp[con[i][j]].f);
            ans[con[i][j]].s = min(ans[con[i][j]].s, mp[con[i][j]].s);
        }
    }
    
    for (int i = 1; i <= N; i ++)
        cout << ans[i].f << " " << max(ans[i].f, ans[i].s) << endl;
    
    return (0);
}