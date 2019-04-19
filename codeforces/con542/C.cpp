#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 55
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

bool ar[MAX_N][MAX_N];

int DP[MAX_N][MAX_N];
int N, M;

struct state {
    int x, y, tunnel, cost;  
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int sq(int x) {
    return (x * x);
}

int main() {
    cin >> N;
    
    int x, y, a, b;
    
    cin >> x >> y;
    cin >> a >> b;
    x --; y --;
    a --; b --;
    
    string str;
    for (int i = 0; i < N; i ++) {
        cin >> str;
        
        for (int j = 0; j < N; j ++) {
            ar[i][j] = (str[j] == '1');
            DP[i][j] = INF;
        }        
    }

    DP[x][y] = 0;

    state start;
    start.x = x;
    start.y = y;
    start.tunnel = 0;
    start.cost = 0;
    
    queue<state> q;
    q.push(start);
    
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        
        state nxt;
        for (int i = 0; i < 4; i ++) {
            int nx = cur.x + dx[i];
            int ny = cur.x + dy[i];
            
            if (!cur.tunnel) {
                for (int j = 0; j < N; j ++) {
                    for (int k = 0; k < N; k ++) {
                        nx = j;
                        ny = k;
                        
                        if (cur.x == j && cur.y == k)
                            continue;
                            
                        if (ar[j][k])
                            continue;
                        
                        if (DP[nx][ny] > sq(cur.x - nx) + sq(cur.y - ny)) {
                            DP[nx][ny] = sq(cur.x - nx) + sq(cur.y - ny);
                            nxt.x = nx;
                            nxt.y = ny;
                            nxt.tunnel = 1;
                            nxt.cost = DP[nx][ny];
                        
                            q.push(nxt);
                        }   
                    }
                }
            }
        
            nx = cur.x + dx[i];
            ny = cur.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || ar[nx][ny])
                continue;
            
            if (DP[nx][ny] > cur.cost) {
                DP[nx][ny] = cur.cost;
                nxt.x = nx;
                nxt.y = ny;
                
                nxt.tunnel = cur.tunnel;
                nxt.cost = cur.cost;
                
                q.push(nxt);
            }
        }
    }
    
    cout << DP[a][b] << endl;
    return (0);
}