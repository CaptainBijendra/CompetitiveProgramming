#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 500005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int pre[MAX_N], ar[MAX_N], tmp[MAX_N];
int N, C;

int main() {
    cin >> N >> C;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        con[ar[i]].push_back(i);
        
        if (ar[i] == C)
            tmp[i] = 1;
    }
    
    pre[0] = tmp[0];
    for (int i = 1; i < MAX_N; i ++)
        pre[i] = pre[i - 1] + tmp[i];
    
    int ans = 0;
    for (int i = 0; i < MAX_N; i ++) {
        int big = -MAX_N;
        
        for (int j = 0; j < con[i].size(); j ++) {
            big = max(big, (con[i][j] == 0 ? 0 : pre[con[i][j] - 1]) - j + 1);
            ans = max(ans, pre[MAX_N - 1] - pre[con[i][j]] + j + big);
        }
    }
    
    cout << ans << endl;
    return (0);
}