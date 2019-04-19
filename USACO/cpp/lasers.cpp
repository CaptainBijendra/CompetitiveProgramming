#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_N 100005

using namespace std;

typedef pair<int, int> ii;
vector<ii> posts;

struct state { 
    int x, y, dist;
    bool dir;
}

bool vis[MAX_N];

int N, sx, sy, bx, by;

bool line (int a, int b, int x, int y, bool dir) {
    if (dir) { return (a == x); }
    else { return (b == y); }
}

int main() {
    ifstream fin ("lasers.in");
    ofstream fout ("lasers.out");
    
    fin >> N >> sx >> sy >> bx >> by;
    
    for (int i = 0; i < N; i ++) {
        int a, b;
        
        fin >> a >> b;
        points.push_back(ii(a, b));
    }
    
    state st1;
    st1.x = sx; st1.y = sy;
    st1.dist = 0; st1.dir = false;
    
    // Dir (false) = horizontal     

    state st2;
    st2.x = sx; st2.y = sy;
    st2.dist = 0; st2.dir = true;
    
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        
        if (line(cur.x, cur.y, bx, by, cur.dir)) {
            cout << cur.dist << endl;
            return (0);
        }
        
        for (int i = 0; i < N; i ++) {
            if (vis[i]) { continue; }
            if (line(cur.x, cur.y, posts[i].first, posts[i].second)) {
                vis[i] = true;
                
                state nxt;
                nxt.x = posts[i].first; nxt.y = posts[i].second;
                nxt.dir = !cur.dir;
                nxt.dist = cur.dist + 1;
                
                q.push(nxt);
            }
        }
    }
}