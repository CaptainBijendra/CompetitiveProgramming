#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int N, K;

int main() {
    string str;
    
    cin >> str;
    N = str.size();

    cin >> K;
    
    int ans = 1;
    
    for (int i = 0; i < N + K; i ++) {
        for (int j = i + 1; j < N + K; j += 2) {
            int n = (j - i + 1) / 2;
            int flag = 1;
            
            if (i + 2 * n > (N + K))
                break;
    
            for (int k = i; k < min(N + K, i + n); k ++) {
                if (k + n >= N)
                    continue;
                
                if (str[k] != str[k + n]) {
                    flag = 0;
                    break;
                }
            }
            
            if (flag)
                ans = max(ans, 2 * n);
        }
    }
    
    cout << ans << endl;
    return (0);
}