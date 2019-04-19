#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;
ii shows[MAX_N];

vector<ii> TV;

long long N, X, Y;

bool cmp(ii a, ii b) {
	return (a.s < b.s);
}

int main() {
	cin >> N >> X >> Y;
	
	for (long long i = 0; i < N; i ++)
		cin >> shows[i].f >> shows[i].s;
	
	sort(shows, shows + N, cmp);
	
	for (long long i = 0; i < N; i ++) {
		long long new_tv = (X + Y * (shows[i].s - shows[i].f));
		long long better_cst = 4e+18;

		vector<ii>::iterator it = upper_bound(TV.begin(), TV.end(), ii(better_cst, shows[i].f - 1), [](ii l, ii r) -> bool { return (l.s < r.s); });
	
		if (it != TV.begin())
			it --;
		else {
			TV.push_back(ii(shows[i].f, shows[i].s));	
			continue;
		}
		
		better_cst = Y * (shows[i].s - it->s);
		
		if (better_cst >= new_tv)
			TV.push_back(ii(shows[i].f, shows[i].s));
		else {
			long long beg = it->f;
			
			TV.erase(it);
			TV.push_back(ii(beg, shows[i].s));
		}
	}
	
	long long cost = 0ll;
	
	for (int i = 0; i < TV.size(); i ++) {
		ii cur = TV[i];
		
		cost = cost + ((X + Y * (cur.s - cur.f)) % MOD);
		cost %= MOD;
	}
	
	cout << cost << endl;
	return (0);
}