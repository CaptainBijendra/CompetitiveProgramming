#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MOD 1000000007
#define MAX_N 2005
#define f first
#define s second 

using namespace std;

long long DP[MAX_N][MAX_N][2];
long long N;

long long DFS (long long len, long long depth, bool used) {
	if (DP[len][depth][used] != -1)
		return (DP[len][depth][used]);
	
	if (len + depth > 2 * N)
		return (0);
	if (len == 2 * N && depth == 0)
		return (!used);
	
	DP[len][depth][used] = 0;
	
	if (used) {
		DP[len][depth][used] += DFS(len + 1, depth + 1, !used);
		DP[len][depth][used] %= MOD;
		
		if (depth > 0)
			DP[len][depth][used] += DFS(len + 1, depth - 1, !used); 
		
		DP[len][depth][used] %= MOD;
	} else {
		DP[len][depth][used] += max(DFS(len + 1, depth + 1, 0), DFS(len + 1, depth + 1, 1) + 1);
		DP[len][depth][used] %= MOD;
		
		if (depth > 0)
			DP[len][depth][used] += max(DFS(len + 1, depth - 1, 0), DFS(len + 1, depth - 1, 1) + 1);
	
		DP[len][depth][used] %= MOD;
	}
	
	return (DP[len][depth][used]);
}

int main() {
	cin >> N;
	
	for (long long i = 0; i < MAX_N; i ++)
		for (long long j = 0; j < MAX_N; j ++) {
			DP[i][j][0] = -1;
			DP[i][j][1] = -1; 
		}
		
	cout << ((DFS (0, 0, 0) * 500000004) % MOD) << endl;
	return (0);
}