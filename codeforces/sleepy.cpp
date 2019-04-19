#include <iostream>
#include <fstream>
#include <vector>

#define MAX_N 100005

using namespace std;

bool vis[MAX_N][2];

vector<int> con[MAX_N];

int DP[MAX_N][2];
int N, M, S;

// 1 = DRAW
// 2 = Petya wins
// 3 = Vasya wins

int DFS (int ind, bool turn) {
    if (DP[ind][turn]) { return (DP[ind][turn]); }
    if (vis[ind][turn]) { return (1); }

    for (int i = 0; i < con[ind].size(); i ++) {
        int a = DFS(con[ind][i], !turn);
        
        if (turn) { 
            if (a == 2)
            { return (DP[ind][turn] = 2); }
        }
        
        else {
            if (a == 3) 
            { return (DP[ind][turn] = 3); }
        }
    }
    
    return (turn == 1 ? 3 : 2);
}

int main() {
    ifstream fin ("sleepy.in");
    ofstream fout ("sleepy.out");
    
    fin >> N >> M;
    
    int a, b;
    
    for (int i = 0; i < N; i ++) {
        fin >> a;
        
        for (int j = 0; j < a; j ++)
        { fin >> b; con[i].push_back(b - 1); }
    }
    
    fin >> S;
    
    int state = DFS (S, true);
    
    if (state == 1) { fout << "Draw" << endl; }
    else if (state == 2) { fout << "Win" << endl; }
    else { fout << "Lose" << endl; }
    
    return (0);
}