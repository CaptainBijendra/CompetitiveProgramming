#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

struct state {
    int x, y;
    int moves;
    
    bool vis[31][31];
};

bool vis[31][31];

int ar[31][31], DP[31][31];
int N, M, small, ex, ey;

int dx[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };

void DFS (int x, int y, int moves) {
    if (x == ex && y == ey) {
        small = min(small, moves);
        return;
    }
    
    vis[x][y] = true;
    
    if (x + 1 < N && y + 2 < M && !vis[x + 1][y + 2])
        DFS (x + 1, y + 2, moves + (ar[x + 1][y + 2] != 1));

    if (x + 1 < N && y - 2 >= 0 && !vis[x + 1][y - 2])
        DFS (x + 1, y - 2, moves + (ar[x + 1][y - 2] != 1));
        
    if (x - 1 >= 0 && y + 2 < M && !vis[x - 1][y + 2])
        DFS (x - 1, y + 2, moves + (ar[x - 1][y + 2] != 1));
    
    if (x - 1 >= 0 && y - 2 >= 0 && !vis[x - 1][y - 2])
        DFS (x - 1, y - 2, moves + (ar[x - 1][y - 2] != 1));
    
    if (x + 2 < N && y + 1 < M && !vis[x + 2][y + 1])
        DFS (x + 2, y + 1, moves + (ar[x + 2][y + 1] != 1));

    if (x + 2 < N && y - 1 >= 0 && !vis[x + 2][y - 1])
        DFS (x + 2, y - 1, moves + (ar[x + 2][y - 1] != 1));
        
    if (x - 2 >= 0 && y + 1 < M && !vis[x - 2][y + 1])
        DFS (x - 2, y + 1, moves + (ar[x - 2][y + 1] != 1));
    
    if (x - 2 >= 0 && y - 1 >= 0 && !vis[x - 2][y - 1])
        DFS (x - 2, y - 1, moves + (ar[x - 2][y - 1] != 1));
}

int main() {
    cin >> N >> M;
    
    int sx, sy;

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cin >> ar[i][j];
            
            if (ar[i][j] == 3) {
                sx = i;
                sy = j;
            }
            
            if (ar[i][j] == 4) {
                ex = i;
                ey = j;
            }
            
            if (ar[i][j] == 2) {
                vis[i][j] = true;
            }
        }
    }
    
    small = 30 * 30;
    DFS (sx, sy, 0);
    
    state start;
    start.x = sx;
    start.y = sy;
    start.moves = 0;
    
    for (int i = 0; i < 31; i ++)
        for (int j = 0; j < 31; j ++)
            start.vis[i][j] = false;
    
    start.vis[sx][sy] = true;
    
    queue<state> q;
    q.push(start);
    
    int ans = 0;
    
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
    
        if (cur.moves == small) {
            if (cur.x == ex && cur.y == ey) {
                ans ++;
            }
            
            continue;
        }
        
        for (int i = 0; i < 8; i ++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && !cur.vis[nx][ny] && (ar[nx][ny] != 2)) {
                state nxt = cur;
                nxt.x = nx;
                nxt.y = ny;
                nxt.moves = cur.moves + (ar[nx][ny] != 1);
                
                nxt.vis[nx][ny] = true;
                
                q.push(nxt);
            }
        }
    }
        
    cout << small - 1 << '\n' << ans << endl;
    return (0);
}