#include <iostream>

#define MAX_N 100005

using namespace std;

int N, ar[MAX_N];

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    for (int i = 0; i < (1 << 15); i ++) {
        int sum = 0;
        
        for (int j = 0; j < N; j ++) {
            if (i & (1 << j))
                sum += ar[j];
            else
                sum -= ar[j];
        }
        
        if (sum % 360 == 0) {
            cout << "YES" << endl;
            return (0);
        }
    }
    
    cout << "NO" << endl;
    return (0);
}