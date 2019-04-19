#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 50005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

ii cow[MAX_N];

bool vis[MAX_N];

long long N, K, M;

bool pos(long long num) {
    long long big = 0;
    
    for (long long i = 0; i < num; i ++)
        big = max(big, cow[i].s);

    vector<ii> pos;
    
    for (long long i = 0; i < N; i ++) {
        if (i >= num)
            pos.push_back(ii(big - cow[i].s, i));
        else
            pos.push_back(ii(cow[i].f - cow[i].s, i));
            
        vis[i] = false;
    }
    
    sort(pos.begin(), pos.end());
    reverse(pos.begin(), pos.end());
    
    long long cst = 0ll;
    
    for (long long i = 0; i < min(num, K); i ++) {
        cst += cow[pos[i].s].s;
        vis[pos[i].s] = true;
    }
    
    for (long long i = 0, j = K; i < N && j < num; i ++) {
        if (!vis[i]) {
            cst += cow[i].f;
            j ++;        
        }   
    }
    
    return (cst <= M);
}

int main() {
    ifstream fin ("coupon.in");
    ofstream fout ("coupon.out");
    
    fin >> N >> K >> M;
    
    for (long long i = 0; i < N; i ++)
        fin >> cow[i].f >> cow[i].s;
    
    sort(cow, cow + N);

    long long low = 0;
    long long hi = N;
    
    while (low != hi) {
        long long mid = (low + hi + 1) / 2;
        
        if (pos(mid))
            low = mid;
        else
            hi = mid - 1;
    }
    
    fout << low << endl;
    return (0);
}