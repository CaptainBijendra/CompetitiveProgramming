#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 25005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> pii;

vector<pii> r;

int N;

int main() {
    cin >> N;
    
    int a, b, c, d;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b >> c >> d;
        r.push_back(pii(ii(a, b), ii(c, d)));
    }
    
    int tot = 0;
    
    for (int i = 0; i < N; i ++) {
        bool flag = true;
        
        for (int j = 0; j < N; j ++) {
            if (i == j) { continue; }
        
            int a = r[i].f.f - 1;
            int b = r[i].f.s - 1;
            int c = r[i].s.f + 1;
            int d = r[i].s.s + 1;
            
            int w = r[j].f.f;
            int x = r[j].f.s;
            int y = r[j].s.f;
            int z = r[j].s.s;
            
            int x1 = max(a, w);
            int y1 = max(b, x);
            int x2 = min(c, y);
            int y2 = min(d, z);
            
            if (x1 < x2 && y1 < y2) {
                flag = false;
                break;
            }
        }
        
        tot += flag;
    }
    
    cout << tot << endl;
    return (0);
}
