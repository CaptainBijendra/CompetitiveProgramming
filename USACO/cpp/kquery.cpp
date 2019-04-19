#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define MAX_N 30005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;  
typedef pair<ii, ii> pii;

vector<pii> query;
vector<ii> sweep;

int ar[MAX_N], res[MAX_N];
int N, M;

class BIT {
    public:
        int tree[MAX_N];

        BIT(int sz) {
            for (int i = 0; i < sz; i ++) 
            { tree[i] = 0; }
        }
    
        int query(int index) {
            int sum = 0;
            
            index ++;
            
            while (index > 0) {
                sum += tree[index];
                index -= (index & (-index));
            }
        
            return (sum);
        }
        
        void update(int index, int val) {
            index ++;
            
            while (index < MAX_N) {
                tree[index] += val;
                index += (index & (-index));
            }
        }
};

bool cmp(pii a, pii b) {
    return (a.f.f < b.f.f);
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
    
    for (int i = 0; i < N; i ++) {
        fastscan(ar[i]);
        sweep.push_back(ii(ar[i], i));
    }
    
    sort(sweep.begin(), sweep.end());
    reverse(sweep.begin(), sweep.end());

    fastscan(M);
    
    int a, b, c;
    for (int i = 0; i < M; i ++) {
        fastscan(a);
        fastscan(b);
        fastscan(c);

        a --; b --; 
        
        query.push_back(pii(ii(c, i), ii(a, b)));
    }
    
    sort(query.begin(), query.end(), cmp);
    reverse(query.begin(), query.end());
    
    BIT ans(MAX_N);

    int lft = 0;

    for (int i = 0; i < query.size(); i ++) {
        while (lft < sweep.size() && sweep[lft].f > query[i].f.f) {
            ans.update(sweep[lft].s, 1);
            lft ++;
        }
        
        res[query[i].f.s] = ans.query(query[i].s.s) - ans.query(query[i].s.f - 1);
    }
    
    for (int i = 0; i < M; i ++)
        cout << res[i] << endl;

    return (0);
}