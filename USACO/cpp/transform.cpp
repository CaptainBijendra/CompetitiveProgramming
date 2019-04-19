#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 12
#define f first
#define s second

using namespace std;

int ar[MAX_N][MAX_N], tar[MAX_N][MAX_N], tmp[MAX_N][MAX_N];
int N;

bool eq() {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (ar[i][j] != tar[i][j]) {
                return (false);
            }
        }
    }
    
    return (true);
}

void rotate() {
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            tmp[i][j] = ar[i][j];
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            ar[i][j] = tmp[N - 1 - j][i];
        }
    }
}

void reflect() {
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            tmp[i][j] = ar[i][j];
        
    for (int i = 0; i < N; i ++) 
        for (int j = 0; j < N; j ++)
            ar[i][j] = tmp[i][N - 1 - j];
}

int main() {
    cin >> N;
    
    string str;
    for (int i = 0; i < N; i ++) {
        cin >> str;
        
        for (int j = 0; j < N; j ++) 
            ar[i][j] = str[j];           
    }
    
    for (int i = 0; i < N; i ++) {
        cin >> str;
        
        for (int j = 0; j < N; j ++) 
            tar[i][j] = str[j];           
    }
    
    for (int i = 1; i <= 3; i ++) {
        rotate();
            
        if (eq()) {
            cout << i << endl;
            return (0);
        }    
    }
        
    rotate();
    reflect();
        
    if (eq()) {
        cout << 4 << endl;
        return (0);
    }
        
    for (int i = 1; i <= 3; i ++) {
        rotate();
            
        if (eq()) {
            cout << 5 << endl;
            return (0);
        }
    }
    
    rotate();
    reflect();
        
    if (eq()) {
        cout << 6 << endl;
        return (0);
    }
    
    cout << 7 << endl;
    return (0); 
}