#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    
    int cur, prev;
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        cin >> cur;
        
        if (i == 0)
            prev = cur;
        else {
            ans += (prev != cur);
            prev = cur;
        }
    }
    
    cout << ans << endl;
    return (0);
}