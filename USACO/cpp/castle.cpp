#include <iostream>
#include <fstream>
#include <map>

#define MAX_N 55
#define MAX_M 55

using namespace std;

struct cell { bool S, E, N, W; };

cell grid[MAX_N][MAX_M];

map<int, int> sz;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int color[MAX_N][MAX_M];
int N, M;

cell calc (int val) { 
    cell nxt;
    nxt.S = false; nxt.E = false; nxt.N = false; nxt.W = false;
     
    if (val - 8 >= 0) { nxt.S = true; val -= 8; }
    if (val - 4 >= 0) { nxt.E = true; val -= 4; }
    if (val - 2 >= 0) { nxt.N = true; val -= 2; }
    if (val - 1 >= 0) { nxt.W = true; val -= 1; }
    
    return (nxt);
}    

void flood (int x, int y, int c) {
    color[x][y] = c;
    
    for (int i = 0; i < 4; i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        bool flag = false;
        
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (color[nx][ny] == 0) {
                if (i == 0 && !grid[x][y].S) { flag = true; }
                else if (i == 1 && !grid[x][y].E) { flag = true; }
                else if (i == 2 && !grid[x][y].N) { flag = true; }
                else if (i == 3 && !grid[x][y].W) { flag = true; }
                
                if (flag) { flood(nx, ny, c); }
            }
        }
    }
}

int main() {
    ifstream fin ("castle.in");
    ofstream fout ("castle.out");
    
    fin >> M >> N;
    
    int v;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            fin >> v;
            
            grid[i][j] = calc(v);
        }
    }
    
    int col = 0;
    int ans1 = 1;
    int ans2 = 1;

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            if (!color[i][j]) {
                col ++;
                sz[col] ++;
                
                flood(i, j, col);
            }

            else { 
                sz[color[i][j]] ++;
                ans1 = max(ans1, sz[color[i][j]]);
            }
        }
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cout << color[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            for (int k = 0; k < 4; k ++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (color[nx][ny] != color[i][j]) {
                        ans2 = max(ans2, sz[color[i][j]] + sz[color[nx][ny]]);
                    }
                }
            }
        }
    }

    fout << col << endl;
    fout << ans1 << endl;
    fout << ans2 << endl;    
    
    return (0);
}