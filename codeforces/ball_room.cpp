#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

long long N, K;

int main() {
    cin >> N >> K;
        
    if (N > (K * (K - 1))) {
        cout << "NO" << endl;
        return (0);
    }
    
    cout << "YES" << endl;

    long long count = 0;

    for (long long i = 1; i <= K; i ++) {
        for (long long j = i + 1; j <= K; j ++) {
            cout << i << " " << j << endl;
            count ++;
            
            if (count == N)
                break;
            
            cout << j << " " << i << endl;
            count ++;
        
            if (count == N)
                break;
        }
        
        if (count == N)
            break;
    }

    return (0);
}