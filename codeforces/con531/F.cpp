#include <iostream>
#include <vector>
#include <queue>

#define INF 2000000009
#define MAX_M 10005
#define MAX_N 17
#define f first
#define s second

using namespace std;

int DP[(1 << MAX_N)][MAX_N][MAX_N], ar[MAX_N][MAX_M], calc[MAX_N][MAX_N];
int N, M;

int abs(int a) {
    return (a < 0 ? -a : a);
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++)
            cin >> ar[i][j];
    }
    
    for (int i = 0; i < N; i ++) 
        DP[(1 << i)][i][i] = INF;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (i == j)
                continue;
                
            calc[i][j] = INF;
            for (int k = 0; k < M; k ++)
                calc[i][j] = min(calc[i][j], abs(ar[i][k] - ar[j][k]));
        }
    }

    for (int i = 1; i < (1 << N); i ++) {
        vector<int> sol;
        
        for (int j = 0; j < N; j ++) 
            if (i & (1 << j)) 
                sol.push_back(j);
            
        for (int j = 0; j < sol.size(); j ++) {
            for (int k = 0; k < sol.size(); k ++) {
                if (j == k)
                    continue;
                    
                int ans = calc[sol[j]][sol[k]];
                
                for (int l = 0; l < N; l ++) 
                    DP[i][sol[k]][l] = max(DP[i][sol[k]][l], min(DP[i ^ (1 << sol[k])][sol[j]][l], ans));
            }
        }   
        
        sol.clear();
    }
    
    int ans = 0;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) { 
            int small = DP[(1 << N) - 1][i][j];
        
            for (int k = 0; k < M - 1; k ++) {
                small = min(small, abs(ar[i][k] - ar[j][k + 1]));
            }
            
            ans = max(ans, small);
        }           
    }
    
    cout << ans << endl;      
    return (0);    
}