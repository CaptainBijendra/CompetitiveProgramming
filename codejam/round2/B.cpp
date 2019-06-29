#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int ar[MAX_N];
int N;

int main() {
    int T, W;
    cin >> T;
        
    int x1, x2, x3, x4, x5, x6, ans1, ans2, ans3, ans4, ans5, ans6;
    for (int ii = 0; ii < T; ii ++) {
        cin >> W;
        
        cout << 1 << endl;
        cout.flush();
        cin >> x1;
        
        cout << 2 << endl;
        cout.flush();
        cin >> x2;
        
        int val = x2 - x1;

        cout << 7 << endl;
        cout.flush();
        cin >> x3;
        
        cout << 6 << endl;
        cout.flush();
        cin >> x4;

        ans1 = (x3 - x4) / 64;
        ans2 = val - 2 * ans1;

        cout << 5 << endl;
        cout.flush();
        cin >> x5;
        
        cout << 4 << endl;
        cout.flush();
        cin >> x6;
        
        
        
        ans5 = (x6 - x5 - 1024 * ans1) / 2;
        ans6 = (x1 - 128 * ans1 - 8 * ans2 - 4 * ans3 - 2 * ans4 - 2 * ans5) / 2;

        cout << "Case #" << (ii + 1) << ": " << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << " " << ans5 << " " << ans6 << endl;
    }

    return (0);
}