#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <stack>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

char ans[5][5];

int ar[MAX_N];
int N;

int main() {
    cin >> N;
    
    if (N < 25) {
        cout << "-1" << endl;
        return (0);
    }
    
    char ans[5] = { 'a', 'e', 'i', 'o', 'u' }; 
    
    int row = 0;
    int col = 0;
    
    for (int i = 5; i * i <= N; i ++) {
        if (N % i == 0 && (N / i) >= 5) {
            row = i;
            col = (N / i);
        }
    }
    
    if (row == 0 && col == 0) {
        cout << "-1" << endl;
        return (0);
    }
    
    for (int i = 0; i < row; i ++) {
        for (int j = 0; j < col; j ++)
            cout << ans[(i + j) % 5];
    }
    
    cout << endl;
    return (0);
}