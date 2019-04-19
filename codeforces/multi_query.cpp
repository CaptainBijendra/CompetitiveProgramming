#include <bits/stdc++.h> 

#define INF 2000000009
#define MAX_N 200005
#define f first
#define s second

using namespace std;

class SegTree {
    private:
        int tree[MAX_N * 4];

    public:
        SegTree() {
            for (int i = 0; i < MAX_N * 4; i ++)
                tree[i] = -INF;
        }

        int get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (-INF); }

            int leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            int rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);
            
            return (max(leftS, rightS));
        }

        int query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {   
                tree[ind] = newVal;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int ind, int val)
        { change_val(0, MAX_N, val, 1, ind); }
};

SegTree pos[33];

int tmp[MAX_N];
int N, K, M;

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
    fastscan(K);

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < K; j ++)
            fastscan(tmp[j]);
    
        for (int j = 0; j < (1 << K); j ++) {
            int sum = 0;

            for (int k = 0; k < K; k ++) {
                if ((j & (1 << k)))
                    sum += tmp[k];
                else
                    sum -= tmp[k];
            }
            
            pos[j].update(i, sum);
        }
    }
    
    fastscan(M);

    int a, b, c;
    for (int i = 0; i < M; i ++) {
        fastscan(a);

        if (a == 1) {
            fastscan(b);
            
            for (int j = 0; j < K; j ++)
                fastscan(tmp[j]);
                
            for (int j = 0; j < (1 << K); j ++) {
                int sum = 0;

                for (int k = 0; k < K; k ++) {
                    if ((j & (1 << k)))
                        sum += tmp[k];
                    else
                        sum -= tmp[k];
                }
                
                pos[j].update(b - 1, sum);
            }
        }
        
        else {
            fastscan(b);
            fastscan(c);
                
            int ans = 0;
            for (int j = 0; j < (1 << K); j ++)
                ans = max(ans, pos[j].query(b - 1, c - 1) + pos[(1 << K) - 1 - j].query(b - 1, c - 1));
            
            cout << ans << "\n";
        }
    }

    return (0);
}