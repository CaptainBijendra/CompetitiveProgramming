#include <iostream>
#include <fstream>

#define MAX_V 100000
#define MAX_N 105
#define MAX_B 25

int cows[MAX_N], breed[MAX_B], DP[MAX_V];
int N, B, i, j;

using namespace std;

int main() {
    ifstream fin ("moomoo.in");
    ofstream fout ("moomoo.out");

    fin >> N >> B;

    for (i = 0; i < B; i ++) { fin >> breed[i]; DP[breed[i]] = 1; }
    for (i = 0; i < N; i ++) { fin >> cows[i]; }

    for (i = 0; i < MAX_V; i ++) {
        for (j = 0; j < B; j ++) {
            if (DP[i] > 0 && i + breed[j] < MAX_V) {
                DP[i + breed[j]] = DP[i] + 1;
            }
        }
    }

    int ans, c;

    for (i = 0; i < N; i ++) {
        ans += DP[cows[i]];
        c = 1;
         
        for (j = 0; j < N; j ++) { cout << cows[j] << endl; }
        
        for (j = i + 1; j < N; j ++) {
            if (cows[i] - c > 0) {
                cows[j] = cows[j] - (cows[i] - c);
                c ++;
            }

            else {
                break;
            }
        }
    }

    fout << ans << endl;
    return (0);
}

