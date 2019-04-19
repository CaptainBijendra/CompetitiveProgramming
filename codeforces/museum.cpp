#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 100005
#define MAX_D 55
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool mat[MAX_N][MAX_D];

int DP[MAX_N][MAX_D];
int N, M, D;

int DFS (int ind, int day) {
    if (DP[ind][day])
        return (DP[ind][day]);
        
    if (day > D)
        return (0);
    
    for (int i = 0; i < con[ind].size(); i ++) {
        DP[ind][day] = max(DP[ind][day], DFS(con[ind][i], day + 1) + mat[ind][day]);
    }
    
    return (DP[ind][day]);
}

int main() {
    cin >> N >> M >> D;
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        a --; b --;
        
        con[a].push_back(b);
    }
    
    string str;
    for (int i = 0; i < N; i ++) {
        cin >> str;
    
        for (int j = 0; j < D; j ++)
            mat[i][j] = (str[j] == '1');
    }
    
    DFS (0, 0);
    
    cout << DP[0][0] << endl;
    return (0);
}