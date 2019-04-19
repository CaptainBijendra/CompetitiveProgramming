#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define MOD 1000000007
#define MAX_N 100005
#define f first
#define s second

using namespace std;

string str;

long long cst[MAX_N], dx[MAX_N], dy[MAX_N];
long long N, M;

int main() {
    long long x, y;
    long long x2, y2;
    
    cin >> x >> y;
    cin >> x2 >> y2;
    
    cin >> N;
    cin >> str;
    
    for (long long i = 0; i < N; i ++) {
        if (i != 0) {
            dx[i] = dx[i - 1];
            dy[i] = dy[i - 1];
        }
        
        if (str[i] == 'U')
            dy[i] ++;
        if (str[i] == 'D')
            dy[i] --;
        if (str[i] == 'R')
            dx[i] ++;
        if (str[i] == 'L')
            dx[i] --;
    }
    
    long long low = 0;
    long long hi = 20000000000000000ll;
    
    while (low < hi) {
        long long mid = (low + hi) / 2;
        
        long long ddx = dx[N - 1] * (mid / N) + (mid % N == 0 ? 0 : dx[mid % N - 1]);
        long long ddy = dy[N - 1] * (mid / N) + (mid % N == 0 ? 0 : dy[mid % N - 1]);
        
        if (abs(x2 - (x + ddx)) + abs(y2 - (y + ddy)) <= mid)
            hi = mid;
        else
            low = mid + 1;
    }
    
    cout << (low >= 20000000000000000ll ? -1 : low) << endl;
    return (0);    
}
