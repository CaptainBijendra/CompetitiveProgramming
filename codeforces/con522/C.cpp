#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>   
#include <vector>
#include <map>
#include <set>
#include <iomanip>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int ar[MAX_N], DP[MAX_N][6];
int N, M;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];

    for (int i = 1; i <= 5; i ++) 
        DP[0][i] = -1;

    for (int i = 1; i < N; i ++) {
        for (int j = 1; j <= 5; j ++) {
            if (DP[i - 1][j]) {
                if (ar[i] > ar[i - 1]) {
                    for (int k = j + 1; k <= 5; k ++)
                        DP[i][k] = j;
                }
                
                else if (ar[i] < ar[i - 1]) {
                    for (int k = 1; k < j; k ++)
                        DP[i][k] = j;
                }
                
                else {
                    for (int k = 1; k <= 5; k ++)
                        if (k != j)
                            DP[i][k] = j;
                }
            }
        }
    }
    
    vector<int> sol;
    
    int cur = -1;
    for (int j = 1; j <= 5; j ++)
        if (DP[N - 1][j]) {
            sol.push_back(j);
            cur = j;
            
            break;
        }
    
    if (cur == -1) {
        cout << "-1" << endl;
        return (0);
    }
    
    for (int i = N - 1; i > 0; i --) {
        cur = DP[i][cur];
        sol.push_back(cur);
    }
    
    reverse(sol.begin(), sol.end());
    
    bool flag = true;
    for (int i = 0; i < sol.size() - 1; i ++) {
        if (ar[i] > ar[i + 1] && sol[i] > sol[i + 1])
            continue;
        
        if (ar[i] < ar[i + 1] && sol[i] < sol[i + 1])
            continue;
        
        if (ar[i] == ar[i + 1] && sol[i] != sol[i + 1])
            continue;
        
        flag = false;
        break;
    }
    
    if (!flag) {
        cout << "-1" << endl;
        return (0);
    }
    
    cout << sol[0];
    for (int i = 1; i < sol.size(); i ++)
        cout << " " << sol[i];
    
    cout << endl;
    return (0);
}