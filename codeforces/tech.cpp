#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <stdio.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];
vector<int> con2[MAX_N];

bool vis[MAX_N];
bool done;

int mark[MAX_N];
int N, M;

vector<int> scc;

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

void DFS (int ind) {
    vis[ind] = true;
    scc.push_back(ind);
    
    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]])
            DFS (con[ind][i]);
}

void isCycle(int ind) {
    mark[ind] = 1;

    for (int i = 0; i < con2[ind].size(); i ++) {
        if (mark[con2[ind][i]] == 1) {
            done = true;
            return;
        }

        if (mark[con2[ind][i]] == 0)
            isCycle(con2[ind][i]);
        
        if (done)
            return;
    }
    
    mark[ind] = 2;
}

int main() {
    fastscan(N);
    fastscan(M);
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        fastscan(a);
        fastscan(b);

        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
        con2[a - 1].push_back(b - 1);
    }
    
    int ans = 0;

    for (int i = 0; i < N; i ++) {
        if (!vis[i]) {
            DFS (i);
        
            done = false;
            
            for (int j = 0; j < scc.size(); j ++) {
                if (mark[scc[j]] == 0) {
                    isCycle(scc[j]);
                
                    if (done)
                        break;
                }
            }
            
            if (done)
                ans += scc.size();
            else
                ans += scc.size() - 1;
        
            scc.clear();
        }
    }
    
    cout << ans << endl;
    return (0);
}
