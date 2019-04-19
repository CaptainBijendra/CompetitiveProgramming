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

ii ar[MAX_N];
int N, M;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) 
        cin >> ar[i].f >> ar[i].s;
    
    cin >> M;
    
    for (int i = 0; i < N; i ++) {
        if (ar[i].f <= M && M < ar[i].s) {
            cout << (N - i) << endl;
            return (0);
        }
        
        if (ar[i].f <= M && M == ar[i].s) {
            if (i == N - 1)
                break;
            else {
                cout << (N - 1) << endl;
                return (0);
            }        
        }
    }
    
    cout << 0 << endl;
    return (0);
}