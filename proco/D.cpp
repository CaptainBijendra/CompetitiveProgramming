#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <set>

#define MAX_N 100005
#define eps 0.00000001
#define f first
#define s second

using namespace std;

typedef pair<long double, long double> ii;
typedef pair<ii, long double> pii;

bool vis[MAX_N];

pii ar[MAX_N];
ii ar1[MAX_N];

int N;

long double abso(long double a) {
    return (a < 0 ? -a : a);
}

pii val (long double phi, long double theta, long double x) {
    return (pii(ii((1 + x) * abso(cos(phi)) * cos(theta), (1 + x) * abso(cos(phi)) * sin(theta)), (1 + x) * (long double)sin(phi)));
}

long double sq(long double a) {
    return (a * a);
}

long double dist(pii a, pii b) {
    long double sum = sq(a.f.f - b.f.f) + sq(a.f.s - b.f.s) + sq(a.s - b.s);

    return (sum);
}

bool pos(long double x) {
    for (int i = 0; i < N; i ++) {
        vis[i] = false;
        ar[i] = val(ar1[i].f, ar1[i].s, x);
    }
    
    queue<int> q;
    q.push(0);
    
    vis[0] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < N; i ++) {
            if (vis[i]) { continue; }
            if (dist(ar[i], ar[cur]) / 4.0 + 1.0 <= sq(1 + x)) {
                q.push(i);
                
                vis[i] = true;
            }
        }
    }
    
    for (int i = 0; i < N; i ++) {
        if (!vis[i]) 
            return (false);
    }
    
    return (true);
}

int main() {
    cin >> N;
    
    long double x, y;
    char a, b;
    for (int i = 0; i < N; i ++) {
        cin >> x >> a >> y >> b;
        
        if (a == 'S')
            x *= -1.0;
        if (b == 'E')
            y *= -1.0;
        
        ar1[i] = ii(x*3.14159265358979323846/180.0, y*3.14159265358979323846/180.0);
    }
    
        long double low = 0.0;
        long double hi = 100.0;
        
        for (int j = 0; j < 1000; j ++) {
            long double mid = (low + hi) / 2.0;
            
            if (pos(mid))
                hi = mid;
            else
                low = mid;
        }
        
        cout << fixed << setprecision(18) << low << endl;
    
    return (0);
}