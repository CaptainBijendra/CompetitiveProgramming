#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>   
#include <vector>
#include <map>
#include <set>
#include <iomanip>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N, M;

int main() {
    cin >> N;
    
    bool flag = false;
    bool flag2 = false;
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        
        if (ar[i] % 2 == 1)
            flag = true;
        if (ar[i] % 2 == 0)
            flag2 = true;
    }

    if (flag && flag2) {
        sort(ar, ar + N);
    }
    
    for (int i = 0; i < N; i ++)
        cout << ar[i] << " ";
    
    cout << endl;
    return (0);
}