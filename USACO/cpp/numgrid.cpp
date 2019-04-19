#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

map<string, bool> pos;

int ar[10][10];
int N;

void DFS (int x, int y, string num) {
    if (num.size() == 6) {
        pos[num] = true;
        return;
    }
    
    string tmp = num;
    if (x + 1 < N)
        DFS (x + 1, y, num += (char)ar[x][y]);
        
    num = tmp;
    if (y + 1 < N)
        DFS (x, y + 1, num += (char)ar[x][y]);
    
    num = tmp;
    if (x - 1 >= 0)
        DFS (x - 1, y, num += (char)ar[x][y]);
    
    num = tmp;
    if (y - 1 >= 0)
        DFS (x, y - 1, num += (char)ar[x][y]);
}

int main() {
    N = 5;
    
    for (int i = 0; i < 5; i ++)
        for (int j = 0; j < 5; j ++) {
            cin >> ar[i][j];
            ar[i][j] += '0';
        }

    for (int i = 0; i < 5; i ++)
        for (int j = 0; j < 5; j ++) 
            DFS (i, j, "");

    int ans = 0;

    map<string, bool>::iterator it;
    for (it = pos.begin(); it != pos.end(); it++) {
        ans ++;
    }
    
    cout << ans << endl;
    return (0);
}