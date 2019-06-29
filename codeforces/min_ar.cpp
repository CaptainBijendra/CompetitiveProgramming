#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string.h>

#define MAX_N 200005
#define f first
#define s seconds

using namespace std;

int ar[MAX_N], ar2[MAX_N], cnt[MAX_N], ans[MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    multiset<int> st;
    
    int x;
    for (int i = 0; i < N; i ++) {
        cin >> x;
        st.insert(x);
    }
    
    for (int i = 0; i < N; i ++) {
        int diff = (N - ar[i]);
        
        multiset<int>::iterator it = st.lower_bound(diff);
        
        if (it == st.end()) {
            ans[i] = ar[i] + *st.begin();
            st.erase(st.begin());
        } else {
            ans[i] = (ar[i] + *it) % N;
            st.erase(it);
        }
    }
    
    for (int i = 0; i < N; i ++)
        cout << ans[i] << " ";
    
    cout << endl;
    return (0);
}