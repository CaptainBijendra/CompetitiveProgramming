#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MOD 998244353
#define MAX_N 200005
#define f first
#define s second

using namespace std;

vector<long long> a1, a2;

long long ar[MAX_N], fast_pow[MAX_N];
long long N, K;

long long solve(vector<long long> a) {
	long long ans = 1ll;
	
	//Case 1: All are -1
	bool flag = false;
	for (long long i = 0; i < a.size(); i ++) {
		if (a[i] != -1) {
			flag = true;
			break;
		}
	}
	
	if (!flag) {
		ans *= K;
		
		for (long long i = 1; i < a.size(); i ++) {
			ans *= (K - 1);
			ans %= MOD;
		}
		
		return (ans);
	}
	
	long long l, r;
	for (l = 0; l < a.size() && a[l] == -1; l ++);
	for (r = a.size() - 1; r >= 0 && a[r] == -1; r --);
	
	r = a.size() - 1 - r;
	
	long long sum = 0ll;
	
	if (l > 0) {
		sum = K * fast_pow[l - 1];
		sum %= MOD;

		for (long long i = 1; i < l; i ++) {
			if (i % 2 == 1)
				sum = ((sum - (K * fast_pow[l - i - 1]) % MOD + MOD) % MOD + MOD) % MOD;
			else
				sum = (sum + (K * fast_pow[l - i - 1]) % MOD) % MOD;
		}
	
		if (l % 2 == 1)
			sum --;
		else
			sum ++;
	
		sum = (sum + MOD) % MOD;
		ans = (ans * sum) % MOD;
	}
	
	sum = 0ll;

	if (r > 0) {
		sum = K * fast_pow[r - 1];
		sum %= MOD;
		
		for (long long i = 1; i < r; i ++) {
			if (i % 2 == 1)
				sum = ((sum - (K * fast_pow[r - i - 1]) % MOD + MOD) % MOD) % MOD;
			else
				sum = (sum + (K * fast_pow[r - i - 1]) % MOD) % MOD;
		}

		if (r % 2 == 1)
			sum --;
		else
			sum ++;
	
		sum = (sum + MOD) % MOD;
		ans = (ans * sum) % MOD;
	}
	
	long long streak = 0;
	long long lft = -2, rght;
	
	for (long long i = l; i < a.size(); i ++) {
		if (i > 0 && a[i] == a[i - 1] && a[i] != -1)
			return (0);
		
		if (a[i] == -1 && streak == 0) {
			streak ++;
			lft = a[i - 1];
		}
		
		else if (a[i] == -1)
			streak ++;
		
		if (a[i] != -1 && streak > 0) {
			rght = a[i];
			sum = 0ll;
			
			if (streak == 1) {
				if (lft == rght)
					ans = (ans * (K - 1)) % MOD;
				else
					ans = (ans * (K - 2)) % MOD;
				
				streak = 0;
				lft = -2;
				
				continue;
			}
			
			long long cnt = 0;
			for (long long j = streak; j >= 1; j --) {
				if (cnt % 2 == 0)
					sum = (sum + fast_pow[j]) % MOD;
				else
					sum = ((sum - fast_pow[j] + MOD) % MOD + MOD) % MOD;
				
				cnt ++;
			}
			
			if (lft != rght) {
				if (cnt % 2 == 0)
					sum --;
				else
					sum ++;
			}
			
			sum = (sum + MOD) % MOD;				
			ans = (ans * sum) % MOD;

			streak = 0;
			lft = -2;
		}
	}
	
	return (ans);
}

int main() {
	cin >> N >> K;
	
	for (long long i = 0; i < N; i ++) {
		cin >> ar[i];
		
		if (i % 2 == 0)
			a1.push_back(ar[i]);
		else
			a2.push_back(ar[i]);
	}
	
	fast_pow[0] = 1;	
	for (long long i = 1; i < MAX_N; i ++) {
		fast_pow[i] = (fast_pow[i - 1] * (K - 1)) % MOD;
		fast_pow[i] %= MOD;
	} 
	
	long long ans1 = solve(a1);
	long long ans2 = solve(a2);
	
	cout << ((ans1 * ans2) % MOD) << endl;
	return (0);
}