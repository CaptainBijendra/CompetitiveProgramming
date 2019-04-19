#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 500005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

vector<ii> query;

vector<long long> con[MAX_N];
vector<long long> pre[MAX_N];

long long used[MAX_N];
long long N, M;

int main() {
    cin >> N >> M;
    
    long long a, b;
    for (long long i = 0; i < N; i ++) {
        cin >> a >> b;
        query.push_back(ii(a, b));
    }
    
    sort(query.begin(), query.end());
    
    long long cnt = 0;
    
    for (long long i = 0; i < query.size(); i ++) {
        if (i == 0) {
            con[cnt].push_back(query[i].s);
            continue;
        }
        
        if (query[i].f == query[i - 1].f)
            con[cnt].push_back(query[i].s);
        else {
            cnt ++;
            con[cnt].push_back(query[i].s);
        }
    }
    
    M = cnt + 1;
    
    for (long long i = 0; i < M; i ++) {
        sort(con[i].begin(), con[i].end());
        reverse(con[i].begin(), con[i].end());
    
        if (con[i].size() >= 1)
            pre[i].push_back(con[i][0]);
        
        for (long long j = 1; j < con[i].size(); j ++)
            pre[i].push_back(pre[i][j - 1] + con[i][j]);
    }
    
    long long fin_ans = 0;
    long long ans = 0, counter = 0, streak = 0;
    
    bool flag = false;
    
    cnt = 0;
    
    for (long long i = 0; i < N; counter ++) {
        if (counter % M == 0 && counter != 0) {
            cnt ++;
            fin_ans = max(fin_ans, ans);
        }
        
        if (streak == M)
            break;
        
        if (used[(counter % M)]) {
            i += (cnt < con[(counter % M)].size());
            streak ++;
            
            continue;
        }
        
        streak = 0;
        
        if (con[counter % M].size() <= cnt) {
            used[(counter % M)] = true;
        
            if (cnt > 0 && pre[(counter % M)].size() > cnt - 1)
                ans -= pre[(counter % M)][cnt - 1];
        
            continue;
        }
        
        else if (cnt < pre[(counter % M)].size() && pre[(counter % M)][cnt] < 0) {
            used[(counter % M)] = true;
            
            if (cnt > 0 && pre[(counter % M)].size() > cnt - 1)
                ans -= pre[(counter % M)][cnt - 1];
        }
        
        else
            ans += con[(counter % M)][cnt];
    
        i ++;    
    }
    
    fin_ans = max(fin_ans, ans);
    
    cout << fin_ans << endl;
    return (0);
}