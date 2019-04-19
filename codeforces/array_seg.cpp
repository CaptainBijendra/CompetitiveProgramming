#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define INF 2000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<int> fin[MAX_N], L[MAX_N], R[MAX_N];

int ar[MAX_N];
int N, Q;

class SegTree {
    private:
        int lazy[4 * (MAX_N)];
        ii tree[4 * MAX_N];

    public:
        SegTree(int N) {
            
        }
        
        ii comb(ii a, ii b) {
            return (ii(max(a.f, b.f), min(a.s, b.s)));
        }

        ii get_val(int l, int r, int l1, int r1, int ind) {
            if (l1 > r || r1 < l) { return (ii(-INF, INF)); }
            if (l <= l1 && r1 <= r) { return (tree[ind]); }

            if (lazy) {
                lazy[2 * ind] += lazy[ind];
                tree[2 * ind].f -= lazy[ind];
                tree[2 * ind].s -= lazy[ind];

                lazy[2 * ind + 1] += lazy[ind];
                tree[2 * ind + 1].f -= lazy[ind];
                tree[2 * ind + 1].s -= lazy[ind];

                lazy[ind] = 0;
            }

            ii leftS = get_val(l, r, l1, (r1 + l1) / 2, (2 * ind));
            ii rightS = get_val(l, r, (r1 + l1) / 2 + 1, r1, 2 * ind + 1);

            return (comb(leftS, rightS));
        }

        ii query(int a, int b)
        { return (get_val(a, b, 0, 100005, 1)); }

        void change_val(int l, int r, int newVal, int ind, int a, int b) {
            if (l > b || r < a) { return; }
            if (a <= l && r <= b) {
                lazy[ind] += newVal;
                tree[ind].f -= newVal;
                tree[ind].s -= newVal;
                
                return;
            }

            if (lazy) {
                lazy[2 * ind] += lazy[ind];
                tree[2 * ind].f -= lazy[ind];
                tree[2 * ind].s -= lazy[ind];

                lazy[2 * ind + 1] += lazy[ind];
                tree[2 * ind + 1].f -= lazy[ind];
                tree[2 * ind + 1].s -= lazy[ind];

                lazy[ind] = 0;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, a, b);
            
            tree[ind] = comb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int a, int b, int val)
        { change_val(0, 100005, val, 1, a, b); }
}; 

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
    fastscan(Q);

    int big = -INF;
    int small = INF;
    
    SegTree seg(MAX_N);

    for (int i = 0; i < N; i ++) {
        fastscan(ar[i]);
        seg.update(i, i, -ar[i]);
    }
    
    if (N == 1) {
        cout << "0\n0\n" << endl;
        return (0);
    }
    
    int a, b;
    for (int i = 0; i < Q; i ++) {
        fastscan(a); fastscan(b);
        L[a - 1].push_back(b - 1);
        R[b - 1].push_back(a - 1);
    
        if (a - 1 <= 0 && 0 <= b - 1) 
            seg.update(a - 1, b - 1, 1);
        
        for (int j = 0; j < N; j ++) {
            if (a - 1 <= j && j <= b - 1)
                fin[j].push_back((i + 1));
        }
    }
    
    int ans = (seg.query(0, N - 1).f - seg.query(0, N - 1).s);
    int ind = 0;
    
    for (int i = 1; i < N; i ++) {
        for (int j = 0; j < L[i].size(); j ++)
            seg.update(i, L[i][j], 1);
        
        for (int j = 0; j < R[i - 1].size(); j ++)
            seg.update(R[i - 1][j], i - 1, -1);
        
        big = seg.query(0, N - 1).f;
        small = seg.query(0, N - 1).s;
        
        if (ans < (big - small)) {
            ans = (big - small);
            ind = i;
        }
    }
    
    cout << ans << endl;
    cout << fin[ind].size() << endl;
    
    for (int i = 0; i < fin[ind].size(); i ++)
        cout << fin[ind][i] << " ";
        
    cout << endl;
    return (0);
}