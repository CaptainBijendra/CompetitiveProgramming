#include <iostream>

#define MAX_N 5005
#define f first
#define s second

using namespace std;

int ar[MAX_N], pre[MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
    
        if (i == 0)
            pre[i] = 0;
        else
            pre[i] = pre[i - 1] + ar[i];
    }
    
    int ans = 0;
        
    for (int i = 0; i < N; i ++) {
        for (int j = i; j < N; j ++) {
            if (pre[j] - pre[i] + ar[i] > (j - i + 1) * 100)
                ans = max(ans, (j - i + 1));
        }
    }
    
    cout << ans << endl;
    return (0);
}