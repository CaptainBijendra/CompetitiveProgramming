#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int ar[MAX_N];
int N, M;

int main() {
    N = 4;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
        
    sort(ar, ar + N);
    
    int x = ar[0] + ar[1] - ar[3];
    int y = ar[0] + ar[2] - ar[3];
    int z = ar[1] + ar[2] - ar[3];
    
    cout << x << " " << y << " " << z << endl;
    return (0);
}