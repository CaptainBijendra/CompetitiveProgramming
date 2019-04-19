#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int col[MAX_N];
int N, M, K, Q;

int main() {
    cin >> N >> M >> K >> Q;
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    for (int i = 0; i < N; i ++)
        cin >> col[i];
    
    for (int i = 0; i < Q; i ++) {
        
    }
    
    
    return (0);
}