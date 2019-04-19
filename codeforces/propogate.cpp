#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define INF 200000000000009
#define MAX_N 200005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int sz[MAX_N], start[MAX_N], d[MAX_N], ar[MAX_N], conv[MAX_N];
int N, M, t;

class SegTree {
    private:
        int lazy[4 * MAX_N][2];
        int tree[4 * MAX_N][2];

    public:
        SegTree(int N) {
            
        }

        int get_val(int l, int r, int l1, int r1, int ind) {
            if (l1 > r || r1 < l) { return (0); }
            if (l <= l1 && r1 <= r) {
                if (d[conv[l1]] % 2 == 0)
                    return (tree[ind][0] - tree[ind][1]);
                else
                    return (tree[ind][1] - tree[ind][0]);
            }
            
            if (lazy[ind][0]) {
                lazy[2 * ind][0] += lazy[ind][0];
                tree[2 * ind][0] += lazy[ind][0];

                lazy[2 * ind + 1][0] += lazy[ind][0];
                tree[2 * ind + 1][0] += lazy[ind][0];

                lazy[ind][0] = 0;
            }

            if (lazy[ind][1]) {
                lazy[2 * ind][1] += lazy[ind][1];
                tree[2 * ind][1] += lazy[ind][1];

                lazy[2 * ind + 1][1] += lazy[ind][1];
                tree[2 * ind + 1][1] += lazy[ind][1];

                lazy[ind][1] = 0;
            }

            int leftS = get_val(l, r, l1, (r1 + l1) / 2, (2 * ind));
            int rightS = get_val(l, r, (r1 + l1) / 2 + 1, r1, 2 * ind + 1);

            return (leftS + rightS);
        }

        int query(int a, int b)
        { return (get_val(a, b, 0, MAX_N, 1)); }

        void change_val(int l, int r, int newVal, int parity, int ind, int a, int b) {
            if (l > b || r < a) { return; }
            if (a <= l && r <= b) {
                lazy[ind][parity] += newVal;
                tree[ind][parity] += newVal;
                return;
            }

            if (lazy[ind][0]) {
                lazy[2 * ind][0] += lazy[ind][0];
                tree[2 * ind][0] += lazy[ind][0];

                lazy[2 * ind + 1][0] += lazy[ind][0];
                tree[2 * ind + 1][0] += lazy[ind][0];

                lazy[ind][0] = 0;
            }

            if (lazy[ind][1]) {
                lazy[2 * ind][1] += lazy[ind][1];
                tree[2 * ind][1] += lazy[ind][1];

                lazy[2 * ind + 1][1] += lazy[ind][1];
                tree[2 * ind + 1][1] += lazy[ind][1];

                lazy[ind][1] = 0;
            }

            change_val(l, (r + l) / 2, newVal, parity, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, parity, 2 * ind + 1, a, b);
        }

        void update(int  a, int  b, int val, int par)
        { change_val(0, MAX_N, val, par, 1, a, b); }
};

void DFS (int ind) {
    sz[ind] = 1;
    start[ind] = t;
    conv[t] = ind;
    
    t ++;

    for (int i = 0; i < con[ind].size(); i ++) {
        if (!sz[con[ind][i]]) {
            d[con[ind][i]] = d[ind] + 1;
            DFS (con[ind][i]);
            
            sz[ind] += sz[con[ind][i]];
        }
    }
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];

    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        a --; b --;
    
        con[a].push_back(b);
        con[b].push_back(a);
    }
    
    t = 1;
    DFS (0);
    
    SegTree seg(MAX_N);

    for (int i = 0; i < N; i ++)
        seg.update(start[i], start[i], ar[i], d[i] % 2);
    
    int c;
    for (int i = 0; i < M; i ++) {
        cin >> a;    
    
        if (a == 1) {
            cin >> b >> c;
            b --;
            
            seg.update(start[b], start[b] + sz[b] - 1, c, d[b] % 2);
        }
        
        else {
            cin >> b; b --;
            cout << seg.query(start[b], start[b]) << endl;
        }
    }
    
    return (0);
}