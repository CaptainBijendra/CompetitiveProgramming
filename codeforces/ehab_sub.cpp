#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <map>
#include <vector>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N, K;

int main() {
    cin >> N >> K;
    
    int sum = 0;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    sort(ar, ar + N);
    
    int cnt = 0;
    
    for (int i = 0; (i < N && cnt < K); i ++) {
        if (ar[i] - sum != 0) {
            cout << ar[i] - sum << endl;
            sum += (ar[i] - sum);
            
            cnt ++;
        }
    }
    
    while (cnt < K) {
        cout << 0 << endl;
        cnt ++;
    }
    
    return (0);
}