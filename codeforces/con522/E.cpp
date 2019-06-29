#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>   
#include <vector>
#include <map>
#include <set>
#include <iomanip>

#define MAX_N 105
#define f first
#define s second

using namespace std;

int ar[MAX_N], DP[MAX_N * MAX_N];
int N, M;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    DP[0] = 1;

    for (int j = 0; j < N; j ++) {
        for (int i = MAX_N * MAX_N - ar[j] - 1; i >= 0; i --) {
            DP[i + ar[j]] += DP[i];
        }
    }
    
    for (int i = 0; i < 13; i ++)
        cout << i << " " << DP[i] << endl;
    
    return (0);
}