#include <iostream>

#define MAX_N 5005
#define f first
#define s second

using namespace std;

int cnt[MAX_N], col[MAX_N], ar[MAX_N];
int N, K;

int main() {
    cin >> N >> K;
    
    int a;
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        
        if (cnt[ar[i]] + 1 > K) {
            cout << "NO" << endl;
            return (0);
        }
        
        cnt[ar[i]] ++;
    }
    
    cout << "YES" << endl;
    for (int i = 0; i < N; i ++) {
        cout << (col[ar[i]] + 1) << " ";
        col[ar[i]] ++;
    }
    
    cout << endl;
    return (0);    
}   