#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <set>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int ar[MAX_N];
int N;

int main() {
        long long q;
        cin >> q;
    
        for (int i = 0; i < q; i ++) {
            long long c;
            cin >> c;
            long long Q = 1;
            
            for (long long j = 2; j <= 10000; j ++) {
                while (c % (j * j * j) == 0) {
                    c /= (j * j * j);
                    Q *= j;
                }
            }
            
            long long n = Q * c;
            long long m = c;
            
            if (n == m) {
                n *= 4;
                m *= 8;
            }
            
            cout << n << " " << m << endl;
        }
        
}