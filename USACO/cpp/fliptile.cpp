#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_N 16
#define MAX_M 16

using namespace std;

struct state { bool move[MAX_N][MAX_M]; };

vector<state> ans;

bool st_grid[MAX_N][MAX_M];

bool grid[MAX_N][MAX_M];
bool mv[MAX_N][MAX_M];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, M;

bool cmp(state a, state b) {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            if (a.move[i][j] && !b.move[i][j]) { return (false); }
            else if (!a.move[i][j] && b.move[i][j]) { return (true); }
        }
    }

    return (true);
}

void flip(int x, int y) {                    
    if (grid[x][y]) { grid[x][y] = false; }
    else { grid[x][y] = true; }
}

void solve() {        
    for (int i = 0; i < M; i ++) {
        if (mv[0][i]) {
            flip(0, i);

            for (int j = 0; j < 4; j ++) {
                int nx = 0 + dx[j];
                int ny = i + dy[j];
                
                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    flip(nx, ny);
                }
            }
        }
    }

    for (int i = 1; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            if (grid[i - 1][j]) { 
                flip(i, j);
                mv[i][j] = true;

                for (int k = 0; k < 4; k ++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        flip(nx, ny);
                    }
                }
            }    
        }
    }
}

int main() {
    ifstream fin ("fliptile.in");
    ofstream fout ("fliptile.out");

    fin >> N >> M;

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            fin >> st_grid[i][j];
            mv[i][j] = false;
            grid[i][j] = st_grid[i][j];
        }
    }

    bool pos = false;

    for (int i = 0; i < (1 << M); i ++) {
        for (int j = 0; j < M; j ++) {
            if (((1 << j) & (i)) != 0) { mv[0][j] = true; }
        }

        solve();
        state n;

        bool sol = true;

        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                n.move[i][j] = mv[i][j];
               
                if (grid[i][j]) { 
                    sol = false;
                    break;
                }
            }    
 
            if (!sol) { break; }
        }
 
        if (sol) { 
            ans.push_back(n);
            pos = true;
        }

        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++) {
                mv[i][j] = false;
                grid[i][j] = st_grid[i][j];
            }
        }
    }

    if (!pos) {
        fout << "IMPOSSIBLE" << endl;
        return (0);
    }

    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            if (j == 0) { fout << ans[0].move[i][j]; }
            else { fout << " " << ans[0].move[i][j]; }
        }

        fout << endl;
    }

    return (0);
}
