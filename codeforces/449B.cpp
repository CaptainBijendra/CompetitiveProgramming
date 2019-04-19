#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

vector<int> con[MAX_N];

int main() {
    cin >> N >> M >> K;
    
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    int cur = 0;
    vis[cur] = true;
    
    
    
    
    return (0);
}