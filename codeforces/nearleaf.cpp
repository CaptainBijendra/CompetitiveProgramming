#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define INF 2000000000000009
#define MAX_N 500005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

class SegTree {
    private:
        long long lazy[4 * MAX_N];
        long long tree[4 * MAX_N];

    public:
        SegTree(int N) {
            for (int i = 0; i < 4 * MAX_N; i ++)
                tree[i] = INF;
        }

        long long get_val(int l, int r, int l1, int r1, int ind) {
            if (l1 > r || r1 < l) { return (INF); }
            if (l <= l1 && r1 <= r) { return (tree[ind]); }

            if (lazy[ind] != 0) {
                lazy[2 * ind] += lazy[ind];
                tree[2 * ind] += (tree[2 * ind] == INF ? 0 : lazy[ind]);

                lazy[2 * ind + 1] += lazy[ind];
                tree[2 * ind + 1] += (tree[2 * ind + 1] == INF ? 0 : lazy[ind]);

                lazy[ind] = 0;
            }
            
            long long leftS = get_val(l, r, l1, (r1 + l1) / 2, (2 * ind));
            long long rightS = get_val(l, r, (r1 + l1) / 2 + 1, r1, 2 * ind + 1);

            return (min(leftS, rightS));
        }

        long long query(int a, int b)
        { return (get_val(a, b, 0, MAX_N, 1)); }

        void change_val(int l, int r, long long newVal, bool newR, int ind, int a, int b) {
            if (l > b || r < a) { return; }
            if (a <= l && r <= b) {
                if (tree[ind] != INF)
                    tree[ind] += newVal;
                else if (newR)
                    tree[ind] = newVal;
                
                lazy[ind] += newVal;
                return;
            }

            if (lazy[ind] != 0) {
                lazy[2 * ind] += lazy[ind];
                tree[2 * ind] += (tree[2 * ind] == INF ? 0 : lazy[ind]);

                lazy[2 * ind + 1] += lazy[ind];
                tree[2 * ind + 1] += (tree[2 * ind + 1] == INF ? 0 : lazy[ind]);

                lazy[ind] = 0;
            }

            change_val(l, (r + l) / 2, newVal, newR, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, newR, 2 * ind + 1, a, b);
            
            tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int a, int b, long long val, bool nR)
        { change_val(0, MAX_N, val, nR, 1, a, b); }
};

SegTree seg(MAX_N);

vector<ii> con[MAX_N];
vector<pii> sol[MAX_N];

long long sum[MAX_N], ans[MAX_N], sz[MAX_N];
int N, M;

void DFS (int ind) {
    sz[ind] = 1;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        sum[con[ind][i].f] = sum[ind] + con[ind][i].s;
        DFS (con[ind][i].f);
        
        sz[ind] += sz[con[ind][i].f];
    }
}

void DFS2 (int ind) {
    for (int i = 0; i < con[ind].size(); i ++) {
        int l = con[ind][i].f;
        int r = con[ind][i].f + sz[con[ind][i].f] - 1;
        
        seg.update(0, l - 1, con[ind][i].s, 0);
        seg.update(r + 1, N - 1, con[ind][i].s, 0);
        seg.update(l, r, -con[ind][i].s, 0);
        
        DFS2 (con[ind][i].f);
    
        seg.update(0, l - 1, -con[ind][i].s, 0);
        seg.update(r + 1, N - 1, -con[ind][i].s, 0);
        seg.update(l, r, con[ind][i].s, 0);
    }
    
    for (int i = 0; i < sol[ind].size(); i ++)
        ans[sol[ind][i].s] = seg.query(sol[ind][i].f.f, sol[ind][i].f.s);
}

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

int main() {
    fastscan(N);
    fastscan(M);

    int a, b, c;
    for (int i = 0; i < N - 1; i ++) {
        fastscan(a);
        fastscan(b);
        con[a - 1].push_back(ii(i + 1, b));
    }
    
    DFS (0);
    
    for (int i = 0; i < N; i ++)
        if (con[i].size() == 0)
            seg.update(i, i, sum[i], 1);

    for (int i = 0; i < M; i ++) {
        fastscan(a);
        fastscan(b);
        fastscan(c);
        
        sol[a - 1].push_back(pii(ii(b - 1, c - 1), i));
    }

    DFS2 (0);
    
    for (int i = 0; i < M; i ++)
        cout << ans[i] << endl;

    return (0);
}