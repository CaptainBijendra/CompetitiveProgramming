#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

bool same[MAX_N];

int ar[MAX_N], ar2[MAX_N], diff[MAX_N], diff2[MAX_N];
int N;

int main() {
    cin >> N;    

    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
    
        if (i > 0)
            diff[i - 1] = ar[i] - ar[i - 1];
    }
    
    for (int i = 0; i < N; i ++) {
        cin >> ar2[i];
        
        if (i > 0)
            diff2[i - 1] = ar2[i] - ar2[i - 1];
    }
        
    if (ar[0] != ar2[0]) {
        cout << "No" << endl;
        return (0);
    }
    
    sort(diff, diff + N - 1);
    sort(diff2, diff2 + N - 1);
    
    for (int i = 0; i < N - 1; i ++) {
        if (diff[i] != diff2[i]) {
            cout << "No" << endl;
            return (0);
        }
    }

    cout << "Yes" << endl;
    return (0);
}