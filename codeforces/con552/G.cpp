#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int ar[MAX_N];
int N, M;

long long lcm(long long a, long long b) {
    return ((a * b) / __gcd(a, b));
}

int cnv[MAX_N * 10];
int cnt[MAX_N * 10];

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
        cnv[ar[i]] = i;
        cnt[ar[i]] ++;
    }
    
    long long c_lcm = -1;
    
    for (int i = 0; i < N; i ++) {
        if (cnt[ar[i]] >= 2) {
            if (c_lcm == -1)
                c_lcm = ar[i];
            else    
                c_lcm = min(c_lcm, (long long)ar[i]);
        }
    }
    
    int x = -1;
    int y = -1;
    
    for (int i = 0; i < N; i ++) {
        if ((long long)ar[i] == c_lcm) {
            if (x == -1)
                x = i;
            else
                y = i;
        }
    }
        
    sort(ar, ar + N);
    
    if (c_lcm == -1) {
        c_lcm = (long long)MAX_N * (long long)MAX_N * 100ll;
    }
    
    for (int i = 0; i < N; i ++) {
        if (i + 1 < N && ar[i + 1] >= c_lcm)
            break;
        
        for (int j = i + 1; j < N; j ++) {
            if (ar[j] >= c_lcm)
                break;
            if (ar[j] == ar[j - 1])
                continue;
            
            long long t = lcm((long long)ar[i], (long long)ar[j]);
            
            if (t < c_lcm) {
                c_lcm = t;
                x = cnv[ar[i]];
                y = cnv[ar[j]];
            }
        }
    }
    
    cout << min(y + 1, x + 1) << " " << max(x + 1, y + 1) << endl;
    return (0);
}