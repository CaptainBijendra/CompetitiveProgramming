#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int ar[MAX_N], cnt[MAX_N];
int N, K;

int main() {
    cin >> N >> K;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        cnt[ar[i]] ++;
    }
    
    vector<ii> sol;
    
    for (int i = 0; i < MAX_N; i ++)
        sol.push_back(ii(cnt[i], i));
    
    sort(sol.begin(), sol.end());    
    reverse(sol.begin(), sol.end());
    
    for (int i = 0; i < K; i ++)
        cout << sol[i].s << " ";
        
    cout << endl;
    return (0);
}