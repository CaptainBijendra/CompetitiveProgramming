#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

int T, N, ans;

int ask(vector<int> s, vector<int> s2) {
    cout << s.size() << " " << s2.size();
    
    for (int i = 0; i < s.size(); i ++)
        cout << " " << s[i];
    for (int i = 0; i < s2.size(); i ++)
        cout << " " << s2[i];
    
    cout << endl;
    cout.flush();

    int x;
    cin >> x;
    
    return (x);
}

void solve(int L, int R) {
    vector<int> s1, s2;
    
    for (int i = 0; i < L; i ++)
        s1.push_back((i + 1));
    for (int i = R + 1; i < N; i ++)
        s1.push_back((i + 1));
    
    for (int i = L; i <= R; i ++)
        s2.push_back((i + 1));
    
    if (s1.size() == 0 || s2.size() == 0) {
        solve(L, (L + R) / 2);
        solve((L + R) / 2 + 1, R);
    
        return;
    }
    
    ans = max(ans, ask(s1, s2));
    
    if (L == R)
        return;
    
    solve(L, (L + R) / 2);
    solve((L + R) / 2 + 1, R);
}

int main() {
    cin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        cin >> N; ans = 0;
        solve(0, N - 1);

        cout << "-1 " << ans << endl;
    }
    
    return (0);
}