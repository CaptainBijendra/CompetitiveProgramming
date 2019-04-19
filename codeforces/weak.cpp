#include <iostream>
#include <algorithm>
#include <iomanip> 
#include <math.h>

#define MAX_N 200005
#define eps 0.000000000001
#define f first
#define s second

using namespace std;

long double ar[MAX_N];
int N;

long double abs(long double x) {
    return (x < 0.0 ? -1.0 * x : x);
}

long double f(long double x) {
    long double cur_big = 0.0, cur_small = 0.0;
    long double ans = 0.0;
    
    for (int i = 0; i < N; i ++) {
        cur_big = max((long double)0.0, cur_big + (ar[i] - x));
        ans = max(ans, cur_big);
    }
    
    for (int i = 0; i < N; i ++) {
        cur_small = min((long double)0.0, cur_small + (ar[i] - x));
        ans = max(ans, abs(cur_small));
    }
    
    return (ans);
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    long double l = -10000.0;
    long double r = 10000.0;
    
    while (r - l > eps) {
        long double p1 = l + (r - l) / 3;
        long double p2 = r - (r - l) / 3;
        
        if (f(p1) < f(p2))
            r = p2;
        else
            l = p1;
    }
    
    cout << setprecision(20) << f(l) << endl;
    return (0);    
}