/*
ID: akommul1
LANG: C++
PROB: frameup
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_H 32
#define INF 200000000

using namespace std;

struct letter {
    int x1, y1;
    int x2, y2;
};

letter coord[26];

vector<string> sol;

bool ov_lap[26][26];
bool in_frame[26], val[26];

char ans[26];

int grid[MAX_H][MAX_H];
int H, W, num_char;

void DFS (int sz) { 
    if (sz == num_char)
    { sol.push_back(ans); return; }

    for (int i = 0; i < 26; i ++) {
        if (!in_frame[i] && val[i]) {
            bool flag = false;

            for (int j = 0; j < 26; j ++) {
                if (in_frame[j] && ov_lap[j][i]) { break; }
                if (j == 25) { flag = true; }
            } 

            if (flag) {
                in_frame[i] = 1; ans[sz] = (char) (i + 65);
                DFS (sz + 1);
                in_frame[i] = 0; ans[sz] = '0';
            }
        }
    }
}

int main() {
    ifstream fin ("frameup.in");
    ofstream fout ("frameup.out");

    for (int i = 0; i < 26; i ++) {
        coord[i].x1 = INF; coord[i].y1 = INF;
        coord[i].x2 = 0; coord[i].y2 = 0;
    }

    fin >> H >> W;

    for (int i = 0; i < H; i ++) {
        for (int j = 0; j < W; j ++) { 
            char in_char;

            fin >> in_char; 
            
            grid[i][j] = (in_char) - 'A';

            coord[grid[i][j]].x1 = min(i, coord[grid[i][j]].x1);
            coord[grid[i][j]].y1 = min(j, coord[grid[i][j]].y1);

            coord[grid[i][j]].x2 = max(i, coord[grid[i][j]].x2);
            coord[grid[i][j]].y2 = max(j, coord[grid[i][j]].y2);  
        }
    }

    for (int i = 0; i < 26; i ++) {
        for (int j = 0; j < 26; j ++) {
            if (i == j) { continue; }

            letter a = coord[i];
            letter b = coord[j];

            if ((min(a.x2, b.x2) - max(a.x1, b.x1)) >= 0 && (min(a.y2, b.y2) - max(a.y1, b.y1)) >= 0) {
                bool flag = false;
                
                for (int w = a.x1; w <= a.x2; w ++) { flag = (grid[w][a.y1] == j ? true : flag); }
                for (int x = a.y1; x <= a.y2; x ++) { flag = (grid[a.x1][x] == j ? true : flag); }
                for (int y = a.x1; y <= a.x2; y ++) { flag = (grid[y][a.y2] == j ? true : flag); }
                for (int z = a.y1; z <= a.y2; z ++) { flag = (grid[a.x2][z] == j ? true : flag); }

                if (flag) { ov_lap[j][i] = true; }
            }
        }
    }
    
    for (int i = 0; i < 26; i ++) { 
        num_char += (coord[i].x1 != INF);
        val[i] = (coord[i].x1 != INF);
    }
   
    cout << num_char << endl;

    DFS (0);
   
    for (int i = 0; i < sol.size(); i ++) { fout << sol[i] << endl; }

    return (0);
}
