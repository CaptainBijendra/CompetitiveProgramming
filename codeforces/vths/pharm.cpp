#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> R;
vector<ii> S;

int tec[MAX_N];
int N, T

int main() {
    cin >> N >> T;

    int d, a, s;
    for (int i = 0; i < N; i ++) {
        cin >> d >> a >> s;
        
        if (a == 'R')
            R.push_back(ii(d, s));
        else
            S.push_back(ii(d, s));
    }
    
    sort(R.begin(), R.end());
    sort(S.begin(), S.end());
    
    int cur_t = 0;
    
    while (true) {
        int best = MAX_N * 1000;
        for (int i = 0; i < T; i ++)
            best = min(best, tec[i]);
            
        if (R.size() > 0 && R[0] >= best) {
            
            for (int i = 0; i < T; i ++)
                if (tec[i] == best) {
                    tec[i] = (cur_t + R[0].s);
                }
            
            R.erase(R.begin());
            continue;
        }
    }
    
    return (0);
}