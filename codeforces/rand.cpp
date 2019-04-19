#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 70
#define f first
#define s second

using namespace std;

long long DP[MAX_N][MAX_N];
long long N, K;

long long calc(long long x) {
    long long sum = 0ll;
    long long ones = 0ll;
    
    for (int i = 63; i >= 0; i --) {
        if (x & (1ll << i)) {
            sum += DP[i][max(0ll, K - ones)];
            ones ++;
        }
    }
    
    return (sum);
}

int main() {
    cin >> N >> K;
    
    DP[0][0] = 1;
    
    for (int i = 1; i < MAX_N; i ++) {
        DP[i][0] = 1;
        DP[i][1] = 1;
    }
    
    for (int i = 1; i < MAX_N - 1; i ++) { //length
        for (int j = 0; j < MAX_N - 1; j ++) {
            DP[i + 1][j + 1] = DP[i][j] + DP[i][j + 1];
        }
    }
    
    long long low = 0ll;
    long long hi = 1000000000000000000ll;
    
    while (low != hi) {
        long long mid = (low + hi) / 2ll;
        long long val = calc(2 * mid) - calc(mid);
        
        if (val < N)
            low = mid + 1;
        else if (val > N)
            hi = mid;
        else {
            cout << mid << endl;
            return (0);
        }
    }
    
    cout << low << endl;
    return (0);
}