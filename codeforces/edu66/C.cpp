#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <iomanip>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N, K;

int main() {
    int T;
    cin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        cin >> N >> K;
        
        int small = 2000000000;
        int val = -1;
        for (int i = 0; i < N; i ++) {
            cin >> ar[i];
        }
        
        for (int i = 0; i < N - K; i ++) {
            int mid = (ar[i] + ar[i + K]) / 2;
                
            if (small > max(mid - ar[i], ar[i + K] - mid)) {
                small = max(mid - ar[i], ar[i + K] - mid);
                val = mid;
            }
        }
        
        cout << val << endl;
    }
    
    return (0);
}