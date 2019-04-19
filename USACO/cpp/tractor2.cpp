#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 505

using namespace std;

bool vis[MAX_N][MAX_N];
bool sol = false;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int grid[MAX_N][MAX_N];
int N, min_req;

int flood(int x, int y, int max_dif) {
    if (vis[x][y]) { return (0); }
    vis[x][y] = true;
         
    int ans = 1;

    for (int i = 0; i < 4; i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (max_dif >= abs(grid[nx][ny] - grid[x][y])) {
                ans += flood(nx, ny, max_dif);    
            }
        }
    }    

    return (ans);
}   

bool pos (int d) {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            vis[i][j] = false;
        }
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (!vis[i][j]) {
                if (flood(i, j, d) >= min_req) {
                    return (true);
                }
            }
        }
    }

    return (false);
}

int main() {
    ifstream fin ("tractor2.in");
    ofstream fout ("tractor2.out");

    fin >> N;
    min_req = ((N * N) % 2 == 0 ? (N * N) / 2 : (N * N) / 2 + 1);

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            fin >> grid[i][j];
        }
    }

    int hi = 10000000, low = 0;
    int mid;

    while (low < hi) {
        mid = (low + hi) / 2;

        if (pos(mid)) { hi = mid; }
        else { low = mid + 1; }
    }
    
    fout << low << endl;
    return (0);
}
