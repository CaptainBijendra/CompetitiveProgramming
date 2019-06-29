#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

int ar[MAX_N], l[MAX_N], r[MAX_N];
int N, X;

int main() {
    cin >> N >> X;
    
    for (int i = 0; i < MAX_N; i ++) { l[i] = MAX_N; }
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        l[ar[i]] = min(l[ar[i]], i);
        r[ar[i]] = max(r[ar[i]], i);
    }
    
    int prev = -1;
    int pre = 0;
    int suf = X;
    
    for (int i = 1; i <= X; i ++) {
        if (l[i] == MAX_N) { continue; }
        if (prev == -1 || l[i] > r[prev]) {
            prev = i;
            continue;
        }
        
        pre = i - 1;
        break;
    }
    
    prev = -1;
    
    for (int i = X; i >= 1; i --) {
        if (l[i] == MAX_N) { continue; }
        if (pre == -1 || r[i] < l[prev]) {
            prev = i;
            continue;
        }
        
        suf = i + 1;
        break;
    }
    
    cout << pre << " " << suf << endl;
    
    return (0);
}