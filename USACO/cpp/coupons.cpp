/*
ID: akommul1
LANG: C++
PROB: coupons
*/

#include <iostream>
#include <fstream>

#define MAX_N 20005
#define MAX_K 10005

int cost[MAX_N][MAX_K], cows[MAX_N][MAX_K], val[MAX_N], coup[MAX_N];
int N, K, M, i, j;

using namespace std;

int main() {
    ifstream fin ("coupons.in");
    ofstream fout ("coupons.out");
    
    fin >> N >> K >> M;
    
    for (i = 0; i < N; i ++) { 
        fin >> val[i] >> coup[i]; 
        cout << val[i] << " " << coup[i] << endl;
    }
    
    for (i = 0; i < N; i ++) {
        for (j = 0; j <= K; j ++) {
            if (j > 0 && cost[i - 1][j - 1] + coup[i] <= M) {
                cost[i][j] = cost[i - 1][j - 1] + coup[i];
                cows[i][j] = cows[i - 1][j - 1] + 1;
            }
            
            else if (cost[i - 1][j] + val[i] <= M){
                cost[i][j] = cost[i - 1][j] + val[i];
                cows[i][j] = cows[i - 1][j] + 1;
            }
        }
    }
    
    for (i = 0; i < N; i ++) {
        for (j = 0; j <= K; j ++) {
            cout << i << " " << j << " COST: " << cost[i][j] << " COWS: " << cows[i][j] << endl; 
        }
    }
    
    return (0);
}