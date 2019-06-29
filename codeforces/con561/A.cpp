#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <stack>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N], cnt[255];
int N;

int main() {
    cin >> N;
    
    string str;
    for (int i = 0; i < N; i ++) {
        cin >> str;
        cnt[str[0]] ++;
    }
    
    int ans = 0;
    for (int i = 0; i < 255; i ++) {
        if (cnt[i] % 2 == 0) {
            ans += max(0, (cnt[i] / 2) * (cnt[i] / 2 - 1));
        } else {
            ans += max(0, (cnt[i] / 2) * (cnt[i] / 2 - 1) / 2 + (cnt[i] / 2 + 1) * (cnt[i] / 2) / 2);
        }
    }

    cout << ans << endl;
    return (0);
}