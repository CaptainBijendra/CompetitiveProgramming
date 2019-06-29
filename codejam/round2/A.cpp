#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

char C[MAX_N];

int X[MAX_N], Y[MAX_N];
int P, Q, T;

int main() {
    cin >> T;
    
    for (int ii= 0; ii < T; ii ++) {
        cin >> P >> Q;
        
        int up_y = Q, low_y = 0;
        int up_x = Q, low_x = 0;
        
        int x, y;
        char c;
        
        for (int j = 0; j < P; j ++)
            cin >> X[j] >> Y[j] >> C[j];
        
        int y_big = 0;
        int big = 0;
        
        for (int i = 0; i <= Q; i ++) {
            int cur = 0;
            
            for (int j = 0; j < P; j ++) {
                if (C[j] == 'N' && Y[j] + 1 <= i)
                    cur ++;
                if (C[j] == 'S' && Y[j] - 1 >= i)
                    cur ++;
            }
            
            if (cur > big) {
                big = cur;
                y_big = i;
            }
        }
        
        int x_big = 0;
        big = 0;
        
        for (int i = 0; i <= Q; i ++) {
            int cur = 0;
            
            for (int j = 0; j < P; j ++) {
                if (C[j] == 'W' && X[j] - 1 >= i)
                    cur ++;
                if (C[j] == 'E' && X[j] + 1 <= i)
                    cur ++;
            }
            
            if (cur > big) {
                big = cur;
                x_big = i;
            }
        }
        
        cout << "Case #" << (ii + 1) << ": " << x_big << " " << y_big << endl;
    }

    return (0);
}