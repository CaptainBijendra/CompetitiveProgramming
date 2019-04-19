#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>

#define MAX_N 30005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> p;

int N;

int main() {
    cin >> N;
    
    int a, b;
    int a1 = 10;

    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
        p.push_back(ii(a, b));
    }

    int pos = (N <= a1);

    if (pos) {
        int min_d = 1000000005;
        int ans = 0;
        
        for (int i = -1005; i <= 1005; i ++) { 
            for (int j = -1005; j <= 1005; j ++) { 
                int tot = 0;
                bool flag = true;
                
                for (int k = 0; k < N; k ++) {
                    if (i == p[k].f && j == p[k].s) {
                        flag = false;
                        break;
                    }
                    
                    tot += abs(p[k].f - i) + abs(p[k].s - j);
                }
                
                if (flag)
                    min_d = min(min_d, tot);
            }
        }
        
        for (int i = -1005; i <= 1005; i ++) { 
            for (int j = -1005; j <= 1005; j ++) { 
                int tot = 0;
                bool flag = true;
                
                for (int k = 0; k < N; k ++) {
                    if (i == p[k].f && j == p[k].s) {
                        flag = false;
                        break;
                    }
                
                    tot += abs(p[k].f - i) + abs(p[k].s - j);
                }
                
                if (flag && tot == min_d)
                    ans ++;
            }
        }
        
        cout << min_d << " " << ans << endl;
        return (0);
    }
    
    int min_y = 1000000005;
    
    for (int i = -10005; i <= 10005; i ++) {
        int dist_y = 0;
        
        for (int j = 0; j < N; j ++)
            dist_y += (abs(p[j].s - i));
            
        min_y = min(min_y, dist_y);
    }
    
    int cnt = 0;
    int st_y = -1000000005;
    
    for (int i = -10005; i <= 10005; i ++) {
        int dist_y = 0;
        
        for (int j = 0; j < N; j ++)
            dist_y += (abs(p[j].s - i));
        
        if (dist_y == min_y) {
            if (st_y == -1000000005)
                st_y = i;
                
            cnt ++;
        }        
    }    
    
    int min_x = 1000000005;
    int ans = 1000000005;
    int ans2 = 0, len = 0, st_x = -1000000005;
    
    for (int i = -10005; i <= 10005; i ++) {
        int dist_x = 0;

        for (int j = 0; j < N; j ++) 
            dist_x += (abs(p[j].f - i));
            
        min_x = min(min_x, dist_x);
        ans = min(ans, dist_x + min_y);
    }
    
    for (int i = -10005; i <= 10005; i ++) {
        int dist_x = 0;

        for (int j = 0; j < N; j ++)
            dist_x += (abs(p[j].f - i));
        
        if (dist_x == min_x) {
            if (st_x == -1000000005)
                st_x = i;
                
            len ++; 
        }
    }
    
    ans2 = (len * cnt);
    
    int end_x = st_x + len - 1;
    int end_y = st_y + cnt - 1;
    
    for (int i = 0; i < N; i ++) {
        if (p[i].f >= st_x && p[i].f <= end_x && 
            p[i].s >= st_y && p[i].s <= end_y) {
                ans2 --;
        }
    }

    cout << ans << " " << ans2 << endl;
    return (0);    
}