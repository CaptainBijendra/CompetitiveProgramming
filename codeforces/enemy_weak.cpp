#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

map<int, int> cnv;

int ar[MAX_N];
int N;

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
    cin >> N;
    
    BIT bit1(MAX_N);
    BIT bit2(MAX_N);
    
    vector<int> vec;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        vec.push_back(ar[i]);
    }
    
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    
    for (int i = 0; i < N; i ++)
        cnv[vec[i]] = i;
    
    bit1.update(cnv[ar[0]], 1);
    
    long long ans = 0ll;
    
    for (int i = 1; i < N; i ++) {
        ans += bit2.query(cnv[ar[i]]);
        bit2.update(cnv[ar[i]], bit1.query(cnv[ar[i]]));
        bit1.update(cnv[ar[i]], 1);
    }
    
    cout << ans << endl;
    return (0);
}