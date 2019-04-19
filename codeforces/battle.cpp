#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int loc[MAX_N];
int N, K, A, M;

bool pos(int moves) {
    vector<int> ar;
    
    for (int i = 0; i < moves; i ++)
        ar.push_back(loc[i]);
    
    sort(ar.begin(), ar.end());
    
    for (int i = 1; i < ar.size(); i ++) {
        if (ar[i] - ar[i - 1] <= K)
            return (false);
    }
    
    return (true);
}

int main() {
    cin >> N >> K >> A;
    cin >> M;
    
    for (int i = 0; i < M; i ++) 
        cin >> loc[i];
    
    if (M == 1) {
        cout << 1 << endl;
        return (0);
    }
    
    int low = 1;
    int hi = M + 1;
    
    while (low != hi) {
        int mid = (low + hi) / 2;
        
        if (!pos(mid))
            hi = mid;
        else
            low = mid + 1;
    }
    
    cout << (low == (M + 1) ? -1 : low) << endl;
    return (0);    
}