#include <iostream>
#include <fstream>
#include <vector>

#define MAX_R 1050
#define MAX_N 55

using namespace std;

int rail[MAX_N], board[MAX_R];
int N, R;

int DFS (int ind, int sum) {
    if (ind > N - 1) { return (0); }
    
    int a = 0;
    
    for (int i = 0; i < R; i ++) {
        if (sum + board[i] < rail[ind])
            a = max(a, DFS (ind, sum + board[i]) + 1);
        else if (sum + board[i] == rail[ind])
            a = max(a, DFS (ind + 1, 0) + 1);
        else 
            a = max(a, DFS (ind + 1, board[i]) + 1);
    }
    
    return (a);
}

int main() {
    ifstream fin ("fence8.in");
    ofstream fout ("fence8.out");
    
    fin >> N;
    for (int i = 0; i < N; i ++) { fin >> rail[i]; }
    
    fin >> R;
    for (int i = 0; i < R; i ++) { fin >> board[i]; }

    fout << (DFS (0, 0) - 1) << endl;
    return (0);
}
