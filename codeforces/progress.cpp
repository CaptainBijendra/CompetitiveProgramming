#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

int ask (int x) {
    cout << "> " << x << endl;
    cout << endl;
    
    cout.flush();
    
    int y;
    
    cin >> y;
    return (y);
}

vector<int> ar;

int N;

int main() {
    cin >> N;
    
    int low = 0;
    int hi = 1000000000;    
    int remaining = 60;
    
    while (low != hi) {
        int mid = (low + hi) / 2;
        
        if (ask(mid))
            low = mid + 1;
        else
            hi = mid;
    
        remaining --;
    }
    
    int y;
    
    for (int i = 0; i < min(remaining, N); i ++) {
        cout << "? " << (i + 1) << endl;
        cout << endl;
        
        cout.flush();
        cin >> y;
        
        ar.push_back(y);
    }
    
    ar.push_back(low);
    sort(ar.begin(), ar.end());
    
    int ans = -1;
    
    for (int i = 0; i < ar.size(); i ++) {
        for (int j = i + 1; j < ar.size(); j ++) {
            if (ans == -1)
                ans = (ar[j] - ar[i]);
            else
                ans = __gcd(ans, (ar[j] - ar[i]));
        }
    }
    
    int final_ans = ans;
    
    vector<int> fact;
    
    for (int i = 1; i * i <= ans; i ++) {
        if (ans % i == 0) {
            if (i * i == ans)
                fact.push_back(i);
            else {
                fact.push_back(i);
                fact.push_back(ans / i);
            }
        }
    }
    
    sort(fact.begin(), fact.end());
    
    for (int i = 0; i < fact.size(); i ++) {
        if (low - fact[i] * (N - 1) <= ar[0]) {
            final_ans = fact[i];
            break;
        }
    }
    
    
    cout << "! " << (low - ans * (N - 1)) << " " << ans << endl;
    return (0);
}