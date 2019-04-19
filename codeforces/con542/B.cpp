#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 300005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

vector<long long> loc[MAX_N];

long long ar[MAX_N];
long long N, M;

int main() {
    cin >> N;
    
    long long x;
    for (long long i = 0; i < 2 * N; i ++) {
        cin >> x; 
        loc[x].push_back(i);
    }

    long long P1 = loc[1][0];
    long long P2 = loc[1][1];
    
    long long ans = P1 + P2;
    
    for (long long i = 2; i <= N; i ++) {
        if (abs(P1 - loc[i][0]) + abs(P2 - loc[i][1]) < abs(P1 - loc[i][1]) + abs(P2 - loc[i][0])) {
            ans += abs(P1 - loc[i][0]);
            ans += abs(P2 - loc[i][1]);

            P1 = loc[i][0];
            P2 = loc[i][1];
        }
        
        else {
            ans += abs(P1 - loc[i][1]);
            ans += abs(P2 - loc[i][0]);

            P1 = loc[i][1];
            P2 = loc[i][0];
        }
    }
    
    cout << ans << endl;
    return (0);
}