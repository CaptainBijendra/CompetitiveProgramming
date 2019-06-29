#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <iomanip>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

int main() {
    int A, B, C;
    
    cin >> N;
    cin >> A >> B >> C;
    
    if (N == 1) {
        cout << 0 << endl;
        return (0); 
    }
    
    if (min(A, min(B, C)) == A || min(A, min(B, C)) == B)
        cout << (N - 1) * min(A, B) << endl;
    else
        cout << (N - 2) * min(A, min(B, C)) + min(A, B) << endl;
    
    return (0);
}