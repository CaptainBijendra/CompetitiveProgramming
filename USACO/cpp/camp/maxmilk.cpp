#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 250005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;

vector<int> con[MAX_N * 2];
vector<pii> cows;

int N;

int main() {
    cin >> N;

    int a, b, c;
    for (int i = 0; i < N; i ++) {
        cin >> a >> b >> c;
        con[b].push_back(a);
        con[c].push_back(a);
        
        cows.push_back(pii(a, ii(b, c)));
    }
    
    for (int i = 0; i < 2 * MAX_N; i ++) {
        sort(con[i].begin(), con[i].end());
        reverse(con[i].begin(), con[i].end());
    }

    cout << sum << endl;
    return (0);
}