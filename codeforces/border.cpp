#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int vis[100005];
int N, K;

int main() {
    cin >> N >> K;
    
    int ans = -1;
    int x;
    
    for (int i = 0; i < N; i ++) {
        cin >> x;
        x %= K;
    
        if (ans == -1)
            ans = x;
        else
            ans = __gcd(ans, x);
    }
    
    vector<int> sol;
    
    for (int i = ans; !vis[i % K]; i += ans) {
        sol.push_back((i % K));
        vis[(i % K)] = true;
        
        i %= K;
    }
    
    sort(sol.begin(), sol.end());
    cout << sol.size() << endl;
    
    for (int i = 0; i < sol.size(); i ++)
        cout << sol[i] << " ";
    
    cout << endl;
    return (0);
}