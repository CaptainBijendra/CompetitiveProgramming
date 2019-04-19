#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_N 400005
#define f first
#define s second

using namespace std;

vector<long long> ansA, ansB;

long long A[MAX_N], B[MAX_N];
long long N, M;

int main() {
    cin >> N;
    
    for (long long i = 0; i < N; i ++)
        cin >> A[i];
        
    cin >> M;
    
    for (long long i = 0; i < M; i ++)
        cin >> B[i];
        
    long long a = 0;
    long long b = 0;
    
    long long sumA = 0;
    long long sumB = 0;
        
    while (true) { 
        if (A[a] == B[b] && sumA == 0 && sumB == 0) {
            ansA.push_back(A[a]);
            ansB.push_back(B[b]);
            
            a ++;
            b ++;
        }
        
        else {
            if (sumA == 0 && sumB == 0 && A[a] != B[b]) {
                sumA += A[a];
                sumB += B[b];
                
                a ++;
                b ++;
                
                continue;
            }
            
            if (sumA < sumB) {
                sumA += A[a];
                a ++;
            }
            
            else if (sumB < sumA) {
                sumB += B[b];
                b ++;
            }
            
            if (sumA == sumB) {
                sumA = 0;
                sumB = 0;
                    
                ansA.push_back(A[a]);
                ansB.push_back(B[b]);
            }
        }
        
        if (a >= N && b >= M)
            break;
    }
    
    long long ans = min(ansA.size(), ansB.size());
    
    if (ans <= 0) {
        cout << -1 << endl;
        return (0);
    }
    
    cout << ans << endl;
    return (0);
}