#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <vector>

#define MAX_N 300005
#define f first
#define s second

using namespace std;

int ar[MAX_N], tmp[MAX_N];
int N, M;

bool pos(int num) {
    for (int i = 0; i < N; i ++)
        ar[i] = tmp[i];
    
    if ((M - ar[0]) <= num)
        ar[0] = 0;
    
    for (int i = 1; i < N; i ++) {
        if (ar[i] < ar[i - 1]) {
            if (ar[i - 1] - ar[i] <= num)
                ar[i] = ar[i - 1];
            else
                return (false);
        } else {
            if (((M - ar[i]) + ar[i - 1]) <= num)  
                ar[i] = ar[i - 1];
        }
    }
    
    return (true);
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        tmp[i] = ar[i];
    }
        
    int low = 0;
    int hi = 2 * M;
    
    while (low < hi) {
        int mid = (low + hi) / 2;
        
        if (pos(mid))
            hi = mid;
        else    
            low = mid + 1;
    }
    
    cout << low << endl;
    return (0);
}