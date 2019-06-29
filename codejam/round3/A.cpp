#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <math.h>
#include <string.h>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

string str[MAX_N];

bool win[MAX_N];

int ar[MAX_N];
int A;

int main() {
    int T;
    cin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        cin >> A;
        
        int big = 500;
        
        for (int i = 0; i < A; i ++) {
            cin >> str[i];
            big = max(big, (int)str[i].size());
            
            win[i] = false;
        }
        
        for (int i = 0; i < A; i ++) {
            string add = "";
            int sz = str[i].size();
            
            while (sz != 500) {
                add += str[i][(sz % str[i].size())];
                sz ++;
            }
            
            str[i] += add;
        }
    
        string ans = "";
    
        bool flag = false;

        for (int i = 0; i < big; i ++) {
            bool r = false, p = false, s = false;

            for (int j = 0; j < A; j ++) {
                if (win[j])
                    continue;
                
                if (str[j][i] == 'R') { r = true; }
                if (str[j][i] == 'P') { p = true; }
                if (str[j][i] == 'S') { s = true; }
            }
            
            if (r && p && s) {
                flag = true;
                break;
            }
            
            if (r && s || !r && !p && s) {
                ans += 'R';
                
                for (int j = 0; j < A; j ++)
                    if (str[j][i] == 'S')
                        win[j] = true;
            }
            
            else if (p && r || !p && r && !s) {
                ans += 'P';

                for (int j = 0; j < A; j ++)
                    if (str[j][i] == 'R')
                        win[j] = true;
            }
            
            else if (s && p || !s && !r && p) {
                ans += 'S';

                for (int j = 0; j < A; j ++)
                    if (str[j][i] == 'P')
                        win[j] = true;    
            }
        }
        
        for (int i = 0; i < A; i ++) {
            if (!win[i]) {
                flag = true;
            }
        }

        if (flag) {
            cout << "Case #" << (ii + 1) << ": IMPOSSIBLE" << endl;
            continue;
        }
        
        cout << "Case #" << (ii + 1) << ": " << ans << endl;
    }
    
    return (0);
}