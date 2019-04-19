#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 505
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

int DP[505][1024];

int ar[MAX_N][MAX_N];
int N, M;

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        if (i == 0) {
            for (int j = 0; j < M; j ++) {
                cin >> ar[i][j];
                DP[0][ar[i][j]] = j + 1;
            }
            
            continue;
        }
        
        for (int j = 0; j < M; j ++) {
            cin >> ar[i][j];
            
            for (int k = 0; k <= 1023; k ++) {
                if (DP[i - 1][k])
                    DP[i][k ^ ar[i][j]] = j + 1;
            }
        }
    }
    
    int ans = -1;
    
    for (int i = 1; i <= 1023; i ++)
        if (DP[N - 1][i]) {
            ans = i;
            break;
        }
    
    vector<int> vec;    
    
    if (ans == -1) {
        cout << "NIE" << endl;
        return (0);
    } else {
        cout << "TAK" << endl;
        
        int row = N - 1;
        
        while (row >= 0) {
            vec.push_back((DP[row][ans]));
            
            ans = (ans ^ ar[row][DP[row][ans] - 1]);
            row --;
        }   
    
        reverse(vec.begin(), vec.end());
        
        for (int i = 0; i < vec.size(); i ++)
            cout << vec[i] << " ";
        
        cout << endl;
    }
    
    return (0);
}

