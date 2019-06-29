#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N, ans;

void recurse(int l, int r) {
    if (l == r)
        return;
    if (r - l + 1 == 2) {
        ans += 2;
        return;
    }
    
    ans += (r - l + 1);
    
    for (int i = l; i <= r - 1; i ++)
        if (ar[i] > ar[i + 1])
            swp(ar[i], ar[i + 1]);
    
    int prev = l;
    for (int i = l; i <= r; i ++)
        if ()   
    
    return;
}

int main() {
    ifstream fin ("sort.in");
    ofstream fout ("sort.out");
    
    fin >> N;
    
    for (int i = 0; i < N; i ++)
        fin >> ar[i];
    
    ans = 0;
    recurse(0, N - 1);
    
    cout << ans << endl;
    return (0);
}