#include <iostream>
#include <algorithm>

#define MAX_N 10
#define f first
#define s second

using namespace std;

int C[MAX_N];
int N, M, pos;

void DFS (int ind, int sum) {
    if (sum == N)
        pos ++;
    
    if (sum >= N)
        return;
    
    if (ind == M)
        return;
    
    for (int i = 0; ; i ++) {
        if (sum + i * C[ind] > N)
            break;
        
        DFS (ind + 1, sum + i * C[ind]);
    }
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < M; i ++)
        cin >> C[i];
    
    pos = 0;
    DFS(0, 0);
    
    cout << pos << endl;
    return (0);
}