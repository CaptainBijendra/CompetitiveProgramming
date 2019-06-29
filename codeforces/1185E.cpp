#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 2005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

char ar[MAX_N][MAX_N];

vector<int> vc[255];

int T, N, M;

int main() {
    cin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        cin >> N >> M;
        
        bool flag = false;
        
        string str;
        for (int i = 0; i < N; i ++) {
            cin >> str;
            
            for (int j = 0; j < M; j ++) {
                ar[i][j] = str[j];   
                vc[ar[i][j]]
            
                if (ar[i][j] != '.')
                    flag = true;
            }
        }
        
        if (!flag) {
            cout << "YES" << endl;
            cout << "0" << endl;
            
            continue;
        }
        
        for (int i = 0; i < 26; i ++) {
            
        }

    }
}