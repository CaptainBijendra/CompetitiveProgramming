#include <bits/stdc++.h> 

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

int val[MAX_N], lca[MAX_N][23], d[MAX_N];
int N, K;

void DFS (int ind, int prev) {
    vis[ind] = true;
    
    lca[ind][0] = ind;
    lca[ind][1] = prev;
    
    d[ind] = d[prev] + 1;
    
    for (int i = 2; i < 23; i ++)
        lca[ind][i] = lca[lca[ind][i - 1]][i - 1];
    
    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]])
            DFS (con[ind][i], ind);
            
    vis[ind] = false;
}

int LCA (int a) {
    if (vis[a])
        return (0);
    
    int cur = a;
    
    for (int i = 22; i >= 0; i --) {
        if (!vis[lca[cur][i]])
            cur = lca[cur][i];
    }
    
    return (d[a] - d[cur] + 1);
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
    fastscan(K);
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        fastscan(a);
        fastscan(b);
        
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    DFS (N - 1, N - 1);
    
    vector<int> rem;
    vis[N - 1] = true;
    
    int cur = 1;
    for (int i = N - 2; i >= 0; i --) {
        int req = LCA(i);
        
        if (cur + req <= (N - K)) {
            cur += req;
            vis[i] = true;
            
            int rekt = lca[i][1];
            
            while (!vis[rekt]) {
                vis[rekt] = true;
                rekt = lca[rekt][1];
            }
        }
        
        else {
            rem.push_back(i);
        }
    }
    
    for (int i = rem.size() - 1; i >= 0; i --) {
        if (!vis[rem[i]])
            cout << (rem[i] + 1) << " ";
    }

    cout << endl;
    return (0);
}