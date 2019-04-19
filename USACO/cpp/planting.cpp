/*
ID: akommul1
PROG: rect1
LANG: C++11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define MAX_N 2505
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> pii;
typedef pair<pii, int> piii;

vector<piii> cur;

int ans[MAX_N];
int A, B, N; 

void fix_board(int lx, int ly, int ux, int uy, int color) {
	vector<piii> upd_nxt;
	upd_nxt.push_back(piii(pii(ii(lx, ux), ii(ly, uy)), color));
	
	for (int i = 0; i < cur.size(); i ++) {
		piii cur_pi = cur[i];
		
		if (ux <= cur_pi.f.f.f || uy <= cur_pi.f.s.f || lx >= cur_pi.f.f.s || ly >= cur_pi.f.s.s) {
			upd_nxt.push_back(cur_pi);
			continue;
		}
		
		if (ux < cur_pi.f.f.s) {
			upd_nxt.push_back(piii(pii(ii(ux, cur_pi.f.f.s), cur_pi.f.s), cur_pi.s));
		}
	
		if (lx > cur_pi.f.f.f) {
			upd_nxt.push_back(piii(pii(ii(cur_pi.f.f.f, lx), cur_pi.f.s), cur_pi.s));
		}
		
		if (uy < cur_pi.f.s.s) {
			upd_nxt.push_back(piii(pii(ii(max(lx, cur_pi.f.f.f), min(ux, cur_pi.f.f.s)), ii(uy,cur_pi.f.s.s)), cur_pi.s));
		}
		
		if (ly > cur_pi.f.s.f) {
			upd_nxt.push_back(piii(pii(ii(max(lx, cur_pi.f.f.f), min(ux, cur_pi.f.f.s)), ii(cur_pi.f.s.f, ly)), cur_pi.s));
		}
	}

	cur = upd_nxt;
}

int main() {
	cin >> A >> B >> N;
	cur.push_back(piii(pii(ii(0, A), ii(0, B)), 1));
	
	for (int i = 0; i < N; i ++) { 
		int lx, ly, ux, uy, c;
		
		cin >> lx >> ly >> ux >> uy >> c;
		fix_board(lx, ly, ux, uy, c);
	}
	
	for (int i = 0; i < cur.size(); i ++) { 
		piii a = cur[i];
		ans[a.s] += (a.f.f.s - a.f.f.f) * (a.f.s.s - a.f.s.f);
	}
	
	for (int i = 0; i < MAX_N; i ++) { 
		if (ans[i]) {
			cout << i << " " << ans[i] << endl;
		}	
	}
	
	return (0);
}