#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

string moves;
string ans;

int M;

void DFS (int ind, int x, int y, int x2, int y2, string str) {
    if (ind == 2 * M - 2) {
        ans = str;
        return;
    }
    
    if (moves[ind] == 'E' && x2 + 1 < M) {
        if (((x != x2 && y != y2) || (x + 1 != x2 + 1 && y != y2)) && x + 1 < M)
            DFS (ind + 1, x + 1, y, x2 + 1, y2, str + 'E');
        if (((x != x2 && y != y2) || (x != x2 + 1 && y + 1 != y2)) && y + 1 < M)
            DFS (ind + 1, x, y + 1, x2 + 1, y2, str + 'S');
    }
    
    else if (moves[ind] == 'S' && y2 + 1 < M) {
        if (((x != x2 && y != y2) || (x + 1 != x2 && y != y2 + 1)) && x + 1 < M)
            DFS (ind + 1, x + 1, y, x2, y2 + 1, str + 'E');
        if (((x != x2 && y != y2) || (x != x2 && y + 1 != y2 + 1)) && y + 1 < M)
            DFS (ind + 1, x, y + 1, x2, y2 + 1, str + 'S');
    }
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> M;
        cin >> moves;
        
        DFS (0, 0, 0, 0, 0, "");
        
        cout << ans << endl;
    }
    
    return (0);
}