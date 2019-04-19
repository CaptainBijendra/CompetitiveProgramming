#include <iostream>
#include <algorithm>

#define INF 2000000009
#define MAX_N 650005
#define f first
#define s second

using namespace std;

int A[MAX_N], B[MAX_N], DP[MAX_N], ans[MAX_N], final[MAX_N];
int N, H;

int main() {
    cin >> N >> H;

    for (int i = 0; i < N; i ++) {
        cin >> A[i];
        cin >> B[i];
    }
    
    for (int i = 1; i < MAX_N; i ++)
        DP[i] = INF;

    for (int i = 0; i < MAX_N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (i + A[j] >= MAX_N)
                continue;
            
            DP[i + A[j]] = min(DP[i + A[j]], DP[i] + B[j]);
        }
    }
    
    for (int i = 0; i < MAX_N; i ++)
        final[i] = INF;
    
    int tmp = H;

    for (int i = tmp + 1; i < MAX_N; i ++)
        if (DP[i] < DP[H])
            H = i;

    for (int i = tmp; i < MAX_N; i ++) { 
        if (DP[i] != DP[H])
            continue;
        
        int cur = DP[i];
        int h = i;
    
        for (int j = N - 1; j >= 0; j --) {
            while (DP[h - A[j]] == cur - B[j]) {
                cur -= B[j];
                h -= A[j];
            
                ans[j] ++;
            }
        }
        
        bool change = false;
        for (int j = 0; j < N; j ++) {
            if (ans[j] < final[j]) {
                change = true;
                break;
            }
            
            if (ans[j] > final[j])
                break;
        }
        
        if (change) {
            for (int j = 0; j < N; j ++)
                final[j] = ans[j];
        }
        
        for (int j = 0; j < N; j ++)
            ans[j] = 0;
    }
    
    for (int i = 0; i < N; i ++)
        cout << final[i] << endl;

    return (0);
}