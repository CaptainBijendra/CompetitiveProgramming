#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int ar[100005], root[100005], index[100005], vis[100005], sz[100005];
int N, A;

void DFS (int ind) {
    vis[ind] = true;

    if (root[ind] >= 0) 
        return;
    
    if (ar[ind] == -1) {
        root[ind] = ind;
        sz[ind] = 0;
        return;
    }
    
    DFS (ar[ind]);
    root[ind] = root[ar[ind]];
    sz[ind] = sz[ar[ind]] + 1;
}

int abs(int a)  {
    if (a < 0) { return (-1 * a); }
    else { return (a); }
}

int main() {
    int ext = 0;
    
    cin >> N;
    ext = N;

    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        root[i] = -1;
        index[i] = 100005;
    }
    
    sz[100005] = 100005;
    
    for (int i = 0; i < N; i ++) {
        if (!vis[i]) { 
            DFS (i);
            vis[i] = false;
        }        
    }
    
    N = ext;

    for (int i = 0; i < N; i ++) {
        if (ar[i] >= 0 && !vis[i]) {
            if (sz[i] < sz[index[root[i]]])
                index[root[i]] = i;
        }
    }
    
    cin >> A;
    
    int v;
    for (int i = 0; i < A; i ++) {
        cin >> v;
        cout << index[root[v]] << endl;
    }   
}