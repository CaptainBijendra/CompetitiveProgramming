#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

double ar[MAX_N];
double ar2[MAX_N];

int N;

bool pos(double x) {
    for (int i = 0; i < N; i ++)
        ar2[i] = ar[i] - x;
    
    double best = -(long long)MAX_N * (long long)MAX_N * 1.0;
    double cur = 0.0;
    double sum = ar2[0] + ar2[N - 1];
    
    for (int i = 1; i < N - 1; i ++) {
        if (cur < 0.0)
            cur = 0.0;
            
        cur += ar2[i];
        sum += ar2[i];
        best = max(best, cur);
    }
    
    return (best >= sum);
}

int main() {
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
    
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
        
    double low = 0.0;
    double hi = 100000.0;
    
    while ((long long)round(low * 10000000.0) < (long long)round(hi * 10000000.0)) {
        double mid = (low + hi) / 2;
        
        if (pos(mid))
            hi = mid;
        else
            low = mid;
    }
    
    printf("%0.3f\n", low);
    return (0);
}