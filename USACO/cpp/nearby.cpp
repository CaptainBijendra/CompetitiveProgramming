#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int DP[MAX_N][21];
int N, K;

int main() {
    cin >> N >> K;

    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < N; i ++)
        cin >> DP[i][0];
    
    for (int i = 0; i < N; i ++) {
        DP[i][1] += DP[i][0];
        
        for (int j = 0; j < con[i].size(); j ++)
            DP[i][1] += DP[con[i][j]][0];
    }

    for (int i = 2; i <= K; i ++) {
        for (int j = 0; j < N; j ++) {
            for (int k = 0; k < con[j].size(); k ++) {
                DP[j][i] += DP[con[j][k]][i - 1];
                DP[j][i] -= DP[j][i - 2];
            }
        
            DP[j][i] += DP[j][i - 2];
        }
    }
        
    for (int i = 0; i < N; i ++) {
        cout << DP[i][K] << endl;
    }

    return (0);
}