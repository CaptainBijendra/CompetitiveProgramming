#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

long long ar[100005], pre[100005];
long long N, M, K;

long double max(long double a, long double b) {
    return (a < b ? b : a);
}

int main() {
    cin >> N >> K >> M;

    for (int i = 0; i < N; i ++)
        cin >> ar[i];

    sort(ar, ar + N);
    
    pre[N - 1] = ar[N - 1];
    for (int i = N - 2; i >= 0; i --)
        pre[i] = (pre[i + 1] + ar[i]);
        
    long double answer = 0.0;
    
    //Iterate through how many we're removing
    for (int i = 0; i < N; i ++) {
        answer = max(answer, (long double)(pre[i] + 1.0 * min((N - i) * K, M - i)) / ((N - i) * 1.0));
    }
    
    cout << setprecision(20) << answer << endl;
    return (0);
}