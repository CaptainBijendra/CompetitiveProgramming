#include <iostream>
#include <vector>
#include <algorithm>

#define INF 200000009
#define MAX_T 10005
#define MAX_A 105
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;

pii ar[MAX_A];
ii slope[MAX_T];

int DP[MAX_T];
int T, S, N;

int main() {
    cin >> T >> S >> N;
    
    for (int i = 0; i < S; i ++) 
        cin >> ar[i].f >> ar[i].s.f >> ar[i].s.s;
    
    for (int i = 0; i < N; i ++)
        cin >> slope[i].f >> slope[i].s;
        
    sort(ar, ar + S);
    sort(slope, slope + N);
        
    int ans = 0, two_point = 0;
    int min_cst = INF;
        
    for (int i = 0; i < MAX_A; i ++) {
        for (int j = 0; j <= T; j ++) {
            if (j + min_cst <= T) {
                DP[j + min_cst] = max(DP[j + min_cst], DP[j] + 1);
                ans = max(ans, DP[j + min_cst]);
            }
        }
    
        while (slope[two_point].f == i) {
            min_cst = min(min_cst, slope[two_point].s);
            two_point ++;
        }
    }
    
    cout << ans << endl;
    return (0);
}