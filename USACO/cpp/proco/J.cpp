#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N (1 << 18)

using namespace std;

int con[MAX_N][2];
int N, D;

int DFS (int ind, int depth, int sum) {
    if (depth == 0)
        return (1);
    if (sum > D)
        return (1);
    
    long long cur_sum = 0ll;
    
//    cout << ind << " " << depth << " " << sum << endl;
    
    for (int i = 0; i < depth; i ++) { //Length of path on left node
        int pos1 = DFS(2 * ind, i, sum + con[ind][0]);
        int pos2 = DFS(2 * ind + 1, depth - i - 1, sum + con[ind][1]);
        
        cur_sum += (pos1 * pos2);
    }
    
    return (cur_sum);
}

int main() {
    cin >> N >> D;
    
    for (int i = 2; i <= N; i ++) 
        cin >> con[i / 2][i % 2];
    
    long long sum = 0ll;
    
    for (int i = 1; i <= N; i ++) { //NODE
        for (int j = 1; j <= 2 * (log2(N) - log2(i)); j ++) { //LENGTH OF DEPTH
            cout << i << " " << j << endl;
            sum += DFS(i, j, 0);
        }
    }
    
    cout << DFS(1, 2, 0) << endl;
    
    cout << sum << endl;
    return (0);
}