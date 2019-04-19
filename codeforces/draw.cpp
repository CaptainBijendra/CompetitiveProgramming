#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

int N;

int main() {
    cin >> N;
    
    int lA = 0, lB = 0;
    int ans = 0;
    
    int a, b;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
        
        ans += max(0, min(a, b) - max(lA, lB));
        
        lA = a;
        lB = b;
    }

    if (lA == lB)
        ans ++;

    cout << (ans + 1) << endl;    
    return (0);
}