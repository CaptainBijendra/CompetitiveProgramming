#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

#define INF 200000000
#define MAX_R 55
#define MAX_C 55
#define MAX_N 18

using namespace std;

typedef pair<int, int> ii;

queue<ii> q;
vector<ii> border[MAX_N];

vector<int> ord;

char grid[MAX_R][MAX_C];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int dist[MAX_N][MAX_R][MAX_C];
int d[MAX_N][MAX_N];
int col[MAX_R][MAX_C];

int DP[(1 << MAX_N)][MAX_N];
int R, C;

void flood_fill (int a, int b, int c) {
    if (a < 0 || b < 0 || a >= R || b >= C) { return; }
    if (grid[a][b] != 'X') { return; }
    if (col[a][b]) { return; }
    col[a][b] = c;

    flood_fill(a + 1, b, c); flood_fill(a, b + 1, c);
    flood_fill(a - 1, b, c); flood_fill(a, b - 1, c);
}

int main() {
    ifstream fin ("island.in");
    ofstream fout ("island.out");

    fin >> R >> C;

    string ln;

    for (int i = 0; i < R; i ++) {
        fin >> ln;

        for (int j = 0; j < C; j ++) 
        { grid[i][j] = ln[j]; }
    }
        
    int c = 1;

    for (int i = 0; i < R; i ++) {
        for (int j = 0; j < C; j ++) {
            if (grid[i][j] == 'X' && !col[i][j]) 
            { flood_fill(i, j, c ++); }
        }
    }
    
    for (int i = 0; i < c; i ++) {
        for (int j = 0; j < R; j ++) {
            for (int k = 0; k < C; k ++) { dist[i][j][k] = INF; }
        }
    }

    for (int is = 0; is < c; is ++) {
        for (int i = 0; i < R; i ++) {
            for (int j = 0; j < C; j ++) {
                if ((grid[i][j] == 'S') &&
                    ((col[i + 1][j] == (is + 1) || col[i][j + 1] == (is + 1)) || 
                     (col[i - 1][j] == (is + 1) || col[i][j - 1] == (is + 1)))) {

                    border[is].push_back(ii(i, j));

                    ii start = ii(i, j);
                    q.push(start);
                    
                    dist[is][i][j] = 1;

                    while (!q.empty()) {
                        ii cur = q.front(); q.pop();

                        for (int k = 0; k < 4; k ++) { 
                            int nx = cur.first + dx[k];
                            int ny = cur.second + dy[k];

                            if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] == 'S') {
                                if (dist[is][nx][ny] > dist[is][cur.first][cur.second] + 1) {
                                    dist[is][nx][ny] = dist[is][cur.first][cur.second] + 1;
                                    q.push(ii(nx, ny));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < c; i ++) { for (int j = 0; j < c; j ++) { d[i][j] = INF; } }
    for (int i = 0; i < c; i ++) {
        for (int k = 0; k < c; k ++) {
            if (i == k) { continue; }

            for (int l = 0; l < border[k].size(); l ++) 
            { d[i][k] = min(d[i][k], dist[i][border[k][l].first][border[k][l].second]); }
        }
    }
    
    for (int i = 0; i < (1 << c); i ++) { 
        for (int j = 0; j < c; j ++) { DP[i][j] = INF; } 
    }

    for (int i = 0; i < (c - 1); i ++) { DP[(1 << i)][i] = 0; }

    for (int i = 0; i < (1 << (c - 1)); i ++) {
        for (int j = 0; j < (c - 1); j ++) 
        { if (i & (1 << j)) { ord.push_back(j); } }

        for (int j = 0; j < ord.size(); j ++) {
            if (DP[i][ord[j]] < INF) {
                for (int k = 0; k < ord.size(); k ++) { 
                    if (j == k) { continue; }
                    
                    DP[i | (1 << ord[k])][ord[k]] = min(DP[i | (1 << ord[k])][ord[k]], 
                                                        DP[i][ord[j]] + d[ord[j]][ord[k]]);
                }
            }
        }
            
        ord.clear();
    }
    
    int ans = INF;

    for (int i = 0; i < (1 << (c - 1))

    for (int i = 0; i < (c - 1); i ++) 
    { ans = min(ans, DP[(1 << (c - 1)) - 1][i]); }

    fout << ans << endl;
    return (0);
}