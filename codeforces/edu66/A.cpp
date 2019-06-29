#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <iomanip>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int T;

int main() {
    cin >> T;
    
    long long N, K;
    for (int ii = 0; ii < T; ii ++) {
        cin >> N >> K;
        
        long long steps = 0ll;
        while (N != 0) {
            if (N % K == 0) {
                N /= K;
                steps ++;
            }
            
            else {
                steps += (N % K);
                N -= (N % K);
            }
        }
        
        cout << steps << endl;
    }
    
    return (0);
}