#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>

#define MAX_N 40
#define f first
#define s second

using namespace std;

map<string, bool> vis, vis2, vis3;
string ans;

int ar[MAX_N][MAX_N];
int N;

void DFS1 (int x, int y) {
    string tmp = ans;
    ans += ar[x][y];
    
    if (x + y == N - 1) {
        vis[ans] = true;
        ans = tmp;
        
        return;
    }
        
    DFS1 (x + 1, y);
    ans = tmp;
    ans += ar[x][y];

    DFS1 (x, y + 1);
    ans = tmp;
}

void DFS2 (int x, int y) {
    string tmp = ans;
    ans += ar[x][y];
        
    if (x == N - 1 && y == N - 1) {
        vis2[ans] = true;
        return;
    }
    
    if (x + 1 < N)
        DFS2 (x + 1, y);
    
    ans = tmp;
    ans += ar[x][y];
    if (y + 1 < N)
        DFS2 (x, y + 1);

    ans = tmp;
}

int main() {
    ifstream fin ("palpath.in");
    ofstream fout ("palpath.out");
    
    fin >> N;    

    string str;
    for (int i = 0; i < N; i ++) {
        fin >> str;
        
        for (int j = 0; j < N; j ++)
            ar[i][j] = str[j];
    }
    
    ans = "";
    DFS1 (0, 0);
    
    ans = "";
    for (int i = 0; i < N; i ++) {
        DFS2(i, N - 1 - i);
        ans = "";
    }
    
    int res = 0;
    
    map<string, bool>::iterator it;
    
    for (it = vis2.begin(); it != vis2.end(); it ++) {
        string cur = it->f;
        reverse(cur.begin(), cur.end());
        
        if (vis[cur])
            res ++;
    }
    
    fout << res << endl;
    return (0);        
}