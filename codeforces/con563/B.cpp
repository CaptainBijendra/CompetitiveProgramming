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

typedef pair<int, int> ii;

ii ar[MAX_N];
int N, K, M;

bool cmp(ii a, ii b) {
    return (a.s < b.s);
}

int main() {
    cin >> N >> K >> M;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i].f;
        ar[i].s = (ar[i].f % M);
    }
    
    sort(ar, ar + N, cmp);
    
    int cur = ar[0].s;
    int streak = 1, end = -1;
    
    for (int i = 1; i < N; i ++) {
        if (ar[i].s == cur)
            streak ++;
        else {
            cur = ar[i].s;
            streak = 1;
        }
        
        if (streak == K)
            end = i;
    }
    
    if (end == -1) {
        cout << "No" << endl;
        return (0);
    }
    
    cout << "Yes" << endl;
    for (int i = end; i > end - K; i --)
        cout << ar[i].f << " ";
    
    cout << endl;
    return (0);
}