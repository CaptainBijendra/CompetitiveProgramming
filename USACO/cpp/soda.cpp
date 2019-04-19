#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

#define INF 2000000009
#define MAX_N 50005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

vector<ii> points;
vector<int> ps;

map<int, int> coord;

int N;

class SegTree {
    private:
        long long lazy[4 * (MAX_N)];

        ii tree[4 * MAX_N];

    public:
        SegTree(long long N) {

        }

        ii get_val(long long l, long long r, long long l1, long long r1, long long ind) {
            if (l1 > r || r1 < l) { return (ii(0, INF)); }
            if (l <= l1 && r1 <= r) { return (tree[ind]); }

            if (lazy[ind]) {
                lazy[2 * ind] += lazy[ind];
                tree[2 * ind].f += ((l1 + r1) / 2 - l1 + 1) * lazy[ind];
                tree[2 * ind].s += lazy[ind];

                lazy[2 * ind + 1] += lazy[ind];
                tree[2 * ind + 1].f += (r1 - ((r1 + l1) / 2)) * lazy[ind];
                tree[2 * ind + 1].s += lazy[ind];

                lazy[ind] = 0;
            }

            ii leftS = get_val(l, r, l1, (r1 + l1) / 2, (2 * ind));
            ii rightS = get_val(l, r, (r1 + l1) / 2 + 1, r1, 2 * ind + 1);

            return (ii(leftS.f + rightS.f, max(leftS.s, rightS.s)));
        }

        ii query(long long a, long long b)
        { return (get_val(a, b, 0, (1 << 16) - 1, 1)); }

        void change_val(long long l, long long r, long long newVal, long long ind, long long a, long long b) {
            if (l > b || r < a) { return; }
            if (a <= l && r <= b) {
                lazy[ind] += newVal;
                tree[ind].f += (r - l + 1) * newVal;
                tree[ind].s += newVal;

                return;
            }

            if (lazy[ind]) {
                lazy[2 * ind] += lazy[ind];
                tree[2 * ind].f += ((r + l) / 2 - l + 1) * lazy[ind];
                tree[2 * ind].s += lazy[ind];

                lazy[2 * ind + 1] += lazy[ind];
                tree[2 * ind + 1].f += (r - ((r + l) / 2)) * lazy[ind];
                tree[2 * ind + 1].s += lazy[ind];

                lazy[ind] = 0;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, a, b);

            tree[ind].f = tree[2 * ind].f + tree[2 * ind + 1].f;
            tree[ind].s = max(tree[2 * ind].s, tree[2 * ind + 1].s);
        }

        void update(long long a, long long b, long long val)
        { change_val(0, (1 << 16) - 1, val, 1, a, b); }
};    

int main() {
    cin >> N;
    
    SegTree ans (4 * MAX_N);
    
    for (int i = 0; i < N; i ++) {
        int a, b;
        
        cin >> a >> b;
        points.push_back(ii(a, b));
        
        ps.push_back(a);
        ps.push_back(b);
    }
    
    sort(ps.begin(), ps.end());
    
    int c = 0;
    
    for (int i = 0; i < ps.size(); i ++) {
        if (ps[i] == ps[i - 1])
            continue;
        
        coord[ps[i]] = c;
        c ++;
    }
    
    for (int i = 0; i < N; i ++) { 
        ans.update(coord[points[i].f], coord[points[i].s], 1);
    }
    
    cout << ans.query(0, (1 << 17) + 1).s << endl;
    return (0);
}