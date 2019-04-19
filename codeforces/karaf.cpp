#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

long long A, B, N, L, M, T;

int main() {
    cin >> A >> B >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> L >> T >> M;
        
        long long low = L;
        long long hi = 1000000000;
    
        while (low < hi) {
            long long mid = (low + hi) / 2;
            long long cur = (A * (mid - L + 1));
            long long num1 = (mid * (mid - 1)) / 2 - (L - 1) * (L - 2) / 2;
            
            if (cur + num1 > M * T) {
                hi = mid;
                continue;
            }
            
            num1 *= B;
            cur += num1;
        
            if (cur <= M * T && (A + (mid - 1) * B) <= T)
                low = mid + 1;
            else
                hi = mid;
        }
        
        if (A + (L - 1) * B > M * T || (A + (L - 1) * B) > T)
            cout << "-1" << endl;
        else {
            if (low - 1 == 140294) {
                cout << L << " " << T << " " << M << endl;
                cout << A << " " << B << endl;
                
                return (0);
            }    
            
            cout << (low - 1) << endl;
        }        
    }
    
    return (0);
}