#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 205
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<int> con[MAX_N];

int sz[MAX_N];
int N, M;

int main() {
    cin >> N >> M;
        
    int a, b;
    
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        a --; b --;
        
        con[a].push_back(b);
    }
    
    for (int i = 0; i < N; i ++) {
        sort(con[i].begin(), con[i].end());
        reverse(con[i].begin(), con[i].end());
    }
    
    for (int i = 0; i < N; i ++) {
        int cost = 0;
        int candy = 0;
        
        for (int j = 0; j < N; j ++)
            sz[j] = 0;
            
        for (int j = 1; candy != M ; j ++) {
            
        }
        
        cout << cost << " ";
    }
    
    cout << endl;
    return (0);
}