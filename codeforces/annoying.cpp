#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

long long N, M;

int main() {
    cin >> N >> M;
    
    long long x, d;
    long long total = 0;
    
    for (int i = 0; i < M; i ++) {
        cin >> x >> d;
        
        if (d >= 0)
            total += (N * x + ((N * (N - 1ll) / 2ll) * d));
        else {
            if (N % 2 == 0)
                total += (N * x + ((N / 2ll - 1ll) * (N / 2ll)) * d + (N / 2ll) * d);
            else
                total += (N * x + ((N / 2ll) * (N / 2ll + 1ll)) * d);
        }
    }
    
    cout << setprecision(20) << ((long double)(total) / (N * 1.0)) << endl;
    return (0);
}