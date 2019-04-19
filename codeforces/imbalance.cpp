#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define INF 2000000009
#define MAX_N 1000005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

class SegTree {
    private:
        int tree[(1 << 22)];

    public:
        SegTree(long long N) {
            for (int i = 0; i < (1 << 22); i ++)
                tree[i] = INF;
        }

        int get_val(long long l, long long r, long long a, long long b, long long ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (INF); }

            int leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            int rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (min(leftS, rightS));
        }

        int query(long long a, long long b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(long long l, long long r, long long newVal, long long ind, long long tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind] = min((long long)tree[ind], newVal);
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = min(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(long long ind, long long val)
        { change_val(0, MAX_N, val, 1, ind); }
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

vector<ii> sol;

long long DP[MAX_N], DP2[MAX_N], small[MAX_N], big[MAX_N]; 

int ar[MAX_N];
int N;

int main() {
    fastscan(N);
    
    SegTree seg (MAX_N);
    SegTree seg2 (MAX_N);
    
    for (long long i = 0; i < N; i ++) {
        fastscan(ar[i]);
        sol.push_back(ii(ar[i], i));
    }
    
    sort(sol.begin(), sol.end());
    
    int streak = 0;
    
    small[sol[0].s] = N;
    big[sol[N - 1].s] = N;
    
    seg.update(sol[0].s, sol[0].s);
    seg2.update(sol[N - 1].s, sol[N - 1].s);
    
    for (int i = 1; i < N; i ++) {
        if (sol[i].f == sol[i - 1].f)
            streak ++;
        else {
            for (int j = i - 1; j >= i - streak; j --)
                seg.update(sol[j].s, sol[j].s);
        
            seg.update(sol[i].s, sol[i].s);
            streak = 0;
        }

        small[sol[i].s] = seg.query(sol[i].s + 1, MAX_N);
        
        if (small[sol[i].s] == INF)
            small[sol[i].s] = N;
    }
    
    streak = 0;
    
    for (int i = N - 2; i >= 0; i --) {
        if (sol[i].f == sol[i + 1].f)
            streak ++;
        else {
            for (int j = i + 1; j <= i + streak; j ++)        
                seg2.update(sol[j].s, sol[j].s);
        
            seg2.update(sol[i].s, sol[i].s);
            streak = 0;
        }        
    
        big[sol[i].s] = seg2.query(sol[i].s + 1, MAX_N);
    
        if (big[sol[i].s] == INF)
            big[sol[i].s] = N;        
    }
    
    DP[N - 1] = ar[N - 1];
    DP2[N - 1] = ar[N - 1];
    
    long long ans = 0ll;
    
    for (long long i = N - 2; i >= 0; i --) {
        long long low = big[i];
        
        if (low >= N)
            DP[i] = (N - i) * ar[i];
        else
            DP[i] = max(0ll, (low - i)) * ar[i] + DP[low];
            
        low = small[i];
        
        if (low >= N)
            DP2[i] = (N - i) * ar[i];
        else
            DP2[i] = max(0ll, (low - i)) * ar[i] + DP2[low];

        ans += (DP[i] - DP2[i]);
    }
    
    cout << ans << endl;
    return (0);    
}