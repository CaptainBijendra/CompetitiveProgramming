#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define MOD 1000000009
#define f first
#define s second

using namespace std;

string str;

int ar[MAX_N];
int N, K;

int main() {
    cin >> N >> K;
    cin >> str;

    for (int i = 0; i < N; i ++) 
        ar[i] = (int)(str[i] - 'a') + 1;
        
    sort(ar, ar + N);
    
    int prev = 0;
    int ans = ar[prev];
    int len = 1;
    
    for (int i = 1; i < N; i ++) {
        if (ar[i] - ar[prev] >= 2) {
            len ++;
            ans += ar[i];
            prev = i;
        }
        
        if (len == K)
            break;
    }
    
    cout << (len < K ? -1 : ans) << endl;
    return (0);
}