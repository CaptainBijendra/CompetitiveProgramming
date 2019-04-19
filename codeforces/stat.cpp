#include <bits/stdc++.h> 

#define INF 2000000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

class SegTree {
    private:
        ii tree[4 * MAX_N];

    public:
        SegTree(int N) {
        }

        ii comb(ii a, ii b) {
            if (a.f < b.f)
                return (b);
            if (a.f == b.f) 
                return (a.s > b.s ? a : b);
            
            return (a);
        }

        ii get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (ii(0, 0)); }

            ii leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            ii rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (comb(leftS, rightS));
        }

        ii query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(int l, int r, int a, int b, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind] = comb(tree[ind], ii(a, b));
                return;
            }

            change_val(l, (r + l) / 2, a, b, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, a, b, 2 * ind + 1, tmp);

            tree[ind] = comb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int ind, int a)
        { change_val(0, MAX_N, a, ind, 1, ind); }
};

long long DP[MAX_N];

int ar[MAX_N];
int N;

int main() {
    cin >> N;
    SegTree seg(MAX_N);
    
    for (int i = 0; i < N - 1; i ++) {
        cin >> ar[i];    
        ar[i] --;
        
        seg.update(i, ar[i]);
    }
    
    ar[N - 1] = N - 1;
    
    long long ans = 0ll;

    for (int i = N - 2; i >= 0; i --) {
        int ind = seg.query(i + 1, ar[i]).s;
        
        if (ind == 0)
            ind = N - 1;
        
        DP[i] = DP[ind] - (ar[i] - ind) + N - i - 1;
        ans += DP[i];
    }
    
    cout << ans << endl;
    return (0);
}