#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 20005
#define f first
#define s second

using namespace std;

bool ending[MAX_N];

long long nxt[MAX_N][26];

long long DP[MAX_N][105], depth[MAX_N], knap[105];
long long T, N, K, cur_ind;

void insert(string str, long long ind, long long cur) {
    if (ind == str.size()) {
        ending[cur] = true;
        return;
    }
    
    long long s = str[ind] - 'a';
    
    if (nxt[cur][s] == -1) {
        cur_ind ++;
        nxt[cur][s] = cur_ind;
        
        depth[cur_ind] = depth[cur] + 1;
        insert(str, ind + 1, cur_ind);
    }
    
    else {
        insert(str, ind + 1, nxt[cur][s]);
    }
}

void DFS (long long cur) {
    vector<int> v;
    
    for (long long i = 0; i < 26; i ++) {
        if (nxt[cur][i] != -1) {
            DFS (nxt[cur][i]);
            v.push_back(i);
        }
    }
        
    for (long long i = 1; i < 105; i ++)
        knap[i] = INF;
    
    for (int ii = 0; ii < v.size(); ii ++) {
        int c = v[ii];
        
        for (long long i = 105; i >= 0; i --) {
            for (long long j = 0; j < 105; j ++) {
                if (i + j < 105)
                    knap[i + j] = min(knap[i + j], min((long long)INF, knap[i] + DP[nxt[cur][c]][j]));            
                else
                    break;
            }
        }
    }
    
    if (ending[cur]) {
        for (int i = 104; i >= 0; i --)
            knap[i + 1] = min(knap[i + 1], knap[i] + DP[cur][1]);
    }
    
    for (long long i = 0; i < 105; i ++)
        DP[cur][i] = min(DP[cur][i], knap[i]);
}

int main() {
    cin >> T;
    
    for (long long ii = 0; ii < T; ii ++) {
        cin >> N >> K;
        
        for (long long i = 0; i < MAX_N; i ++) {
            for (long long j = 0; j < 105; j ++)
                DP[i][j] = INF;
            
            for (long long j = 0; j < 26; j ++)
                nxt[i][j] = -1;
            
            ending[i] = false;
        }
        
        cur_ind = 0;
        
        string str;
        for (long long i = 0; i < N; i ++) {
            cin >> str;
            insert(str, 0, 0);
        }
        
        for (long long i = 0; i <= cur_ind; i ++) {
            DP[i][0] = 0;
            DP[i][1] = depth[i];
        }
        
        DFS (0);
        cout << "Case #" << (ii + 1) << ": " << DP[0][K] << endl;
    }
    
    return (0);
}
