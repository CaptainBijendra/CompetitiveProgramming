#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string.h>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

int A[MAX_N], B[MAX_N];
int T, N, X, Y;

int main() {
    cin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        cin >> N;
        
        int a, b;
        for (int i = 0; i < N - 1; i ++) {
            cin >> a >> b;
            con[a - 1].push_back(b - 1);
            con[b - 1].push_back(a - 1);
        }
        
        cin >> X;
        for (int i = 0; i < X; i ++)
            cin >> A[i];
        
        cin >> Y;
        for (int i = 0; i < Y; i ++)
            cin >> B[i];
        
        cout << B[0] << endl;
        
        
        DFS (B[0]);
        
        for (int i = 0; i < MAX_N; i ++)
            con[i].clear();
    }
}