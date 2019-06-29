#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>   
#include <vector>
#include <map>
#include <set>
#include <iomanip>

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

bool vis[2 * MAX_N];

int N, X;

int main() {
    cin >> N >> X;
    vis[0] = true;
    
    vector<int> ans;
    
    int cur_xor_pre = 1;
    int prev = 0;
    
    while (cur_xor_pre < MAX_N) {
        while ((vis[cur_xor_pre] || vis[X ^ cur_xor_pre]) && cur_xor_pre < MAX_N)
            cur_xor_pre ++;
            
        if (cur_xor_pre >= MAX_N)
            break;
            
        if ((cur_xor_pre ^ prev) >= (1 << N)) {
            vis[cur_xor_pre] = true;
            continue;
        }
        
        vis[cur_xor_pre] = true;
        ans.push_back(cur_xor_pre ^ prev);
    
        prev = cur_xor_pre;
    }
    
    cout << ans.size() << endl;
    
    for (int i = 0; i < ans.size(); i ++)
        cout << ans[i] << " ";

    cout << endl;
    return (0);
}