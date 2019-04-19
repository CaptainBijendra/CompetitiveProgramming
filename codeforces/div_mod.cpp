#include <iostream>

#define INF 2000000009

using namespace std;

int N, K;

int main() {
    cin >> N >> K;

    int ans = 1000000000;
    for (int i = 1; i <= 1000000; i ++) {
        int mod = (N % i == 0 ? N / i : INF);
        
        if (mod < K) {    
            ans = min(ans, i * K + mod);
        }        
    }

    cout << ans << endl;
    return (0);
}