#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define MAX_N 605
#define MAX_M 605

using namespace std;

typedef pair<int, int> ii;
vector<ii> p;

struct state { int x, y, dif; };

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool mark[MAX_N][MAX_M];

int grid[MAX_N][MAX_M];
int N, M;

int absol(int x) { return (x < 0 ? x * -1 : x); }
void BFS(int s_x, int s_y, int s_dif) {
    queue<state> q;
    
    state st;
    st.x = s_x; st.y = s_y; st.dif = s_dif;
    
    q.push(st);
    
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        
        mark[cur.x][cur.y] = true;

        cout << cur.x << " " << cur.y << endl;

        for (int i = 0; i < 4; i ++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!mark[nx][ny] && (absol(grid[cur.x][cur.y] - grid[nx][ny]) <= cur.dif)) {
                    state nxt;
                    nxt.x = nx; nxt.y = ny; nxt.dif = cur.dif;
                    
                    q.push(nxt);
                }
            }
        }
    }
}

int main() {
    ifstream fin ("ccski.in");
    ofstream fout ("ccski.out");

    fin >> N >> M;

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) { fin >> grid[i][j]; }    
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) { 
            bool pole;
            
            fin >> pole;
            if (pole) { p.push_back(ii(i, j)); }
        }
    }

    int low = 0, hi = 2000000000, mid = 0;

    while (low < hi) {
        for (int i = 0; i < MAX_N; i ++) {
            for (int j = 0; j < MAX_M; j ++) { mark[i][j] = false; }
        }
        
        
        mid = (low + hi) / 2;
        BFS(p[0].first, p[0].second, mid);
        
        bool flag = true;

        for (int i = 0; i < p.size(); i ++) {
            if (!mark[p[i].first][p[i].second]) { flag = false; }
            if (!flag) { break; }
        }

        if (flag) { hi = mid; }
        else { low = mid + 1; }
    }
    
    fout << hi << endl;
    return (0);
}
