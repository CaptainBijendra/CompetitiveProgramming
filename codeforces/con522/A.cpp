#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>   
#include <vector>
#include <map>
#include <set>
#include <iomanip>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int ar[MAX_N], cnt[MAX_N];
int N, M;

int main() {
    cin >> N >> M;
    
    int big = 0;
    int diff = 0;
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
    
        if (cnt[ar[i]] == 0)
            diff ++;
    
        cnt[ar[i]] ++;
        big = max(big, cnt[ar[i]]);
    }
    
    while (big % M != 0)
        big ++;
    
    cout << max(0, (diff * big - N)) << endl;
    return (0);
}