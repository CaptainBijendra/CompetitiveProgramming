#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N, M;

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
        
    return (0);
}