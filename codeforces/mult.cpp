#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

#define MOD 1000
#define MAX_N 100005
#define f first
#define s second

using namespace std;

long long ar[MAX_N], DP[MAX_N * 10];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
        
    long long ans = 0ll;
    
    DP[0] = 1;

    for (int i = 0; i < N; i ++) {
        vector<int> fact;
        
        for (int j = 1; j * j <= ar[i]; j ++) {
            if (ar[i] % j == 0) {
                if (j * j == ar[i])
                    fact.push_back(j);
                else {
                    fact.push_back(j);
                    fact.push_back((ar[i] / j));
                }
            }
        }    
        
        sort(fact.begin(), fact.end());
        reverse(fact.begin(), fact.end());
        
        for (int j = 0; j < fact.size(); j ++) {
            DP[fact[j]] += DP[fact[j] - 1];
            DP[fact[j]] %= MOD;
        }
    }
    
    for (int i = 1; i < MAX_N * 10; i ++) {
        ans += DP[i];
        ans %= MOD;
    }
    
    cout << ans << endl;
    return (0); 
}