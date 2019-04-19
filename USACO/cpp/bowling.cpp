#include <iostream>
#include <algorithm>

#define MAX_N 2005

using namespace std;

int loc1[MAX_N], loc2[MAX_N], ar[MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < 2 * N; i ++)
        cin >> ar[i];
    
    int ans = 0;
    
    for (int i = 0; i < 2 * N; i += 2) {
        for (int j = i + 1; j < 2 * N; j ++) {
            if (ar[j] == ar[i]) {
                for (int k = j; k > i + 1; k --) {
                    int tmp = ar[k];
                    ar[k] = ar[k - 1];
                    ar[k - 1] = tmp;
                
                    ans ++;
                }
                
                break;
            }
        }
    }

    cout << ans << endl;
    return (0);
}