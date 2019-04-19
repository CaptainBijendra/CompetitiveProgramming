#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int ar[MAX_N], lft[MAX_N], rght[MAX_N];
int N, Q;

class BIT {
    public:
        long long tree[MAX_N];

        BIT(int sz) {
            for (int i = 0; i < sz; i ++) 
            { tree[i] = 0ll; }
        }
    
        long long query(int index) {
            long long sum = 0;
            
            index ++;
            
            while (index > 0) {
                sum += tree[index];
                index -= (index & (-index));
            }
        
            return (sum);
        }
        
        void update(int index, long long val) {
            index ++;
            
            while (index < MAX_N) {
                tree[index] += val;
                index += (index & (-index));
            }
        }
};

int main() {
    cin >> N >> Q;
    
    BIT inv(MAX_N);

    for (int i = 1; i <= Q; i ++)
        lft[i] = MAX_N;
    
    bool pos = false;
    bool pos2 = false;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        lft[ar[i]] = min(lft[ar[i]], i);
        rght[ar[i]] = max(rght[ar[i]], i);
        
        con[ar[i]].push_back(i);
        
        if (ar[i] == Q)
            pos = true;
        if (ar[i] == 0)
            pos2 = true;
    }

    bool flag = false;

    for (int i = 1; i <= Q; i ++) {
        if (lft[i] >= N)
            continue;
        
        int sum = inv.query(rght[i]) - (lft[i] == 0 ? 0 : inv.query(lft[i] - 1));
        
        if (sum > 0) {
            flag = true;
            break;
        }
        
        for (int j = 0; j < con[i].size(); j ++)
            inv.update(con[i][j], 1);
    }
    
    if (flag || (!pos && !pos2)) {
        cout << "NO" << endl;
        return (0);
    }
    
    cout << "YES" << endl;
    
    if (ar[0] == 0 && !pos) {
        ar[0] = Q;
        pos = true;
    }
    
    else if (ar[0] == 0 && pos)
        ar[0] = 1;
    
    cout << ar[0];
    for (int i = 1; i < N; i ++) {
        if (ar[i] == 0 && !pos) {
            ar[i] = Q;
            pos = true;
        }
        
        else if (ar[i] == 0 && pos)
            ar[i] = ar[i - 1];
        
        cout << " " << ar[i];
    }
    
    cout << endl;
    return (0);
}