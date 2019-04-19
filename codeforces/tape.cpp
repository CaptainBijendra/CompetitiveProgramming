#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K;

int main() {
    cin >> N >> M >> K;
    
    vector<int> diff;
    
    int a, prev;
    int tot = 0, big = 0;
    
    for (int i = 0; i < N; i ++) {
        cin >> a;
        
        if (i > 0)
            diff.push_back(a - prev);
        
        prev = a;
        
        if (i == 0)
            big = a;
        if (i == N - 1)
            tot = a - big + 1;
    }
    
    sort(diff.begin(), diff.end());
    reverse(diff.begin(), diff.end());
    
    for (int i = 0; i < (K - 1); i ++) {
        tot -= (diff[i] - 1);
    }

    cout << tot << endl;
    return (0);
}