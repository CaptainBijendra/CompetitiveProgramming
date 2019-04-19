#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int N, M;

class SegTree {
    private:
        long long lazy[4 * MAX_N];
        long long tree[4 * MAX_N];

    public:
        SegTree(long long N) {

        }
    
        long long comb(long long a, long long b) {
            return (a | b);
        }

        long long get_val(long long l, long long r, long long l1, long long r1, long long ind) {
            if (l1 > r || r1 < l) { return (0); }
            if (l <= l1 && r1 <= r) { return (tree[ind]); }

            if (lazy[ind]) {
                lazy[2 * ind] = lazy[2 * ind] ^ lazy[ind];
                tree[2 * ind] = lazy[ind];

                lazy[2 * ind + 1] = lazy[ind];
                tree[2 * ind + 1] = lazy[ind];

                lazy[ind] = 0;
            }

            long long leftS = get_val(l, r, l1, (r1 + l1) / 2, (2 * ind));
            long long rightS = get_val(l, r, (r1 + l1) / 2 + 1, r1, 2 * ind + 1);

            return (comb(leftS, rightS));
        }

        long long query(long long a, long long b)
        { return (get_val(a, b, 0, MAX_N, 1)); }

        void change_val(long long l, long long r, long long newVal, long long ind, long long a, long long b) {
            if (l > b || r < a) { return; }
            if (a <= l && r <= b) {
                lazy[ind] = (1ll << newVal);
                tree[ind] = (1ll << newVal);
                
                return;
            }

            if (lazy[ind]) {
                lazy[2 * ind] = lazy[ind];
                tree[2 * ind] = lazy[ind];

                lazy[2 * ind + 1] = lazy[ind];
                tree[2 * ind + 1] = lazy[ind];

                lazy[ind] = 0;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, a, b);
            
            tree[ind] = comb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(long long a, long long b, long long val)
        { change_val(0, MAX_N, val, 1, a, b); }
};

int main() {
    cin >> N >> M;
    
    cout << (3 ^ 5 + 4 ^ 5 + 5 ^ 5 + 6 ^ 5 + 7 ^ 5 + 8 ^ 5) << endl;
    cout << ((3 + 4 + 5 + 6 + 7 + 8) ^ 5) << endl;
    
    return (0);
}