#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>

#define MAX_N 7
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;
typedef pair<ii, ii> pii;

struct state {
    long long st;    
    
    vector<pii> moves;
    int num;
};

map<long long, bool> cmp;
ii pos[5];

bool ar[MAX_N][MAX_N];
int N;

queue<state> q;

bool valid_loc(int row, int col) {
    // locations outside the square
    if (row < 0 || row > 6 || col < 0 || col > 6) return false;
    // locations inside corners
    if ((row == 0 || row == 1 || row == 5 || row == 6) &&
                                    (col < 2 || col > 4)) return false;
    return true;
}

long long set(long long cur, int row, int col, bool value) {
    cur ^= (-value ^ cur) & (1UL << (row * MAX_N + col));
    return (cur);
}

bool get(long long cur, int row, int col) {
    return ((cur >> (row * MAX_N + col)) & 1U);
}

int main() {
    state start;
    start.st = 0;
    start.num = 0;
    
    for (int i = 0; i < MAX_N; i ++) { 
        for (int j = 0; j < MAX_N; j ++) {
            if (valid_loc(i, j)) {
                start.st = set(start.st, i, j, 1);
            }
        }
    }
    
    start.st = set(start.st, 3, 3, 0);
    state next;
    
    q.push(start);        

    int cur_cnt = 0;
        
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
    
        if (cur.num == cur_cnt) {
            cout << cur.num << endl;
            cur_cnt ++;
    
            for (int i = 0; i < MAX_N; i ++) {
                for (int j = 0; j < MAX_N; j ++) 
                    cout << get(cur.st, i, j);
            
                cout << endl;
            }
        
            cout << "__________________" << endl;
        }
        
        if (cur.num == 31) {
            
            for (int i = 0; i < cur.num; i ++)
                cout << "MOVE " << i << ": " << cur.moves[i].f.f << " " << cur.moves[i].f.s << " " << cur.moves[i].s.f << " " << cur.moves[i].s.s << endl;
            
            break;
        }
        
        for (int i = 0; i < MAX_N; i ++) {
            for (int j = 0; j < MAX_N; j ++) {
                if (valid_loc(i, j) && get(cur.st, i, j)) {
                    int ln = 0;
                    int row = i, col = j;
                
                    //Going up
                    if (valid_loc(row - 2, col)) { 
                        if (!get(cur.st, row - 2, col) && get(cur.st, row - 1, col)) { 
                            pos[ln ++] = ii(-2, 0);
                        }
                    }
                    
                    //Going right
                    if (valid_loc(row, col + 2)) { 
                        if (!get(cur.st, row, col + 2) && get(cur.st, row, col + 1)) { 
                            pos[ln ++] = ii(0, 2);
                        }
                    }
                    
                    //Going down
                    if (valid_loc(row + 2, col)) {
                        if (!get(cur.st, row + 2, col) && get(cur.st, row + 1, col)) { 
                            pos[ln ++] = ii(2, 0);
                        }
                    }
                    
                    //Going left
                    if (valid_loc(row, col - 2)) { 
                        if (!get(cur.st, row, col - 2) && get(cur.st, row, col - 1)) { 
                            pos[ln ++] = ii (0, -2);
                        }
                    }
                    
                    for (int k = 0; k < ln; k ++) {
                        next.st = cur.st;
                        next.num = cur.num + 1;
                            
                        next.st = set(next.st, i, j, 0);
                        next.st = set(next.st, i + pos[k].f / 2, j + pos[k].s / 2, 0);
                        next.st = set(next.st, i + pos[k].f, j + pos[k].s, 1);
                            
                        next.moves.push_back(pii(ii(i, j), ii(i + pos[k].f, j + pos[k].s)));

                        if (!cmp[next.st]) {
                            cmp[next.st] = true;
                            q.push(next);
                        }
                    }
                }
            }
        }
    }

    return (0);
}