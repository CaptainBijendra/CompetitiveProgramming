#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_V 1000000009
#define MAX_N 10005
#define MAX_K 105
#define f first
#define s second
#define ll long long

using namespace std;

typedef pair<ll, ll> Line;

ll ar[MAX_N];
ll N, K;

class LiChao {
    struct Node {
        ll l, r;
        ll left, right;
        Line line;
    };
    
    public:
        vector<Node> tree;
    
        ll f(Line l, ll x) {
            return (l.f * x + l.s);
        }    

        ll query(ll ind, ll val) {
            if (ind == -1) { return (1e18); }
            
            ll l = tree[ind].l; ll r = tree[ind].r;
            ll m = (l + r) / 2;
            
            if (val <= m) {
                return (min(f(tree[ind].line, val), query(tree[ind].left, val)));
            } else {
                return (min(f(tree[ind].line, val), query(tree[ind].right, val)));
            }
        }

        void insert(ll ind, Line newVal) {
            ll l = tree[ind].l; ll r = tree[ind].r;
            ll m = (l + r) / 2;
            
            Line low = tree[ind].line;
            Line hi = newVal;
            
            if (f(low, l) >= f(hi, l)) { swap(low, hi); }
            if (f(low, r) <= f(hi, r)) {
                tree[ind].line = low;
                return;
            }
            
            else if (f(low, m) <= f(hi, m)) {
                tree[ind].line = low;
                
                if (tree[ind].right == -1) {
                    tree[ind].right = tree.size();
                    tree.push_back({m + 1, r, -1, -1, {0, 1e18}});
                }
                
                insert(tree[ind].right, hi);
            }
            
            else if (f(low, m) >= f(hi, m)) {
                tree[ind].line = hi;
                
                if (tree[ind].left == -1) {
                    tree[ind].left = tree.size();
                    tree.push_back({l, m, -1, -1, {0, 1e18}});
                }
                
                insert(tree[ind].left, low);
            }
        }
};

LiChao DP[MAX_K];

ll main() {
    cin >> N >> K;
    
    for (ll i = 0; i < N; i ++)
        cin >> ar[i];
    
    for (ll i = 1; i <= K; i ++) {
        DP[i].tree.push_back({0, MAX_V, -1, -1, {0, 1e18}});
    }
    
    //DP[i][j] = min (DP[k][j - 1] + ar[i]^2 + ar[k + 1]^2 - 2*ar[i]*ar[k + 1]);
    //           k<i
    
    DP[1].insert(0, {-2ll*ar[0], ar[0]*ar[0]});
    
    for (ll i = 0; i < N; i ++) {
        for (ll j = 2; j <= K; j ++) {
            ll pos = DP[j - 1].query(0, ar[i]) + ar[i]*ar[i];
            DP[j].insert(0, {-2*ar[i + 1], ar[i + 1] * ar[i + 1] + pos});
        }
    }
    
    cout << (DP[K].query(0, ar[N - 1]) + ar[N - 1] * ar[N - 1]) << endl;
    return (0);
}