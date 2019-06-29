#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <iomanip>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

bool con[MAX_N];

int ar[MAX_N];
int N;

int main() {
    cin >> N;

    int ans = 1;
    
    cout << ans << " ";
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        ans ++;
        
        if (ar[i] == N) {
            con[ar[i]] = true;
            ans --;

            int it = ar[i] - 1;
            
            while (!con[it] && it > 0) {
                con[it] = true;
                ans --;
                
                it --;
            }
        }
        
        if (con[ar[i] + 1]) {
            int it = ar[i];
            
            while (!con[it] && it > 0) {
                con[it] = true;
                ans --;
                
                it --;
            }
        }
        
        cout << ans << " ";
    }
    
    cout << endl;
    return (0);
}