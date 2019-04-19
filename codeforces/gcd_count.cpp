#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define INF 2000000009
#define MAX_N 200005
#define MAX_M 100
#define f first
#define s second

using namespace std;

vector<long long> con[MAX_N];
vector<long long> sol;

bool vis[MAX_N];

long long DP[MAX_N][MAX_M], val[MAX_N], extra[MAX_N];
long long N, ans;

void DFS(long long ind) {
	vis[ind] = true;
	
	vector<long long> bigger[MAX_M];
	vector<long long> plus;
	
	for (long long i = 0; i < con[ind].size(); i ++) {
		if (!vis[con[ind][i]]) {
			DFS (con[ind][i]);
			
			bool flag = true;
			for (long long j = 0; j < sol.size(); j ++) {
				if (val[ind] % sol[j] == 0) {
					DP[ind][j] = max(DP[ind][j], DP[con[ind][i]][j] + 1);
					ans = max(ans, DP[ind][j]);
					
					bigger[j].push_back(DP[con[ind][i]][j]);
				
					flag = false;
				}
			}		
			
			if (flag) {
				if (val[con[ind][i]] == val[ind] && val[ind] != 1) {
					extra[con[ind][i]] = max(extra[con[ind][i]], 1ll);
					extra[ind] = max(extra[ind], extra[con[ind][i]] + 1);
					
					ans = max(ans, extra[ind]);
					
					plus.push_back(extra[con[ind][i]]);
				}
			}
		}
	}
	
	if (plus.size() > 0 && val[ind] != 1) {
		sort(plus.begin(), plus.end());
		
		if (plus.size() >= 2)
			ans = max(ans, plus[plus.size() - 1] + plus[plus.size() - 2] + 1);
		
		return;
	}
	
	for (long long i = 0; i < sol.size(); i ++)
		sort(bigger[i].begin(), bigger[i].end());
		
	for (long long i = 0; i < MAX_M; i ++)
		if (bigger[i].size() >= 2)
			ans = max(ans, bigger[i][bigger[i].size() - 1] + bigger[i][bigger[i].size() - 2] + 1);
	
	vis[ind] = false;
}

int main() {
	cin >> N;
	
	for (long long i = 0; i < N; i ++)
		cin >> val[i];
	
	long long a, b;
	for (long long i = 0; i < N - 1; i ++) {
		cin >> a >> b;
		con[a - 1].push_back(b - 1);
		con[b - 1].push_back(a - 1);
	}
	
	for (long long i = 2; i <= sqrt(MAX_N); i ++) {
		bool flag = true;
		
		for (long long j = 2; j * j <= i; j ++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		
		if (flag)
			sol.push_back(i);
	}
	
	for (long long i = 0; i < MAX_N; i ++)
		for (long long j = 0; j <= sol.size(); j ++)
			DP[i][j] = -INF;
	
	ans = 0;
	for (long long i = 0; i < N; i ++) {
		for (long long j = 0; j < sol.size(); j ++)
			if (val[i] % sol[j] == 0) {
				DP[i][j] = 1;
				ans = 1;
			}
	}
	
	DFS (0);
	
	cout << ans << endl;
	return 0;
}