#include <iostream>

using namespace std;

int DP[500][500];
int N;

int main() {
    cin >> N;
    
    for (int i = 1; i <= N; i ++) {
        for (int j = 0; j < N; j ++) {
            DP[j][i] = 1;
        }
    }

    for (int i = 1; i <= N; i ++) {
    	for (int j = 0; j <= 30; j ++) {
	        if (DP[j][i] > 0)
	            DP[j + i][i + 1] = DP[j][i] + 1;
	    }
    }

    for (int i = 0; i < 30; i ++) {
        cout << i << " " << DP[i][N] << endl;
    }

    cout << DP[30][N] << endl;
    return (0);
}