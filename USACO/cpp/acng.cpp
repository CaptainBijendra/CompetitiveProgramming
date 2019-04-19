#include <iostream>

using namespace std;

int N;
int main() {
    cin >> N;
    
    int ans = 0;
    
    while (N != 1) {
        if (N % 2 == 0)
            N /= 2;
        else
            N = 3 * N + 1;
            
        ans ++;
    }

    cout << ans << endl;
    return (0);
}