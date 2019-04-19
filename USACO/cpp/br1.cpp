#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    
    int ans = 0;
    
    for (int i = 1; i * i <= N; i ++) {
        if (N % i == 0) {
            ans += i;
            
            if (i != (N / i))
                ans += (N / i);
        }
    }
    
    cout << ans << endl;
    return (0);
}