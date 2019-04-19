#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 305
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> pii;

int ar[MAX_N][MAX_N], DP[MAX_N][MAX_N], pre[MAX_N][MAX_N];
int N;

int qrow(int r, int i, int j) {
    return (pre[r][j] - pre[r][i] + ar[r][i]);
}

bool cmp(pii a, pii b) {
    return ((a.f.s - a.f.f - 1) * (a.s.s - a.s.f - 1) < 
            (b.f.s - b.f.f - 1) * (b.s.s - b.s.f - 1));
}

int main() {
    ifstream fin ("eight.in");
    ofstream fout ("eight.out");
    
    fin >> N;

    string a;

    for (int i = 0; i < N; i ++) {
        fin >> a;
        
        for (int j = 0; j < N; j ++) 
            ar[i][j] = (a[j] == '*');
    }

    for (int i = 0; i < N; i ++) { 
        pre[i][0] = ar[0][i];
        
        for (int j = 1; j < N; j ++)
            pre[i][j] = pre[i][j - 1] + ar[j][i];
    }
    
    vector<pii> rect;

    for (int i = 0; i < N; i ++) { //Row
        for (int j = 3; j <= N; j ++) { //Length
            int lft = -1;

            if (i + j - 1 >= N)
                break;

            vector<int> pos;

            for (int k = 0; k < N; k ++) { //Column
                if (qrow(k, i, i + j - 1) == 0)
                    pos.push_back(k);

                if (ar[i][k] != 0 || ar[i + j - 1][k] != 0)
                    lft = -1;
            }
            
            for (int k = 0; k < pos.size(); k ++)
                for (int l = k + 1; l < pos.size(); l ++) 
                    rect.push_back(pii(ii(pos[k], pos[l]), ii(i, i + j - 1)));
        }
    }

    sort(rect.begin(), rect.end(), cmp);
    
    int ans = 0;
    bool flag = true;

    for (int i = rect.size() - 1; i >= 0; i --) {
        for (int j = rect.size() - 1; j >= 0; j --) {
            if (i == j)
                continue;
            
            if (rect[i].s.f == rect[j].s.s && ((rect[i].f.f <= rect[j].f.f && rect[j].f.s <= rect[i].f.s))) {
                ans = max(ans, ((rect[i].f.s - rect[i].f.f - 1) * (rect[i].s.s - rect[i].s.f - 1)) * ((rect[j].f.s - rect[j].f.f - 1) * (rect[j].s.s - rect[j].s.f - 1)));
                break;
            }
        }
    }
    
    fout << ans << endl;
    return (0);
}