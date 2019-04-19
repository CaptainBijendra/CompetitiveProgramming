#include <iostream>
#include <fstream>

#define MAX_N 1005

using namespace std;

int DP[5][MAX_N];
int N;

int main() {
    ifstream fin ("vans.in");
    ofstream fout ("vans.out");
    
    fin >> N;
    
    DP[2][2] = 1;
    DP[2][3] = 1;
    DP[2][4] = 1;
    
    for (int i = 3; i <= N; i ++) { DP[i][2] = 1; }
    
    for (int i = 3; i <= 4; i ++) {
        for (int j = 3; j <= N; j ++) {
            if ((i % 2 == 1) && (j % 2 == 1)) { continue; }
            
            int sA, sB;
            
            for (int k = 2; k <= j / 2; k ++) {
                sA = DP[i][j - k];
                sB = DP[i][k];
                
                DP[i][j] += (sA - (j - 2)) * 3 * sB;
                DP[i][j] += (sB - (j - 2)) * 3 * sA;
            }
        }
    }
    
    for (int i = 3; i <= 4; i ++) {
        for (int j = 3; j <= N; j ++) {
            cout << i << " " << j << " " << DP[i][j] << endl;
        }
    }
    
    return (0);
}