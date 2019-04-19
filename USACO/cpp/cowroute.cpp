#include <iostream>
#include <fstream>

#define MAX_N 1005
#define MAX_INT 10000000

int w[MAX_N][MAX_N], dist[MAX_N], tree[MAX_N];
int i, j, k, l, A, B, N, cost, MIN, mI;

using namespace std;

int main() {
    ifstream fin ("cowroute.in");
    ofstream fout ("cowroute.out");
    
    fin >> A >> B >> N;
    
    for (i = 0; i < N; i ++) {
        fin >> k >> l;
        
        for (j = 0; j < l; j ++) { 
            fin >> cost;
            w[i][cost - 1] = k;
        }
    }
    
    for (i = 0; i < N; i ++) {
        dist[i] = MAX_INT;
    }

    dist[A - 1] = 0;
    cost = 0;
    
    for (i = 0; i < N; i ++) {
        MIN = MAX_INT;
        mI = 0;
        
        for (j = 0; j < N; j ++) {
            if (i != j && dist[j] < MIN && !tree[j]) {
                MIN = dist[j];
                mI = j;
            }
        }
        
        tree[mI] = true;
        cost += MIN;
        
        for (j = 0; j < N; j ++) {
            if (w[i][j] != 0 && dist[i] + w[i][j] < dist[j]) {
                dist[j] = dist[i] + w[i][j];
            }
        }
    }
    
    fout << cost << endl;
    return (0);
}
