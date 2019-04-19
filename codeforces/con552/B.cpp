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
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    sort(ar, ar + N);
    
    int diff = 0;
    int cnt = 0;
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        if (ar[i + 1] > ar[i]) {
            if (cnt == 0) {
                diff = ar[i + 1] - ar[i];
                cnt ++;
            }
            
            else if (cnt == 1) {
                if (ar[i + 1] - ar[i] == diff) {
                    ans = diff;
                    cnt ++;
                }
                
                else {
                    cout << "-1" << endl;
                    return (0);
                }
            }
            
            else {
                cout << "-1" << endl;
                return (0);
            }
        }
    }
    
    if (cnt == 1) {
        if (diff % 2 == 0)
            ans = diff / 2;
        else    
            ans = diff;
    }
    
    if (cnt == 0)
        ans = 0;
    
    cout << ans << endl;
    return (0);
}