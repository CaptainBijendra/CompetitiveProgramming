#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <set>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int ar[MAX_N][MAX_N];
ii ord[MAX_N][MAX_N];

int N;

bool cmp(ii a, ii b) {
    return (ar[a.f][a.s] < ar[b.f][b.s]);
}


int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> ar[i][j];
            ord[i][j] = ii(i, j);
        }
        
        sort(ord[i], ord[i] + N, cmp);
    }
    
    for (int i = 0; i < N; i ++) {
        bool flag = false;
        int x = ord[i][0].f;
        
        for (int j = 1; j < N; j ++) {
            if (ord[i][j].f != x) {
                flag = true;
                break;
            }
        }
        
        if (flag) {
            cout << "N" << endl;
            return (0);
        }
    }
    
    int cx = 0;
    int cy = 0;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            ord[i][j] = ii(cy, cx);
            cy ++;
        }
        
        cy = 0;
        cx ++;
    }
    
    for (int i = 0; i < N; i ++) {
        sort(ord[i], ord[i] + N, cmp);
    }
    
    for (int i = 0; i < N; i ++) {
        bool flag = false;
        int x = ord[0][i].f;
        
        for (int j = 1; j < N; j ++) {
            if (ord[j][i].f != x) {
                flag = true;
                break;
            }
        }
        
        if (flag) {
            cout << "N" << endl;
            return (0);
        }
    }
    
    cout << "Y" << endl;
    return (0);
}