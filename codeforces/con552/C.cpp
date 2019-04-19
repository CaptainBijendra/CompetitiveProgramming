#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

long long ar[MAX_N];
long long A, B, C;

long long solve(long long X, long long Y, long long Z) {
    long long w1, w2, w3;
    long long r1, r2, r3;    

    w1 = (X / 3ll);
    w2 = (Y / 2ll);
    w3 = (Z / 2ll); 

    long long d;
    
    d = min(w1, min(w2, w3)) * 7ll;
    
    r1 = X - min(w1, min(w2, w3)) * 3;
    r2 = Y - min(w1, min(w2, w3)) * 2;
    r3 = Z - min(w1, min(w2, w3)) * 2;
    
    if (r1 <= 0ll) {
        return (d);
    }
    
    r1 --; d ++;
    
    if (r2 <= 0ll) {
        return (d);
    }
    
    r2 --; d ++;

    if (r3 <= 0ll) {
        return (d);
    }

    r3 --; d ++;

    if (r1 <= 0ll) {
        return (d);
    }

    r1 --; d ++;

    if (r3 <= 0ll) {
        return (d);
    }
    
    r3 --; d ++;

    if (r2 <= 0ll) {
        return (d);
    }    

    r2 --; d ++;

    if (r1 <= 0ll) {
        return (d);
    }    

    r1 --; d ++;
    return (d);
}

int main() {
    cin >> A >> B >> C;
     
    long long ans = 0ll;
    
    ans = max(ans, solve(A, B, C));
    ans = max(ans, solve(A + 1, B, C) - 1ll);
    ans = max(ans, solve(A + 1, B + 1, C) - 2ll);
    ans = max(ans, solve(A + 1, B + 1, C + 1) - 3ll);
    ans = max(ans, solve(A + 2, B + 1, C + 1) - 4ll);
    ans = max(ans, solve(A + 2, B + 1, C + 2) - 5ll);
    ans = max(ans, solve(A + 2, B + 2, C + 2) - 6ll);
    
    cout << ans << endl;
    return (0);
}