#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

int ar[MAX_N];
int N, M, C;

int main() {
    cin >> N >> M >> C;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    sort(ar, ar + N);
    
    int need = (N / M);
    int streak = 0;
    int ans = 0;
    
    for (int i = need; i + need < N; i += need) {
        if (i >= N)
            break;
            
        ans = max(ans, ar[i] - ar[i - need + 1]);
    }
    
    return (0);
}