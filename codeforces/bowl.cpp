#include <iostream>

using namespace std;

int ar[100005];
int N;

int main() {
    cin.precision(20);
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
        
    long double ans = 100000000.0;
    int a;
    for (int j = 0; j < N; j ++) {
        cin >> a;
        ans = min(ans, (long double)(ar[j] * 1.0 / a * 1.0));
    }    
    
    cout << ans << endl;
    return (0);
}