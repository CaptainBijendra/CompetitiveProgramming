#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <vector>

#define MAX_N 300005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<int> con[MAX_N];

map<ii, int> con2;

int ar[MAX_N], vis[MAX_N];
int N, M;

int main() {
    cin >> N >> M;
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
    
        con[a].push_back(b);
        con[b].push_back(a);
        con2[ii(min(a, b), max(a, b))] ++;
    }
    
    vis[0] = 1;
    for (int i = 1; i < MAX_N; i ++)
        vis[con[i].size()] ++;

    for (int i = 1; i < MAX_N; i ++)  {      
        for (int j = 0; j < con[i].size(); j ++) {
            if (con[i].size() + con[con[i][j]].size() - con2[ii(min(i, con[i][j]), max(i, con[i][j]))] == M) {
                cout << "YES" << endl;
                return (0);
            }
            
            vis[con[con[i][j]].size()] --;
        }
        
        vis[con[i].size()] --;
        
        if (vis[M - con[i].size()] > 0) {
            cout << "YES" << endl;
            return (0);
        }
    
        vis[con[i].size()] ++;
        for (int j = 0; j < con[i].size(); j ++) {
            vis[con[con[i][j]].size()] ++;
        }
    }
    
    cout << "NO" << endl;
    return (0);
}