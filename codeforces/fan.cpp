#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 205
#define ROUNDS 6
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int DP[2 * MAX_N][2 * MAX_N][ROUNDS];
int N;

bool cmp(ii a, ii b) {
    if (a.f > a.s && b.f < b.s) { return (true); }
    return (false);
}

void test(int a, int b, int x, int y) {
    vector<ii> sol;
    
    for (int it = (x + y); it >= 1; it --) {
        int mx = (it == 5 ? 15 : 25);
        
        bool flag = false;
        
        for (int i = mx; i <= 200; i ++) {
            if (a >= i && b >= (i - 2) && DP[a - i][b - (i - 2)][it - 1] + 1 == DP[a][b][it]) {
                sol.push_back(ii(i, i - 2));
                
                a -= i;
                b -= (i - 2);
                
                flag = true;
                break;
            }
            
            if (a >= (i - 2) && b >= i && DP[a - (i - 2)][b - i][it - 1] - 1 == DP[a][b][it]) {
                sol.push_back(ii(i - 2, i));
                
                a -= (i - 2);
                b -= i;
                
                flag = true;
                break;
            }
        }
        
        if (flag)
            continue;
        
        for (int i = 0; i <= mx - 2; i ++) {
            if (a >= mx && b >= i && DP[a - mx][b - i][it - 1] + 1 == DP[a][b][it]) {
                sol.push_back(ii(mx, i));
                
                a -= mx;
                b -= i;
                
                flag = true;
                break;
            }
            
            if (a >= i && b >= mx && DP[a - i][b - mx][it - 1] - 1 == DP[a][b][it]) {
                sol.push_back(ii(i, mx));
                
                a -= i;
                b -= mx;
                
                flag = true;
                break;
            }
        }
        
        if (flag)
            continue;
    }
    
    reverse(sol.begin(), sol.end());
    sort (sol.begin(), sol.begin() + min((int)sol.size(), 4), cmp);
    
    for (int i = 0; i < 3; i ++) {
        if (sol[i].f > sol[i].s && sol[i + 1].f < sol[i + 1].s) {
            ii a = sol[i];
            sol[i] = sol[i + 1];
            sol[i + 1] = a;
            
            break;
        }
    }
    
    for (int i = 0; i < sol.size(); i ++)
        cout << sol[i].f << ":" << sol[i].s << " ";
        
    cout << endl;
}

int main() {
    cin >> N;
    
    for (int ii = 0; ii < ROUNDS; ii ++) 
        for (int i = 0; i < MAX_N; i ++) 
            for (int j = 0; j < MAX_N; j ++) 
                DP[i][j][ii] = -INF;
    
    DP[0][0][0] = 0;
    
    for (int ii = 1; ii < ROUNDS; ii ++) {
        for (int i = 0; i < MAX_N; i ++) {
            for (int j = 0; j < MAX_N; j ++) {
                int mx = (ii == 5 ? 15 : 25);
                
                for (int k = mx; k <= 200; k ++) {
                    DP[i + k][j + (k - 2)][ii] = max(DP[i + k][j + (k - 2)][ii], DP[i][j][ii - 1] + 1);
                    DP[i + (k - 2)][j + k][ii] = max(DP[i + (k - 2)][j + k][ii], DP[i][j][ii - 1] - 1);
                }
                
                for (int k = 0; k <= mx - 2; k ++) {
                    DP[i + mx][j + k][ii] = max(DP[i + mx][j + k][ii], DP[i][j][ii - 1] + 1);
                    DP[i + k][j + mx][ii] = max(DP[i + k][j + mx][ii], DP[i][j][ii - 1] - 1);
                }
            }    
        }
    }
    
    int a, b, x = 0, y = 0;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
    
        int r = 0;
            
        for (int i = 3; i < ROUNDS; i ++) 
            if (DP[a][b][i] >= DP[a][b][r]) 
                r = i;
    
        y = ((r - DP[a][b][r]) / 2);
        x = (r - y);
    
        while (max(x, y) > 3) {
            r --;
            y = ((r - DP[a][b][r]) / 2);
            x = (r - y);
        }
        
        if (max(x, y) < 3) {
            r ++;
            y = ((r - DP[a][b][r]) / 2);
            x = (r - y);    
        }
        
        if (max(x, y) < 3) {
            r ++;
            y = ((r - DP[a][b][r]) / 2);
            x = (r - y);
        }
    
        if (x < 0 || y < 0 || r < 3 || (max(x, y) < 3))
            cout << "Impossible" << endl;
        else {
            cout << x << ":" << y << endl;
            test(a, b, x, y);
        }
    }
    
    return (0);    
}