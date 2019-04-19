#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 105
#define MOD 1000000009
#define f first
#define s second

using namespace std;

int cnt[MAX_N], people[MAX_N];;
int N, M;

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < M; i ++) {
        int a;
        
        cin >> a;
        cnt[a] ++;
    }
    
    int final_ans = MOD;
    
    for (int i = 0; i < N; i ++) {
        int ans = 0;
        int ind = -1;
        
        for (int j = 0; j < MAX_N; j ++) {
            if (cnt[j] > 0) {
                if (cnt[j] / (people[j] + 1) > ans) { 
                    ans = cnt[j] / (people[j] + 1);
                    ind = j;
                }    
            }
        }
        
        people[ind] ++;
        final_ans = min(final_ans, ans);
    }
    
    cout << final_ans << endl;
    return (0);
}