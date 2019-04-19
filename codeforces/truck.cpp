#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define INF 2000000009
#define MAX_N 405
#define f first
#define s second

using namespace std;

int DP[MAX_N][MAX_N][MAX_N];
int ar[MAX_N];

int N, Q;

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
    
    for (int i = 0; i < MAX_N; i ++)
        for (int j = 0; j < MAX_N; j ++)
            for (int k = 0; k < MAX_N; k ++)
                DP[i][j][k] = INF;
    
    for (int i = 0; i < N; i ++)
        fastscan(ar[i]);
    
    for (int i = 0; i < N; i ++)
        for (int j = i; j < N; j ++)
            DP[i][j][0] = ar[j] - ar[i];
    
    for (int k = 1; k < MAX_N; k ++) {
        for (int i = 0; i < N; i ++) {
            int hi = i;
            
            for (int j = i; j < N; j ++) {
				while (max(DP[i][hi + 1][k - 1], ar[j] - ar[hi + 1]) < max(DP[i][hi][k - 1], ar[j] - ar[hi]))
				    hi ++;

                DP[i][j][k] = max(DP[i][hi][k - 1], (ar[j] - ar[hi]));
            }
        }
    }
    
    long long ans = 0, bst = 0;
    int a, b, c, d;
    
    for (int i = 0; i < Q; i ++) {
        fastscan(a);
        fastscan(b);
        fastscan(c);
        fastscan(d);

        long long e = c;

        ans = max(ans, (long long)(DP[a - 1][b - 1][d]) * e);
    }
    
    cout << ans << endl;
    return (0);
}
