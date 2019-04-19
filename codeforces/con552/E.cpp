#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <string.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int ar[MAX_N], ans[MAX_N];
int N, K;

int main() {
    cin >> N >> K;
    
    vector<ii> v;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        v.push_back(ii(ar[i], i));
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    set<int> vals;
    
    for (int i = 0; i < N; i ++)
        vals.insert(i);
    
    int turns = 0;
    
    for (int i = 0; i < N; i ++) {
        if (ans[v[i].s] != 0)
            continue;
        
        auto it = vals.find(v[i].s);

        vector<int> rem;
        for (int j = 0; j <= K; j ++) {
            rem.push_back(*it);
            
            if (it == vals.begin())
                break;
                
            it --;
        }
        
        it = vals.find(v[i].s);
        it ++;
        
        for (int j = 0; j < K; j ++) {
            if (it == vals.end())
                break;
                
            rem.push_back(*it);
            it ++;
        }
        
        for (int j = 0; j < rem.size(); j ++) {
            ans[rem[j]] = (turns % 2) + 1;
            vals.erase(rem[j]);
        }
        
        turns ++;
    }
    
    for (int i = 0; i < N; i ++)
        cout << ans[i];
    
    cout << endl;
    return (0);
}