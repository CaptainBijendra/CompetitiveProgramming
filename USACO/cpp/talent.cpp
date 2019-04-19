#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 255
#define f first
#define s second

using namespace std;

int DP[1000005], w[MAX_N], t[MAX_N];
int N, W;

int main() {
    ifstream fin ("talent.in");
    ofstream fout ("talent.out");
    
    fin >> N >> W;
    
    int ans = 0;
    
    for (int i = 0; i < N; i ++)
        fin >> w[i] >> t[i];
        
    for (int i = 0; i <= 1000005; i ++)
        DP[i] = -100000005;
    
    DP[0] = 0;
    
    for (int j = 0; j < N; j ++) {
        for (int i = 1000005; i >= 0; i --) {
            if (i + w[j] >= 1000000)
                ans = max(ans, (int)(1000.0 * ((DP[i] + t[j]) * 1.0) / (i + w[j])));
            else
                DP[i + w[j]] = max(DP[i + w[j]], DP[i] + t[j]);
        }
    }
    
    for (int i = W; i <= 1000005; i ++)
        ans = max(ans, (int)(1000 * (DP[i] * 1.0 / (i * 1.0))));
    
    fout << ans << endl;
    return (0);
}