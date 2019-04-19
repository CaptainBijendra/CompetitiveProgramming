#include <bits/stdc++.h>
using namespace std;

vector<int> fibonacciSum(int N) {
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    
    while (true) {
        fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
        
        if (fib[fib.size() - 1] >= N)
            break;
    }
    
    vector<int> DP[fib[fib.size() - 1] + 5];
    
    for (int i = 0; i <= N; i ++) {
        for (int j = 0; j < fib.size(); j ++) {
            if (i + fib[j] <= N) { 
                if (DP[i + fib[j]].size() > DP[i].size() + 1 || DP[i + fib[j]].size() == 0) {
                    DP[i + fib[j]] = DP[i];
                    DP[i + fib[j]].push_back(fib[j]);
                }
            }    
        }   
    }
    
    return (DP[N]);
}

int main() {
    int n;
    cin >> n;
    vector<int> solution = fibonacciSum(n);
    for (int i = 0; i < (int)solution.size(); ++ i) {
        cout << solution[i];
        cout << (i + 1 == (int)solution.size() ? "\n" : " ");
    }
    return 0;
}
