#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 2000000000009
#define MAX_N 300005
#define f first
#define s second

using namespace std;

long long DP[MAX_N][4], A[MAX_N], B[MAX_N];
long long N, K;

//Start with T, end with T
long long calc_0(long long a, long long b) {
    if (a > b)
        return ((a + b) / (b + 1));
    
    return ((a + b) / (a + 1));
}

//Start with T, end with F
long long calc_1(long long a, long long b) {
    if (a >= b)
        return ((a + b - 1) / b);
    
    return ((a + b - 1) / a);
}

//Start with F, end with T
long long calc_2(long long a, long long b) {
    if (b >= a)
        return ((a + b - 1) / a);
    
    return ((a + b - 1) / b);
}

//Start with F, end with F
long long calc_3(long long a, long long b) {
    if (b > a)
        return ((a + b) / (a + 1));
    
    return (INF);
}

int main() {
    cin >> N >> K;
    
    for (long long i = 0; i < N; i ++)
        cin >> A[i];
        
    for (long long i = 0; i < N; i ++)
        cin >> B[i];

    DP[0][0] = min(calc_0(A[0], B[0]), calc_2(A[0], B[0]));
    DP[0][1] = min(calc_1(A[0], B[0]), calc_3(A[0], B[0]));

    for (long long i = 1; i < N; i ++) {
        int pos1 = calc_0(A[i] + DP[i - 1][0], B[i]);
        int pos2 = calc_2(A[i], DP[i - 1][1] + B[i]));
        int pos3 = calc_1(A[i] + DP[i - 1][0], B[i]);
        int pos4 = calc_3(A[i], DP[i - 1][1] + B[i]));
        
        bool flag = false;
        
        if (pos1 <= K) {
            
            
            flag = true;
        }
        
        if (pos3 <= K)
        
        if (DP[i][0] > K && DP[i][1] > K) {
            cout << "NO" << endl;
            return (0);
        }
    }
    
    cout << "__________________" << endl;
    for (int i = 0; i < N; i ++) {
        cout << DP[i][0] << " " << DP[i][1] << endl;
    }
    
    cout << "YES" << endl;
    return (0);
}