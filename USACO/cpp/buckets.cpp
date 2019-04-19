#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAX_N 11

using namespace std;

int N, ans;

int main() {
    ifstream fin ("buckets.in");
    ofstream fout ("buckets.out");

    int sx, sy, ex, ey, bx, by;
    
    string str;
    for (int i = 0; i < 10; i ++) {
        fin >> str;
        
        for (int j = 0; j < 10; j ++) {
            if (str[j] == 'B') {
                sx = i;
                sy = j;
            }
            
            else if (st[j] == 'R') {
                bx = i;
                by = j;
            }
            
            else if (str[j] == 'L') {
                ex = i;
                ey = j;
            }
        }
    }
    
    if ((sx == ex && sx == bx && ) || (sy == ey && sy == by))
        fout <<  (abs(sx - ex) + abs(sy - ey) + 1) << endl;
    else
        fout << (abs(sx - ex) + abs(sy - ey) - 1) << endl;
        
    return (0);
}