#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define INF 20000009
#define MAX_N 100005
#define MAX_K 105

using namespace std;

typedef pair<int, int> ii;

vector<ii> cows;
ii ar[MAX_N];

int DP[MAX_N][MAX_K];
int max_rng[MAX_N], pre[MAX_N];

int N, K;

bool cmp(ii a, ii b) {
    if (a.second == b.second) { return (a.first > b.first); }
    else { return (a.second < b.second); }
}

void update(int left) {
    //For all K, determine maximum area after removing i lifeguards from 0 to left inclusive    
    
    for (int i = 0; i <= K; i ++) {
        if (left >= i && pre[i] >= 0) {
            if (max_rng[i] - cows[pre[i]].second + cows[left].second > max_rng[i]) {
                max_rng[i] = max_rng[i] - cows[pre[i]].second + cows[left].second;
                pre[i] = i;
            }
            
            if (max_rng[i - 1] > max_rng[i]) {
                max_rng[i] = max_rng[i - 1];
                pre[i] = pre[i - 1];
            }
        }
    }
}

int query(int num) { 
    //return the maximum area after update function
    if (num < 0) { return (-INF); } 
    return (max_rng[num]);
}

int main() {
    ifstream fin ("lifeguards.in");
    ofstream fout ("lifeguards.out");
    
    fin >> N >> K;
    for (int i = 0; i < N; i ++) { fin >> ar[i].first >> ar[i].second; }
    
    ar[N] = ii(INF, INF); 
    sort(ar, ar + N, cmp);        
    
    int tmp = N;
    
    for (int i = 0; i < tmp; i ++) {
        cows.push_back(ar[i]);
        
        while ((cows.size() > 0) && (ar[i + 1].first <= cows[cows.size() - 1].first)) {
            N --; K --; 
            cows.pop_back();    
        }
    }

    K = max(K, 0);

    int left = 0;
    
    DP[0][0] = cows[0].second - cows[0].first;
    
    for (int i = 0; i < N; i ++) {
        DP[i + 1][0] = DP[i][0] + cows[i + 1].second - cows[i + 1].first - 
                       max(0, (cows[i].second - cows[i + 1].first));
    }

    for (int i = 0; i <= K; i ++) { pre[i] = -1; }

    max_rng[0] = DP[0][0]; 
    max_rng[1] = DP[0][1];
    
    pre[0] = 0;

    update(0);

    for (int i = 1; i < N; i ++) {
        while (cows[left].second < cows[i].first) {
            update(left ++);
        }
        
        cout << "LEFT: " << left << " I: " << i << endl;

        for (int j = 0; j <= min(i, K); j ++) {
            if (j <= i) {
                DP[i][j] = max(DP[i][j], cows[i].second - cows[i].first); 
            }
            
            DP[i][j] = max(DP[i][j], query(j - (i - left)) + cows[i].second - cows[i].first);
            DP[i][j] = max(DP[i][j], DP[left][j - (i - left - 1)] + cows[i].second - cows[left].second); 
        }
    }
   
    cout << N << " " << K << endl;

    for (int i = 0; i < N; i ++) {
        cout << cows[i].first << " " << cows[i].second << endl;
    }
    
    for (int i = 0; i <= K; i ++) {
        cout << "I: " << i << " " << max_rng[i] << endl;
    }

    int ans = 0;

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= K; j ++) { 
            if ((N - i - 1) + j >= K) { ans = max(ans, DP[i][j]); }
            
            cout << i << " " << j << " " << DP[i][j] << endl;
        }
    }

    fout << ans << endl;
    return (0);
}
