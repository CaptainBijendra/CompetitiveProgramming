#include <iostream>
#include <algorithm>

#define MAX_N 25005
#define f first
#define s second

using namespace std;

bool used[MAX_N];

int A[MAX_N], B[MAX_N], ans[MAX_N];
int N;

int main() {
    cin >> N;
    
    int mx = -1;
    int ind = -1;
    
    for (int i = 0; i < N; i ++) { 
        cin >> A[i] >> B[i];
        
        if (B[i] > mx) {
            ind = i;
            mx = B[i];
        }
    }

    ans[0] = ind;
    used[ind] = true;

    for (int i = 1; i < N; i ++) {
        ind = -1;
        mx = -1;
        
        for (int j = 0; j < N; j ++) {
            if (used[j]) { continue; }
            
            if (mx < min(B[ans[i - 1]], A[j])) {
                mx = min(B[ans[i - 1]], A[j]);
                ind = j;
            }
        }
        
        ans[i] = j;
    }
    
    for (int i = 0; i < N)
    
    return (0);
}