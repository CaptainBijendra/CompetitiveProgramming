#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int N, sum;

void merge(int l, int r) {
    if (l == r)
        return;
    
    if (l + 1 == r)
        sum += (l * r);
        
    merge(l, (l + r) / 2);
    merge((l + r) / 2 + 1, r);
}

int main() {
    cin >> N;
    sum = 0;
    
    merge(1, N);
    
    cout << sum << endl;
}