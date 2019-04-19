#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int Q;

int main() {
    cin >> Q;    

    int x;
    for (int i = 0; i < Q; i ++) {
        cin >> x;
        
        int cur = 2;
        int big = 0;
        
        for (int i = 0; i <= 25; i ++) {
            if (cur - 1 > x)
                break;
        
            if (__gcd((x & (cur - 1)), (x ^ (cur - 1))) > big)
                big = __gcd((x & (cur - 1)), (x ^ (cur - 1)));
            
            cur *= 2;
        }
        
        cout << big << endl;
    }

    return (0);
}