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
    N *= 2;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
        
    sort(ar, ar + N);

    long long sum1 = 0ll;
    long long sum2 = 0ll;
    
    for (int i = 0; i < N; i ++) {
        if (i < N / 2)
            sum1 += ar[i];
        else
            sum2 += ar[i];
    }

    if (sum1 == sum2) {
        cout << "-1" << endl;
        return (0);
    }
    
    for (int i = 0; i < N; i ++)
        cout << ar[i] << " ";
    
    cout << endl;
    return (0);
}