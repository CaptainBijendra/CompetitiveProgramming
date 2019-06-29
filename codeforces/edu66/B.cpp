#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <iomanip>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

int main() {
    cin >> N;
    
    vector<long long> stack;
    vector<long long> test;
    
    string str;
    
    long long ans = 0ll;
    long long over = (1ll << 32ll) - 1ll;
    
    for (int i = 0; i < N; i ++) {
        cin >> str;
        
        if (str[0] == 'a') {
            if (stack.size() >= 32) {
                cout << "OVERFLOW!!!" << endl;
                return (0);
            }
            
            long long cur_mult = 1ll;
            for (int j = 0; j < stack.size(); j ++) {
                cur_mult *= stack[j];
            
                if (cur_mult > over - ans) {
                    cout << "OVERFLOW!!!" << endl;
                    return (0);
                }
            }
            
            if (ans > over - cur_mult) {
                cout << "OVERFLOW!!!" << endl;
                return (0);
            }

            ans += (cur_mult);
        }
        
        else if (str[0] == 'f') {
            long long x;
            cin >> x;
            
            test.push_back(x);
            
            if (x != 1)
                stack.push_back(x);
        } else {
            if (test[test.size() - 1] != 1)
                stack.pop_back();
            
            test.pop_back();
        }
    }
    
    cout << ans << endl;
    return (0);
}