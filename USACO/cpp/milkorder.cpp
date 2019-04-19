#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];
vector<int> ar[MAX_N];

vector<int> stck;

int vis[MAX_N];
int N, M;

bool DFS (int ind) {
    if (vis[ind])
        return (true);
    
    vis[ind] = true;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        bool a = DFS(con[ind][i]);
        
        if (a)
            return (true);
    }
    
    return (false);
}

bool pos(int x) {
    for (int i = 0; i <= x; i ++)
        con[i].clear();
    
    for (int i = 0; i < N; i ++)
        vis[i] = false;
    
    for (int i = 0; i <= x; i ++) 
        for (int j = 1; j < ar[i].size(); j ++) 
            con[ar[i][j]].push_back(ar[i][j - 1]);

    for (int i = 0; i < N; i ++) {
        if (!vis[i]) {
            bool a = DFS(i);
            
            if (a)
                return (false);
        }
    }
    
    return (true);
}

void topo(int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]])
            topo(con[ind][i]);
    
    stck.push_back(ind);
}

int main() {
    ifstream fin ("milkorder.in");  
    ofstream fout ("milkorder.out");
    
    fin >> N >> M;
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        fin >> a;
        
        for (int j = 0; j < a; j ++) {
            fin >> b;
            ar[i].push_back(b - 1);
        }
    }
    
    int low = 0;
    int hi = N - 1;
    
    while (low < hi) {
        int mid = (low + hi) / 2;
        
        if (pos(mid))
            low = mid + 1;
        else
            hi = mid;
    }

    if (!pos(low))
        low --;
        
    low ++;
    
    for (int i = 0; i < N; i ++)
        con[i].clear();
    
    for (int i = 0; i < low; i ++) 
        for (int j = 1; j < ar[i].size(); j ++) 
            con[ar[i][j]].push_back(ar[i][j - 1]);

    for (int i = 0; i < N; i ++) {
        sort(con[i].begin(), con[i].end());
        reverse(con[i].begin(), con[i].end());
        
        vis[i] = false;
    }
    
    for (int i = 0; i < N; i ++)
        if (!vis[i])
            topo(i);
    
    for (int i = 0; i < stck.size(); i ++)
        fout << (stck[i] + 1) << " ";
    
    fout << endl;
    return (0);
}