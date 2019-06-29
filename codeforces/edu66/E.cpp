#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <vector>

#define MAX_N 500005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

ii ar[MAX_N];

int DP[MAX_N][25], con[MAX_N];
int N, M;

bool cmp(ii a, ii b) {
    if (a.s < b.s)
        return (true);
    else if (a.s > b.s)
        return (false);
    return (a.f < b.f);
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i].f >> ar[i].s;   
        con[ar[i].f] = max(ar[i].s, con[ar[i].f]);
    }
    
    int c_max = 0;
    for (int i = 1; i < MAX_N; i ++) {
        c_max = max(c_max, con[i]);
        DP[i][0] = (c_max < i ? 0 : c_max);
    }
    
    for (int j = 1; j <= 22; j ++) {
        for (int i = 1; i < MAX_N; i ++) {
            DP[i][j] = DP[DP[i][j - 1]][j - 1];
        }        
    }
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        
        int low = 0;
        int hi = MAX_N;
        
        while (low < hi) {
            int mid = (low + hi) / 2;
            
            int cur = a;
            for (int j = 22; j >= 0; j --)
                if (mid & (1 << j))
                    cur = DP[cur][j];
            
            if (cur >= b)
                hi = mid;
            else
                low = mid + 1;
        }
        
        if (low == MAX_N)
            cout << "-1" << endl;
        else
            cout << low << endl;
    }
    
    return (0);
}