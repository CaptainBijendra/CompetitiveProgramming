#include <iostream>
#include <fstream>

#define INF 1000000009
#define MAX_N 10005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

ii ar[MAX_N];

int N, M;

ii min_ind(ii a, ii b) {
    if (a.f < b.f) { return (a); }
    else if (a.f == b.f) { return (a.f < b.f ? a : b); }
    return (b);
}

ii max_ind(ii a, ii b) {
    if (a.f < b.f) { return (b); }
    else if (a.f == b.f) { return (a.f > b.f ? a : b); }
    return (a);
}

int abs(int x) {
    return (x < 0 ? -x : x);
}

int calc(ii a, ii b) {
    int depth_d = 2 * abs(b.f - a.f) - 1;
    
    int left = a.s;
    int right = min(N, a.s + 2 * abs(b.f - a.f));
    
    if (b.s < left) {
        return (depth_d + abs(b.s - left) + 1);
    }
    
    else if (b.s > right) {
        return (depth_d + abs(b.s - right) + 1);
    }
    
    return (depth_d);
}

int main() {
    int sx, sy;
    
    cin >> N >> M;
    cin >> sx >> sy;
    
    int min_ans = INF;
    int min_x = -1, min_y = -1;
    
    for (int i = 0; i < M; i ++) { 
        cin >> ar[i].f >> ar[i].s;
            
        ii up = (min_ind(ii(sx, sy), ar[i]));
        ii down = (max_ind(ii(sx, sy), ar[i]));
        
        ii lft = up;
        lft.s = max(1, lft.s - 1);
        
        ii rght = up;
        rght.s = min(N, rght.s + 1);
        
        int sol;
        
        if (up.s % 2 == 1) 
            sol = calc(up, down) + 1;
        else 
            sol = min(calc(up, lft) + 2, calc(up, rght) + 2);
        
        if (sol < min_ans) {
            min_ans = sol;
            min_x = ar[i].f;
            min_y = ar[i].s;
        }
            
        if (sol == min_ans) {
            if (min_x >= ar[i].f) {
                min_x = ar[i].f;
                
                if (min_y >= ar[i].s)
                    min_y = ar[i].s;
            }
        }
    }
    
    cout << min_x << " " << min_y << endl;
    cout << min_ans << endl;
    return (0);
}