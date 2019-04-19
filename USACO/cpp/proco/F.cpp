#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair <int, int> ii;
int N;
ii X[MAX_N];

bool solve(double t) {
    double minValue = X[0].f+X[0].s*t;
    for(int i=1; i<N; i++) {
        double cand = X[i].f+X[i].s*t;
        if(cand >= minValue)
            return true;
        minValue = cand;
    }
    return false;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> X[i].f >> X[i].s;
    
    sort(X, X+N);
    
    long long smallestV = X[0].s;
    for(int i=1; i<N; i++) {
        if(smallestV > X[i].s)
            break;
        smallestV = X[i].s;
        if(i == N-1) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    double e = 0.00000001;
    double l = 0;
    double h = 1000000000;
    while(l+e < h) {
        double mid = (l+h)/2;
        bool good = solve(mid);
        if(good)
            l = mid;
        else
            h = mid;
    }

    cout << l << endl;
    return (0);    
}