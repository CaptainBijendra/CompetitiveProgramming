#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define MOD 1000000007
#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N, M;

int main() {
    cin >> N;
    
    int big = 0;
    int ans = 0;
    int streak = 0;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        big = max(big, ar[i]);
    }
    
    for (int i = 0; i < N; i ++) {
        if (big == ar[i])
            streak ++;
        else {
            ans = max(ans, streak);
            streak = 0;
        }
    }
    
    ans = max(ans, streak);
    
    cout << ans << endl;
    return (0);    
}
