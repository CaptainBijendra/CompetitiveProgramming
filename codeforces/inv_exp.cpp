#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 250005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

class BIT {
    public:
        int tree[MAX_N];

        BIT(int sz) {
            for (int i = 0; i < sz; i ++) 
            { tree[i] = 0; }
        }
    
        int query(int index) {
            int sum = 0;
            
            index ++;
            
            while (index > 0) {
                sum += tree[index];
                index -= (index & (-index));
            }
        
            return (sum);
        }
        
        void update(int index, int val) {
            index ++;
            
            while (index < MAX_N) {
                tree[index] += val;
                index += (index & (-index));
            }
        }
};

int main() {
    cin >> N;
    
    BIT ans(MAX_N);
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    for (int i = 0; i < N; i ++)
        if (ar[i] == -1)
            cnt_neg ++;
    
    long long ans = max(0ll, (cnt_neg - 1) * ((cnt_neg) * (cnt_neg - 1)));
    long long pre = 0;
    
    for (int i = 0; i < N; i ++) {
        if (ar[i] != -1) 
            pre += (ar[i] - 1);
    }
    
    return (0);
}