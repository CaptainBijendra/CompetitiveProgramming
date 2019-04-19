#include <iostream>
#include <fstream>
#include <queue>

#define MAX_N 505
#define MAX_M 505
#define INF 2000000000

using namespace std;

struct state {
    int x, y, mv;
    bool grav;
};

queue<state> q;

int vis[MAX_N][MAX_M];
int N, M, cx, cy, bx, by;

char grid[MAX_N][MAX_M];

bool hitD;

state fall (state cur) {
    int add;
    
    if (cur.grav == false) { add = 1; }
    else { add = -1; }
    
    while (grid[cur.x + add][cur.y] == '.') {
        if (cur.x == bx && cur.y == by) {
            hitD = true;
            break;
        }
    
        cur.x += add;
    }
    
    if (cur.x <= 0 || cur.x >= N - 1) {
        cur.x = -1; cur.y = -1;
        return (cur);
    }
    
    state nMove;
    nMove.x = cur.x; nMove.y = cur.y;
    nMove.grav = cur.grav;
    nMove.mv = cur.mv;
    
    return (nMove);
}

int main() {
    ifstream fin ("gravity.in");
    ofstream fout ("gravity.out");

//    fin >> N >> M;
    cin >> N >> M;

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
//            fin >> grid[i][j];
            cin >> grid[i][j];

            if (grid[i][j] == 'C') {
                cx = i;
                cy = j;
                grid[i][j] = '.';
            }

            else if (grid[i][j] == 'D') {
                bx = i;
                by = j;
                grid[i][j] = '.';
            }

            vis[i][j] = INF;
        }
    }

    int ans = INF;

    hitD = false;

    state st;
    st.x = cx; st.y = cy; st.mv = 0;
    st.grav = false;
    
    vis[cx][cy] = INF;
    q.push(st);

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        state next = fall(cur);  
        
        if ((next.x == bx && next.y == by) || hitD) {
            ans = min(ans, next.mv);
            hitD = false;
            continue;
        }
        
        if (next.x == -1 && next.y == -1) { continue; }
        if (vis[next.x][next.y] <= next.mv) { continue; }
        vis[next.x][next.y] = next.mv;
        
        if (next.y + 1 < M && grid[next.x][next.y + 1] != '#') {
            next.y ++;
            q.push(next);
            next.y --;
        }
        
        if (next.y - 1 >= 0 && grid[next.x][next.y - 1] != '#') {
            next.y --;
            q.push(next);
            next.y ++;
        }
        
        next.grav = !next.grav;
        next.mv ++;
        q.push(next);
    }

    if (ans == INF) { cout << "-1" << endl; }
    else { cout << ans << endl; }
    
    return (0);
}
 