#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int DP[MAX_N][10];
int N;

int main() {
    cin >> N;

    for (int i = 0; i < MAX_N; i ++) {
        for (int j = 0; j < 10; j ++) {
            DP[i][j] = -MAX_N * 100;
        }
    }
    
    DP[0][0][0] = 0;

    int blocks;
    for (int i = 0; i < N; i ++) {
        cin >> blocks;

        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        
        v1.push_back(0); v1.push_back(0); v1.push_back(0);
        v2.push_back(0); v2.push_back(0); v2.push_back(0);
        v3.push_back(0); v3.push_back(0); v3.push_back(0);

        int x, y;
        for (int j = 0; j < blocks; j ++) {
            cin >> x >> y;
                
            if (x == 1)
                v1.push_back(y);
            else if (x == 2)
                v2.push_back(y);
            else    
                v3.push_back(y);
        }
        
        sort(v1.begin(), v1.end()); reverse(v1.begin(), v1.end());
        sort(v2.begin(), v2.end()); reverse(v2.begin(), v2.end());
        sort(v3.begin(), v3.end()); reverse(v3.begin(), v3.end());
    
        for (int j = 0; j < 10; j ++) {
            if (j < 7)
                DP[i + 1][j + 3] = max(DP[i + 1][j + 3], DP[i][j] + v1[0] + v1[1] + v1[2]);
            if (j < 8)
                DP[i + 1][j + 2] = max(DP[i + 1][j + 2], DP[i][j] + v1[0] + max(v1[1], v2[0]));
            if (j < 9)
                DP[i + 1][j + 1] = max(DP[i + 1][j + 1], DP[i][j] + max(v1[0], max(v2[0], v3[0])));
        }
    }
    
    int ans = 0;
    for (int j = 0; j < 10; j ++)
        ans = max(ans, DP[N][j][0]);

    cout << ans << endl;
}