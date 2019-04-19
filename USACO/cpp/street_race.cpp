#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 105
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];
vector<int> rcon[MAX_N];

int vis[MAX_N];
int N, T;

void DFS (int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]]) 
            DFS (con[ind][i]);        
}

void DFS2 (int ind) {
    vis[ind] = true;
    
    for (int i = 0; i < rcon[ind].size(); i ++) 
        if (!vis[rcon[ind][i]])
            DFS2 (rcon[ind][i]);
}

int main() {
    N = 0;
    
    int st;
    for (int i = 0; ; i ++) {
        cin >> st;
        
        if (st == -1)
            break;
        
        while (true) {
            if (st == -2)
                break;
        
            con[i].push_back(st);
            
            rcon[i].push_back(st);
            rcon[st].push_back(i);
            
            cin >> st;
        }
        
        N ++;
    }
    
    vector<int> subA;
    vector<int> subB;

    for (int i = 1; i < N; i ++) {
        for (int j = 0; j < N; j ++)
            vis[j] = false;
        
        vis[i] = true;
        DFS(0);    
    
        bool flag = true;
        for (int j = 0; j < N; j ++)
            if (!vis[j]) {
                flag = false;
                break;
            }
    
        if (!flag)
            subA.push_back(i);
            
        for (int j = 0; j < N; j ++)
            vis[j] = false;
        
        vis[i] = true;
        DFS2(0);

        if (con[i].size() == 0)
            continue;

        bool flag2 = true;
        bool flag3 = false;
        
        for (int j = 0; j < con[i].size(); j ++)
            if (con[i][j] == 0) {
                flag3 = true;
                break;
            }
        
        if (flag3)
            continue;
        
        for (int j = 0; j < N; j ++)
            if (!vis[j]) {
                flag2 = false;
                break;
            }
        
        if (!flag2)
            subB.push_back(i);
    }
    
    if (subA.size() == 0)
        cout << 0 << endl;
    else
        cout << subA.size() << " ";
    
    for (int i = 0; i < subA.size(); i ++) {
        if (i == subA.size() - 1)
            cout << subA[i] << endl;
        else
            cout << subA[i] << " ";
    }    
    
    if (subB.size() == 0)
        cout << 0 << endl;
    else
        cout << subB.size() << " ";
    
    for (int i = 0; i < subB.size(); i ++) {
        if (i == subB.size() - 1)
            cout << subB[i] << endl;
        else
            cout << subB[i] << " ";
    }
    
    return (0);    
}