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

int ar[MAX_N];
int N, M;

int main() {
    cin >> N;
    
    int pos = 0;
    int neg = 0;
    int target = (N + 1) / 2;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
    
        if (ar[i] > 0)
            pos ++;
        if (ar[i] < 0)
            neg ++;
    }
    
    if (neg >= target) {
        cout << -1 << endl;
        return (0);
    }
    
    if (pos >= target) {
        cout << 1 << endl;
        return (0);
    }
    
    cout << 0 << endl;
    return (0);
}