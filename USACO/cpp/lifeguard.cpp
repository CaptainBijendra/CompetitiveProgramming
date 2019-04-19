#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

ii ar[MAX_N];

int DP[MAX_N][605];
int N, K;

bool cmp(ii a, ii b) {
    return (a.s < b.s);
}

int main() {
    ifstream fin ("lifeguards.in");
    ofstream fout ("lifeguards.out");

    ios::sync_with_stdio(0); fin.tie(0); fout.tie(0);

    fin >> N >> K;

    for (int i = 0; i < N; i ++)
        fin >> ar[i].f >> ar[i].s;

    sort(ar, ar + N);
    
    int mx = 0;
    int newN = N;
    
    for (int i = 0; i < N; i ++) {
        if (ar[i].s >= mx) {
            mx = ar[i].s;
            continue;
        }
        
        else {
            ar[i].f = INF;
            ar[i].s = INF;
            
            newN --;
            K --;
        }
        
        if (K == 0)
            break;
    }
    
    sort(ar, ar + N, cmp);
    N = newN;
    
    for (int i = 0; i < N; i ++) {
        DP[i][min(i, K)] = max(DP[i][min(i, K)], ar[i].s - ar[i].f);
    
        for (int j = 0; j <= min(i, K); j ++) {
            for (int k = i + 1; k < N; k ++) {
                if (j + (k - i - 1) > K)
                    break;
                
                if (ar[k].f <= ar[i].s)
                    DP[k][j + (k - i - 1)] = max(DP[k][j + (k - i - 1)], DP[i][j] + ar[k].s - ar[i].s);
                if (ar[k].f > ar[i].s && ar[k].s >= ar[i].s)
                    DP[k][j + (k - i - 1)] = max(DP[k][j + (k - i - 1)], DP[i][j] + ar[k].s - ar[k].f);
            }
        }
    }

    int ans = 0;
    int sum = 0;

	for (int i = 0; i < N; i ++)
	    if (K - (N - 1 - i) >= 0)
	        ans = max(ans, DP[i][K - (N - 1 - i)]);

    fout << ans << endl;
    return (0);
}