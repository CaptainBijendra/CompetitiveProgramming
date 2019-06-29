#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <iomanip>

#define MAX_N 400005
#define f first
#define s second

using namespace std;

long long ar[MAX_N], suf[MAX_N];
int N, K;

int main() {
    cin >> N >> K;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i]; 
    
    if (N == K) {
        long long ans = 0ll;
        
        for (int i = 0; i < N; i ++) {
            ans += ar[i] * (i + 1);    
        }
        
        cout << ans << endl;
        return (0);
    }
    
    vector<long long> vc;
    for (int i = N - 1; i >= 0; i --) {
        suf[i] = suf[i + 1] + ar[i];
        
        if (i != 0)
            vc.push_back(suf[i]); 
    }
    
    long long ans = suf[0];
    
    sort(vc.begin(), vc.end());
    
    for (int i = vc.size() - 1; i > vc.size() - K; i --)
        ans += vc[i];
    
    cout << ans << endl;
    return (0);
}