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

int ar[MAX_N], val[MAX_N];
int N, M;

int main() {
    cin >> N;
    
    int cnt = 1;
    for (int i = 2; i <= N; i ++) {
        if (val[i]) { continue; }
        for (int j = i; j <= N; j += i)
            if (!val[j])
                val[j] = cnt;
        
        cnt ++;
    }
    
    for (int i = 2; i <= N; i ++)
        cout << val[i] << " ";
    
    cout << endl;
    return (0);
}