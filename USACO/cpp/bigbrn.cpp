/*
ID: akommul1
LANG: C++
PROB: bigbrn
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int min(int a, int b) { if (a > b) { return (b); } return (a); }
int max(int a, int b) { if (a > b) { return (a); } return (b); }

int main() {
    ofstream fout ("bigbrn.out");
    ifstream fin ("bigbrn.in");

    int N, T, x, y, ans;
    bool flag;

    fin >> N >> T;

    bool graph[1000][1000];
    int DP[1000][1000];

    for (int i = 0; i < N; i ++) { 
        for (int j = 0; j < N; j ++) { 
            graph[i][j] = false;
            DP[i][j] = 1;
        }
    }

    for (int i = 0; i < T; i ++) {
        fin >> x >> y;
        graph[x - 1][y - 1] = true;
    }
    
    for (int i = N - 2; i >= 0; i --) {
        for (int j = N - 2; j >= 0; j --) {
            if (!graph[i][j]) {
                flag = true;
                x = 0; y = 0;

                for (int k = j; k < j + DP[i + 1][j + 1] + 1; k ++) {
                    if (graph[i][k]) { flag = false; break; }
                    x ++;
                }

                for (int l = i; l < i + DP[i + 1][j + 1] + 1; l ++) {
                    if (graph[l][j]) { flag = false; break; }
                    y ++;
                }

                if (flag) {
                    if (!graph[i + 1][j + 1]) { DP[i][j] = DP[i + 1][j + 1] + 1; }
                }

                else {
                    DP[i][j] = min(x, y);
                }
            }
        }
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            ans = max(ans, DP[i][j]);
        }
    }

    fout << ans << endl;
    return (0);
}