#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

string str;

int ar[MAX_N];
int N, M;

int diff(int ind, char let) {
    return (min(abs((int)str[ind] - (int)let), (int)('Z' - max(let, str[ind]) + min(let, str[ind]) - 'A') + 1));
}

int main() {
    cin >> N;
    cin >> str;
    
    int ans = MAX_N;
    
    for (int i = 0; i < N - 3; i ++) {
        ans = min(ans, diff(i, 'A') + diff(i + 1, 'C') + diff(i + 2, 'T') + diff(i + 3, 'G'));
    }
    
    cout << ans << endl;
    return (0);
}

