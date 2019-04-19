#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <string.h>
#include <math.h>

#define INF 2000009
#define MAX_N 255
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

deque<ii> nxt;

ii cow[MAX_N];
ii center;

int DP[MAX_N][MAX_N];
int N;

bool cmp(ii a, ii b)
{
    if (a.f - center.f >= 0 && b.f - center.f < 0)
        return true;
    if (a.f - center.f < 0 && b.f - center.f >= 0)
        return false;
    if (a.f - center.f == 0 && b.f - center.f == 0) {
        if (a.s - center.s >= 0 || b.s - center.s >= 0)
            return a.s > b.s;
        return b.s > a.s;
    }

    // compute the cross product of vectors (center -> a) x (center -> b)
    int det = (a.f - center.f) * (b.s - center.s) - (b.f - center.f) * (a.s - center.s);
    if (det < 0)
        return true;
    else
        return false;
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> cow[i].f >> cow[i].s;
        nxt.push_back(cow[i]);
    }
    
    int ans = 0;
    
    for (int ii = 0; ii < N; ii ++) {
        center = cow[ii];
        sort(nxt.begin(), nxt.end(), cmp);

        for (int i = 0; i < N; i ++)
            if (nxt[i].f == center.f && nxt[i].s == center.s)
                nxt.erase(nxt.begin() + i);
        
        nxt.push_front(center);

        for (int i = 0; i < MAX_N; i ++)
            for (int j = 0; j < MAX_N; j ++)
                DP[i][j] = -INF;
        
        for (int i = 0; i < N; i ++)
            DP[0][i] = 2;
        
        DP[0][0] = -INF;
        
        for (int i = 0; i < N; i ++) { //Previous
            for (int j = i + 1; j < N; j ++) { //Current Point
                center = nxt[j];

                for (int k = j + 1; k < N; k ++) { //Next Point
                    if (cmp(nxt[i], nxt[k]))
                        DP[j][k] = max(DP[j][k], DP[i][j] + 1);
                }
            }
        }
        
        for (int i = 1; i < N; i ++) {
            for (int j = 1; j < N; j ++) {
                center = nxt[j];
                
                if (cmp(nxt[i], nxt[0])) {
                    ans = max(ans, DP[i][j]);
                
                    if (DP[i][j] == 8) {
                        cout << "___________" << endl;
                        
                        for (int k = 0; k < N; k ++)
                            cout << nxt[k].f << " " << nxt[k].s << endl;
                        
                        cout << nxt[i].f << " " << nxt[i].s << " " << nxt[j].f << " " << nxt[j].s << " " << nxt[0].f << " " << nxt[0].s << endl;
                        cout << DP[3][4] << endl;
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    return (0);
}