#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 20
#define f first
#define s second

using namespace std;

int guard1[10][12];

int DP[MAX_N][MAX_N][MAX_N][MAX_N][12];
int N, M, A, B, X, Y;

int main() {
    cin >> N >> M;
    
    string str;
    for (int i = 0; i < N; i ++) {
        cin >> str;
    
        for (int j = 0; j < M; j ++)
            ar[i][j] = str[j];
    }
    
    cin >> A;
    
    int a, b, c;
    char d;
    
    for (int i = 0; i < A; i ++) {
        cin >> a >> b >> c >> d;
        
        for (int i = 0; i < c; i ++) {
            
        }
    }
}