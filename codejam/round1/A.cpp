#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int R, C;

struct state {
    vector<int> x;
    vector<int> y;
    bool vis[6][6];
};

int main() {
    int T;
    cin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        state def;
        cin >> R >> C;
        
        for (int i = 0; i < R; i ++)
            for (int j = 0; j < C; j ++)
                def.vis[i][j] = false;
        
        queue<state> q;
        
        for (int i = 0; i <= 0; i ++) {
            for (int j = 0; j <= 0; j ++) {
                def.vis[i][j] = true;
                def.x.push_back(i); def.y.push_back(j);
                q.push(def);
                def.x.pop_back(); def.y.pop_back();
                def.vis[i][j] = false;
            }
        }
        
        bool flag2 = false;
    
            
            pair<int, int> loc = make_pair(cur.x[cur.x.size() - 1], cur.y[cur.y.size() - 1]);
        
            for (int i = 0; i < R; i ++) {
                for (int j = 0; j < C; j ++) {
                    if (!(loc.f == i || loc.s == j || loc.f - loc.s == i - j || loc.f + loc.s == i + j) && !cur.vis[i][j]) {
                        cur.x.push_back(i); cur.y.push_back(j);
                        cur.vis[i][j] = true;
                        q.push(cur);
                        cur.x.pop_back(); cur.y.pop_back();
                        cur.vis[i][j] = false;
                    }
                }
            }
            
            bool flag = true;
            
            for (int i = 0; i < R; i ++)
                for (int j = 0; j < C; j ++)
                    if (!cur.vis[i][j]) {
                        flag = false;
                        break;
                    }
        
            if (flag) {
                cout << "Case #" << (ii + 1) << ": POSSIBLE" << endl;
                
                for (int i = 0; i < cur.x.size(); i ++)
                    cout << (cur.x[i] + 1) << " " << (cur.y[i] + 1) << endl;
                
                flag2 = true;
                break;
            }
        }
        
        if (flag2)
            continue;
        
        cout << "Case #" << (ii + 1) << ": IMPOSSIBLE" << endl;
    }

    return (0);
}