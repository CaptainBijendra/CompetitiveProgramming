#include <iostream>
#include <algorithm>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N, M, K;

bool pos(int ind) {
    int box = 0;
    int cur_sum = 0;
    
    for (int i = ind; i < N; i ++) {
        cur_sum += ar[i];
        
        if (cur_sum == K) { 
            cur_sum = 0;
            box ++;
        }
        
        if (cur_sum > K) {
            cur_sum = ar[i];
            box ++;
        }
        
        if (box > M)
            return (false);
    }
        
    if (cur_sum == 0)
        return (true);
    else
        return (box + 1 <= M);
}

int main() {
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    int low = 0;
    int hi = N;
    
    while (low < hi) {
        int mid = (low + hi) / 2;
        
        if (pos(mid))
            hi = mid;
        else
            low = mid + 1;
    }
    
    cout << (N - low) << endl;
    return (0);
}