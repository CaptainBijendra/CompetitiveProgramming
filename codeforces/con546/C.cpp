#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define MAX_N 505
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

map<int, int> cnt, cnt2;

int ar[MAX_N][MAX_N], tar[MAX_N][MAX_N];
int N, M;

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
        for (int j = 0; j < M; j ++)
            fastscan(ar[i][j]);
    
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < M; j ++)
            fastscan(tar[i][j]);

    for (int i = 0; i < M; i ++) {
        int x = i;
        
        for (int j = 0; j < N; j ++) {
            if (x < 0)  
                break;
            
            cnt[ar[j][x]] ++;
            x --;
        }

        x = i;
        for (int j = 0; j < N; j ++) {
            if (x < 0)  
                break;
            
            cnt2[tar[j][x]] ++;
            x --;
        }

        x = i;
        for (int j = 0; j < N; j ++) {
            if (x < 0)  
                break;
            
            if (cnt[ar[j][x]] != cnt2[ar[j][x]]) {
                cout << "NO" << endl;
                return (0);
            }
            
            x --;
        }
    }
    
    if (ar[0][0] != tar[0][0] || ar[N - 1][M - 1] != tar[N - 1][M - 1]) {
        cout << "NO" << endl;
        return (0);
    }

    cout << "YES" << endl;
    return (0);
}