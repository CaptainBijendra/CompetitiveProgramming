#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 5005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int N, M, ref;

bool cmp(int a, int b) {
    return (abs(a - ref) < abs(b - ref));
}

int main() {
    cin >> N >> M;
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
    }
    
    for (int i = 0; i < N; i ++) {
        ref = i;
        sort(con[i].begin(), con[i].end(), cmp);
    }
    
    for (int i = 0; i < N; i ++) {
        int ans = 0;
        
        for (int j = 0; j < N; j ++) {
            if (con[j].size() == 0) {
                continue;
            }
            
            int start_dist, end_dist = MAX_N;
            
            if (j >= i)
                start_dist = j - i;
            else
                start_dist = N - i + j;
            
            for (int x = 0; x < con[j].size(); x ++) {
                int back = con[j][x];
            
                if (back >= j) 
                    end_dist = min(end_dist, back - j);
                else
                    end_dist = min(end_dist, N - j + back);
            }
            
            ans = max(ans, start_dist + N * (int)(con[j].size() - 1) + end_dist);
        }
        
        cout << ans << " ";
    }
    
    cout << endl;
}