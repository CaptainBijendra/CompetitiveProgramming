#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 55
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

ii cow[MAX_N];

int dx[MAX_N], dy[MAX_N];
int N;

bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> cow[i].f >> cow[i].s >> dx[i] >> dy[i];
    }

    cout << collinear(cow[0].f, cow[0].s, cow[1].f, cow[1].s, cow[2].f, cow[2].s) << endl;

    int ans = 1;

    for (int ii = 0; ii < 25000; ii ++) {
        for (int i = 0; i < N; i ++) {
            for (int j = i + 1; j < N; j ++) {
                int cnt = 2;
                
                for (int k = j + 1; k < N; k ++) {
                    if (collinear(cow[i].f, cow[i].s, cow[j].f, cow[j].s, cow[k].f, cow[k].s)) {
                        cnt ++;
                    }
                }
                
                ans = max(ans, cnt);
            }
        }
        
        for (int j = 0; j < N; j ++) {
            cow[j].f += dx[j]; 
            cow[j].s += dy[j];
        }
    }
     
    cout << ans << endl;   
    return (0);
}