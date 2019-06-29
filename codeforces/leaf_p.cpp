#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int DP[MAX_N][2];
int N;

void DFS (int ind) {
    DP[ind][0] = 1;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        DFS (con[ind][i]);    
        DP[ind][0] *= DP[con[ind][i]][0];
    }
}

int main() {
    cin >> N;
    
    int x;
    for (int i = 0; i < N; i ++) {
        cin >> x;
        con[x - 1].push_back(i + 1);
    }
    
    DFS (0);
    
    cout << (DP[0][0] + DP[0][1]) << endl;
    return (0);
}