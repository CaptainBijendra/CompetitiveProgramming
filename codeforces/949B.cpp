#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

long long N, Q;

long long solve (long long low, long long hi, long long num) {
    if (low == N) { return (low); } 
    if (hi - low == 1) { return (num == 1 ? low : hi); }
    if (num % 2 == 1)
        return (low + (num - 1) / 2);
    
    return (solve((low + hi + 1) / 2 + 1, hi, num / 2));
}

int main() {
    cin >> N >> Q;
    
    long long x;
    for (int i = 0; i < Q; i ++) {
        cin >> x;
        
        if (x % 2 == 1)
            cout << (1 + (x - 1) / 2) << endl;
        else {
            cout << solve((N + 1) / 2 + 1, N, x / 2) << endl;
        }
    }
    
    return (0);
}