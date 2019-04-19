#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 300005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int N, M;

int main() {
    cin >> N >> M;
    
    int moves = 0;
    
    if (M > (N / 2)) {
        for (int i = M; i <= N; i ++)
            moves += 3;    
    
        moves --;
    
        if (M != 1)
            moves += (N - (M - 1));
    
        if (M != 1) {
            for (int i = M - 1; i >= 1; i --)
                moves += 3;
    
            moves --;
        }

        moves ++;
    }
    
    else {
        for (int i = M; i >= 1; i --)
            moves += 3;
        
        moves --;
        
        if (M != N)
            moves += M;
        
        if (M != N) {
            for (int i = M + 1; i <= N; i ++)
                moves += 3;
            
            moves --;
        }
        
        moves ++;
    }

    cout << moves << endl;
    return (0);
}