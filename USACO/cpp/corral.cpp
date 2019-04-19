#include <iostream>
#include <algorithm>
#include <set>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

ii points[MAX_N];
int C, N;

int abs(int x) {
    return (x < 0 ? -x : x);
}

bool pos(int S) {
    for (int c = 0; c < N; c ++) {
        int cur_points = 1;
        
        for (int i = c + 1; i < N; i ++) {
            if (points[i].f - points[c].f < S) {
                if (points[i].s - points[c].s < S && (points[i].s >= points[c].s)) {
                    cur_points ++;
                    
                    if (cur_points >= C) {
                        return (true);
                    }
                }
            }
        }
    }
    
    return (false);
}

bool pos2(int S) {
    for (int c = 0; c < N; c ++) {
        int cur_points = 1;
        
        for (int i = c + 1; i < N; i ++) {
            if (points[i].f - points[c].f < S) {
                if (points[i].s - points[c].s < S && (points[i].s <= points[c].s)) {
                    cur_points ++;
                    
                    if (cur_points >= C) {
                        return (true);
                    }
                }
            }
        }
    }
    
    return (false);
}

int main() {
    cin >> C >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> points[i].f >> points[i].s;
    
    sort(points, points + N);
    
    int low = 1;
    int hi = 10005;
    
    while (low < hi) {
        int mid = (low + hi) / 2;
        
        if (pos(mid) || pos2(mid)) {
            hi = mid;
        }
        
        else {
            low = mid + 1;
        }
    }
    
    cout << low << endl;
    return (0);
}
