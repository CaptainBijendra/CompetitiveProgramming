#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N], use[MAX_N];
int N, Z;

int main() {
    cin >> N >> Z;

    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    sort(ar, ar + N);
    
    int lft = 0;
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        while (use[lft])
            lft ++;
        
        if (lft < i && ar[i] - ar[lft] >= Z) {
            use[i] = true;
            use[lft] = true;
            
            ans ++;
            lft ++;
        }
    }
    
    cout << ans << endl;
    return (0);
}