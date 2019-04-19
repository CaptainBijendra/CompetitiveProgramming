#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 20
#define f firsth
#define s second

using namespace std;

int loc[MAX_N];
int N;

int DFS (int row, int col) {
    for (int i = 0; i < row - 1; i ++) 
        if (abs(loc[row - 1] - loc[i]) == row - 1 - i || loc[row - 1] == loc[i])
            return (0);
            
    if (row == N)
        return (1);
    
    int sum = 0;
    
    for (int i = 0; i < N; i ++) {
        if (i == col)
            continue;
        
        if (i == col + 1 || i == col - 1)
            continue;
        
        loc[row] = i;
        sum += DFS (row + 1, i);
        loc[row] = -1;
    }
    
    return (sum);
}

int main() {
    cin >> N;

    cout << DFS(0, -5) << endl;
    return (0);
}