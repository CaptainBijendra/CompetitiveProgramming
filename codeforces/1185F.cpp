#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <vector>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<int> con[MAX_N];

ii vis[MAX_N];

int frie[MAX_N], c[MAX_N], cst[MAX_N];
int N, M;

int main() {
    cin >> N >> M;
    
    int x, a;
    for (int i = 0; i < N; i ++) {
        cin >> x;
        
        for (int j = 0; j < x; j ++) {
            cin >> a;
            frie[i] += (1 << (a - 1));
        }
    }
    
    int big = 0;
    for (int i = 0; i < (1 << 9); i ++) {
        int cnt = 0;
        for (int j = 0; j < N; j ++) {
            if ((i & frie[j]) == frie[j])
                cnt ++;
        }
        
        con[cnt].push_back(i);
        big = max(big, cnt);
    }
    
    for (int i = 0; i < M; i ++) {
        cin >> c[i] >> x;
        
        for (int j = 0; j < x; j ++) { 
            cin >> a;
            cst[i] += (1 << (a - 1));
        }
        
        for (int j = 0; j < (1 << 9); j ++) {
            if ((j & cst[i]) == j) {
                if (vis[j].f == 0)
                    vis[j] = ii(c[i], i);
                else {
                    if (vis[j].f > c[i]) {
                        vis[j].f = c[i];
                        vis[j].s = i;
                    }
                }            
            }
        }
    }
    
    for (int ii = big; ii >= 0; ii --) {
        int ans = 2000000009;
        int ind1 = -1, ind2 = -1;

        for (int i = 0; i < con[ii].size(); i ++) {
            int cur = con[ii][i];
        
            for (int j = 0; j < M; j ++) {
                if (((cur & cst[j]) == cst[j]) && (vis[cur ^ cst[j]].f != 0) && ((c[j] + vis[cur ^ cst[j]].f) < ans)) {
                    ans = c[j] + vis[cur ^ cst[j]].f;
                    ind1 = j;
                    ind2 = vis[cur ^ cst[j]].s;
                }   
            }
        }
        
        if (ans != 2000000009) {
            if (ind2 == ind1) {
                ind2 = 0;
                ind2 += (ind1 == ind2);
                
                for (int j = 0; j < M; j ++) {
                    if (c[j] < c[ind2] && j != ind1) 
                        ind2 = j;
                }
            }
            
            cout << (ind1 + 1) << " " << (ind2 + 1) << endl;
            break;
        }
    }
    
    return (0);
}