#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define INF 1000000009
#define MAX_N 5005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

int DP[MAX_N][MAX_N][2], cost[MAX_N], disc[MAX_N], sz[MAX_N];
int N, B;

void begin(int ind) {
    vis[ind] = true;
    sz[ind] = 1;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            begin (con[ind][i]);
            sz[ind] += sz[con[ind][i]];
        }
    }
    
    vis[ind] = false;
}

void DFS (int ind) {
    vis[ind] = true;

    DP[ind][1][0] = cost[ind];
    DP[ind][1][1] = disc[ind];
    
    int now = 1;

    for (int i = 0; i < con[ind].size(); i ++) {
        if (!vis[con[ind][i]]) {
            DFS (con[ind][i]);
            
            for (int j = now; j >= 0; j --) {
                for (int k = 0; k <= sz[con[ind][i]]; k ++) {
                    DP[ind][j + k][1] = min(DP[ind][j + k][1], min(B + 1, DP[ind][j][1] + DP[con[ind][i]][k][1]));
                    DP[ind][j + k][0] = min(DP[ind][j + k][0], min(B + 1, DP[ind][j][0] + DP[con[ind][i]][k][0]));
                }
            }
            
            now += sz[con[ind][i]];
        }
    }
    
    for (int i = 0; i <= sz[ind]; i ++)
        DP[ind][i][1] = min(DP[ind][i][1], DP[ind][i][0]);
        
    vis[ind] = false;
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
    fastscan(B);

    int a, b, c;
    for (int i = 0; i < N; i ++) {
        if (i > 0) {
            fastscan(a);
            fastscan(b);
            fastscan(c);
            
            cost[i] = a;
            disc[i] = (a - b);
            
            con[i].push_back(c - 1);
            con[c - 1].push_back(i);
        }
        
        else {
            fastscan(a);
            fastscan(b);
            
            cost[i] = a;
            disc[i] = (a - b);
        }        
    }

    begin(0);
    
    for (int i = 0; i < MAX_N; i ++) {
        for (int j = 1; j <= sz[i]; j ++) {
            DP[i][j][0] = INF;
            DP[i][j][1] = INF;
        }
        
        DP[i][0][1] = INF;
    }
    
    DFS(0);

    for (int i = N; i >= 1; i --) {
        if (DP[0][i][1] <= B) {
            cout << i << endl;
            return (0);
        }
    } 
    
    cout << 0 << endl;
    return (0);
}