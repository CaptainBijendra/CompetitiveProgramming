#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <math.h>

#define MAX_N 105
#define f first
#define s second

using namespace std;

long long DP[MAX_N][MAX_N][MAX_N];
long long ar[MAX_N], knap[MAX_N];
long long N;

string str;

long long solve(int l, int r, int prefix) {
    if (l > r)
        return (0);
    
    if (l == r)
        return (knap[prefix]);
    
    if (DP[l][r][prefix])
        return (DP[l][r][prefix]);

    DP[l][r][prefix] = max(DP[l][r][prefix], solve(l + 1, r, 1) + knap[prefix]);
    
    for (int i = l + 1; i <= r; i ++) {
        if (str[i] == str[l]) {
            DP[l][r][prefix] = max(DP[l][r][prefix], solve(l + 1, i - 1, 1) + solve(i, r, prefix + 1));
        }
    }
    
    return (DP[l][r][prefix]);
}

int main() {
    cin >> N;
    cin >> str;
    
    for (long long i = 1; i <= N; i ++)
        cin >> ar[i];
    
    for (long long i = 1; i < MAX_N; i ++)
        knap[i] = -1ll * MAX_N * MAX_N * MAX_N * MAX_N * MAX_N * MAX_N * MAX_N;
    
    for (long long i = 0; i < MAX_N; i ++) {
        for (long long j = 1; j <= N; j ++)
            if (i + j < MAX_N)
                knap[i + j] = max(knap[i + j], knap[i] + ar[j]);
    }
    
    cout << solve(0, N - 1, 1) << endl;
    return (0);
}