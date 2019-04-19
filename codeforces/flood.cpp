#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 5005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> comp;

int ar[MAX_N], DP[MAX_N][MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    int cnter = 1;
    int col = ar[0];
    
    for (int i = 1; i < N; i ++) {
        if (ar[i] == ar[i - 1])
            cnter ++;
        else {
            comp.push_back(ii(cnter, col));
            cnter = 1;
            col = ar[i];
        }
    }
    
    comp.push_back(ii(cnter, col));
    
    for (int i = 0; i < MAX_N; i ++) 
        for (int j = 0; j < MAX_N; j ++) {
            if (i == j)
                continue;
                
            DP[i][j] = INF; 
        }
    
    N = comp.size();
    
    for (int len = 1; len <= N; len ++) {
        for (int i = 0; i < N; i ++) {
            int j = (i + len - 1);
            
            if (i > 0 && j < N && comp[i - 1].s == comp[j + 1].s)
                DP[i - 1][j + 1] = min(DP[i - 1][j + 1], DP[i][j] + 1);
            if (i > 0)
                DP[i - 1][j] = min(DP[i - 1][j], DP[i][j] + 1);
            if (j < N)
                DP[i][j + 1] = min(DP[i][j + 1], DP[i][j] + 1);
        }
    }
    
    cout << DP[0][N - 1] << endl;
    return (0);
}