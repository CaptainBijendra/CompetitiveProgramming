#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>

#define MAX_N 31005
#define f first
#define s second

using namespace std;

string str;

int DP[MAX_N], cnt[255];
int N, M, K, T;

int main() {
    cin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        cin >> N >> M >> K;
        cin >> str;
        
        if (N < M) {
            int tmp = M;
            M = N;
            N = tmp;
        }
        
        for (int i = 0; i < K; i ++) {
            cnt[str[i] - 'A'] ++;
            cnt[str[i] - 'A'] = min(cnt[str[i] - 'A'], N);
        }
        
        int ans = MAX_N * MAX_N;
        
        //For each character try building DP without
        //using this character
        for (int a = 0; a < 26; a ++) {
            DP[0] = 1;
            
            for (int i = 0; i < 26; i ++) {
                if (i == a) { continue; }
                for (int j = MAX_N - 1; j >= 0; j --) {
                    if (DP[j] && j + cnt[i] < MAX_N) 
                        DP[j + cnt[i]] = DP[j];
                }
            }
            
            for (int i = 0; i < cnt[a]; i ++) {
                if (DP[N - i]) {
                    ans = min(ans, i * (cnt[a] - i));
                }
            }
        
            for (int i = 0; i < N + 100; i ++)
                DP[i] = 0;
        }
        
        cout << ans << endl;
        
        for (int i = 0; i < K; i ++)
            cnt[str[i] - 'A'] = 0;
    }
    
    return (0);
}