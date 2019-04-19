#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 505
#define f first
#define s second

using namespace std;

vector<int> stack;

int con[MAX_N][MAX_N];

int vis[MAX_N];
int F;

void DFS (int ind) {
    for (int i = 0; i < 500; i ++) {
        if (con[ind][i]) {
            con[ind][i] --;
            con[i][ind] --;
            DFS (i);
        }
    }
    
    stack.push_back(ind);
}

int main() {
    cin >> F;
    
    bool edge_case = false;
    
    int a, b;
    for (int i = 0; i < F; i ++) {
        cin >> a >> b; O
    
        a %= 500;
        b %= 500;
    
        con[a][b] ++;
        con[b][a] ++;

        vis[a] = true;
        vis[b] = true;
    }
    
    for (int i = 0; i < 500; i ++) {
        if (vis[i]) {
            DFS (i);
            break;
        }
    }
    
    for (int i = stack.size() - 1; i >= 0; i --) {
        if (stack[i] == 0)
            cout << 500 << endl;
        else
            cout << stack[i] << endl;
    }

    return (0);
}