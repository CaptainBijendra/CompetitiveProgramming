#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

typedef pair<long double, long double> ii;
typedef pair<ii, long double> pii;

ii cow[MAX_N];
int N;

bool cmp(pii a, pii b) {
    if ((a.f.f * 1.0) / (a.f.s * 1.0) < (b.f.f * 1.0) / (b.f.s * 1.0))
        return (true);
    if ((a.f.f * 1.0) / (a.f.s * 1.0) > (b.f.f * 1.0) / (b.f.s * 1.0))
        return (false);

    return (a.s < b.s);
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> cow[i].f >> cow[i].s;
    
    vector<pii> vis;
    map<ii, int> vis2;
    
    map<int, bool> infinite;
    map<int, bool> flat;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (i == j)
                continue;
            
            int dx = cow[j].f - cow[i].f;
            int dy = cow[j].s - cow[i].s;
            
            if (dx == 0) {
				infinite[cow[j].f] = true;
				continue;
			}
			 
			if (dy == 0) {
			    flat[cow[j].s] = true;
			    continue;
			}
			    
			vis.push_back(pii(ii(dy / __gcd(dx, dy), dx / __gcd(dx, dy)), cow[j].s - cow[j].f * ((dy * 1.0) / (dx * 1.0))));
        }
    }
    
    sort(vis.begin(), vis.end(), cmp);
    
    int sz = vis.size();
    
    pii prev = pii(ii(-1.0, -1.0), -1.0);
    for (int i = 0; i < vis.size(); i ++) {
        pii cur = vis[i];
        
        if (prev.f.f == -1.0 && prev.f.s == -1.0 && prev.s == -1.0) {
            vis2[cur.first] ++;
            prev = cur;
            continue;
        }
        
        if (cur.f.f == prev.f.f && cur.f.s == prev.f.s && (abs(cur.s - prev.s) <= 0.000000001))  {
            sz --;
            prev = cur;
            continue;
        }

        vis2[cur.first] ++;
        prev = cur;
    }    
    
    long long ans = (long long)(sz + infinite.size() + flat.size()) * (long long)(sz - 1 + infinite.size() + flat.size()) / 2ll;
    
    for (map<ii, int>::iterator it = vis2.begin(); it != vis2.end(); it ++)
		ans -= ((long long)((((long long)it->second) * ((long long)it->second - 1)) / 2ll));
    
    ans -= (((long long)(infinite.size()) * ((long long)infinite.size() - 1)) / 2ll);
    ans -= (((long long)(flat.size()) * ((long long)flat.size() - 1)) / 2ll);
    
    cout << max(0ll, ans) << endl;
    return (0);
}