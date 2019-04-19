#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define MOD 1000000007
#define MAX_N 40005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

struct node {
    long long mask;
    long long val;
};

node numbers[305];

long long primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179,
                       181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293 };

long long calc[65];

int ar[MAX_N];
int N, Q;

long long fast_expo (long long base, long long pow) {
    if (pow == 1)
        return (base);
    if (pow == 0)
        return (1);
    
    if (pow % 2 == 0) {
        long long a = fast_expo(base, pow / 2);
        return ((a * a) % MOD);
    }
    
    else {
        long long a = fast_expo(base, (pow - 1) / 2);
        return ((((a * a) % MOD) * base) % MOD);
    }
}

class SegTree {
    private:
        node lazy[4 * MAX_N];
        node tree[4 * MAX_N];
        node default_node;

    public:
        SegTree(long long N) {            
            default_node.mask = 0;
            default_node.val = 1;
            
            for (long long i = 0; i < 4 * MAX_N; i ++) {
                tree[i] = default_node;
                lazy[i] = default_node;
            }
        }
        
        node comb(node a, node b) {
            node n;
                        
            n.mask = (a.mask | b.mask);
            n.val = (a.val * b.val) % MOD;
                        
            return (n);
        }
        
        node comb2(node a, node b, int dist) {
            node n;
            
            n.mask = (a.mask | b.mask);
            n.val = (a.val * fast_expo(b.val, dist)) % MOD;
            
            return (n);
        }

        node get_val(long long l, long long r, long long l1, long long r1, long long ind) {
            if (l1 > r || r1 < l) { return (default_node); }
            if (l <= l1 && r1 <= r) { return (tree[ind]); }

            if (lazy[ind].val != 1) {
                lazy[2 * ind] = comb(lazy[2 * ind], lazy[ind]);
                tree[2 * ind] = comb2(tree[2 * ind], lazy[ind], ((r1 + l1) / 2 - l1 + 1));

                lazy[2 * ind + 1] = comb(lazy[2 * ind + 1], lazy[ind]);
                tree[2 * ind + 1] = comb2(tree[2 * ind + 1], lazy[ind], (r1 - (r1 + l1) / 2));
    
                lazy[ind] = default_node;
            }
            
            node leftS = get_val(l, r, l1, (r1 + l1) / 2, (2 * ind));
            node rightS = get_val(l, r, (r1 + l1) / 2 + 1, r1, 2 * ind + 1);

            return (comb(leftS, rightS));
        }

        node query(long long a, long long b)
        { return (get_val(a, b, 0, MAX_N, 1)); }

        void change_val(long long l, long long r, node newVal, long long ind, long long a, long long b) {
            if (l > b || r < a) { return; }
            if (a <= l && r <= b) {
                lazy[ind] = comb(lazy[ind], newVal);
                tree[ind] = comb2(tree[ind], newVal, r - l + 1);
                
                return;
            }

            if (lazy[ind].val != 1) {
                lazy[2 * ind] = comb(lazy[2 * ind], lazy[ind]);
                tree[2 * ind] = comb2(tree[2 * ind], lazy[ind], ((r + l) / 2 - l + 1));

                lazy[2 * ind + 1] = comb(lazy[2 * ind + 1], lazy[ind]);
                tree[2 * ind + 1] = comb2(tree[2 * ind + 1], lazy[ind], (r - (r + l) / 2));
    
                lazy[ind] = default_node;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, a, b);
            
            tree[ind] = comb(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(long long a, long long b, node newVal)
        { change_val(0, MAX_N, newVal, 1, a, b); }
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

    SegTree seg(MAX_N);
    
    for (int i = 1; i <= 300; i ++) {
        int x = i;
        
        node a;
        a.mask = 0ll;
        a.val = 1ll;
        
        for (long long j = 0; j < 62; j ++) {
            long long cnt = 0;
            
            while (x != 1 && x % primes[j] == 0) {
                x /= primes[j];
                cnt ++;    
                
                a.val *= primes[j];
                a.val %= MOD;
            }
            
            if (cnt >= 1)
                a.mask = (a.mask | (1ll << j));
        }
        
        numbers[i] = a;
    }
    
    for (long long i = 0; i < N; i ++) {
        fastscan(ar[i]);

        node a = numbers[ar[i]];
        seg.update(i, i, a);
    }                       
    
    for (int j = 0; j < 62; j ++)
        calc[j] = fast_expo(primes[j], MOD - 2);
        
    string rekt;

    int l, r, x;
    for (long long i = 0; i < Q; i ++) {
        cin >> rekt;
        cin >> l >> r;

        if (rekt[0] == 'T') {
            node ans =  seg.query(l - 1, r - 1);
            long long x = ans.val;
            
            for (long long j = 0; j < 62; j ++) {                
                if (ans.mask & (1ll << j)) {
                    x *= calc[j];
                    x %= MOD;
                    
                    x *= (primes[j] - 1);
                    x %= MOD;
                }
            }
                        
            cout << x << endl;
        }
        
        else {
            cin >> x;

            node a = numbers[x];
            seg.update(l - 1, r - 1, a);
        }
    }

    return (0);
}