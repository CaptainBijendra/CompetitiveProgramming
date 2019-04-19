#include <iostream>

using namespace std;

int main() {
    cin >> N;
    
    DP[0][1] = 1;
    DP[1][1] = 1;
	
    for (int i = 1; i <= N; i ++) {
    	for (int j = 1; j <= 30; j ++) {
	    DP[j + i + 1][i + 1] = DP[i][j] + 1;
	}
    }

    cout << DP[30][N] << endl;
    return (0);
}