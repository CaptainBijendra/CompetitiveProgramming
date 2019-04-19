#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

using namespace std;

map<long long, long long> cntr;

long long N, B;

long long cnt(long long num) {
    long long mult = num;
    long long tot = 0ll;
                
    for (long long j = 0; j <= 70; j ++) {
        tot += (N / mult);

        if ((N / mult) >= num)
            mult *= num;
        else
            break;
    }
    
    return (tot);
}

int main() {
    cin >> N >> B;    

    long long ans = -1;
    
    vector<long long> fact;
    
    for (long long i = 2; i * i <= B; i ++) {
        if (B % i == 0)
            fact.push_back(i);

        while (B % i == 0) {
            cntr[i] ++;
            B /= i;
        }
    }

    if (B >= 2) {
        cntr[B] ++;
        fact.push_back(B);
    }
    
    for (long long i = 0; i < fact.size(); i ++) {
        if (i > 0 && fact[i] == fact[i - 1])
            continue;
        else {
            if (ans == -1)
                ans = (cnt(fact[i]) / cntr[fact[i]]);
            else
                ans = min(ans, (cnt(fact[i]) / cntr[fact[i]]));
        }
    }

    cout << ans << endl;
    return (0);
}