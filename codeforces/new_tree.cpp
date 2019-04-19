#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define INF 200000000000009
#define MAX_N 400005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int sz[MAX_N], start[MAX_N], col[MAX_N];
int N, M, t;

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
                lazy[2 * ind] = lazy[ind];
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

void DFS (int ind) {
    sz[ind] = 1;
    start[ind] = t; t ++;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!sz[con[ind][i]]) {
            DFS (con[ind][i]);
            sz[ind] += sz[con[ind][i]];
        }
    }
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
    
    for (int i = 0; i < N; i ++)
        fastscan(col[i]);

    int a, b, c;
    for (int i = 0; i < N - 1; i ++) {
        fastscan(a); fastscan(b);
        a --; b --;
        
        con[a].push_back(b);
        con[b].push_back(a);
    }
    
    t = 0;
    DFS (0);
    
    SegTree seg(MAX_N);
    
    for (int i = 0; i < N; i ++)
        seg.update(start[i], start[i], col[i]);
    
    for (int i = 0; i < M; i ++) {
        cin >> a; 
        
        if (a == 1) {
            cin >> b >> c;
            b --;
        
            seg.update(start[b], start[b] + sz[b] - 1, c);    
        }
        
        else {
            cin >> b;
            b --;
            
            cout << __builtin_popcountll(seg.query(start[b], start[b] + sz[b] - 1)) << endl;
        }
    }
    
    return (0);
}