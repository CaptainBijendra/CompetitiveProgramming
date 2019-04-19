#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 20005
#define f first
#define s second

using namespace std;

priority_queue<long long> q;

long long ar[MAX_N];
long long N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        q.push(-ar[i]);
    }
    
    long long ans = 0ll;
    
    while (q.size() > 1) {
        int f1 = -1 * q.top(); q.pop();
        int f2 = -1 * q.top(); q.pop();
        
        ans += (f1 + f2);
        q.push(-1 * (f1 + f2));
    }

    cout << ans << endl;
    return (0);
}