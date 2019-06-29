#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 55
#define f first
#define s second

using namespace std;

vector<long long> sol;

long long Q, M;

bool pos(int len, long long num, long long st) {
    vector<long long> so;
    
    long long mult = (long long)(1ll << (len - 1));    
    
    if ((num / st) >= mult) {
        num -= (mult * st);
        
        if (((num + (1ll << (len - 1)) - 1) / (1ll << (len - 1))) > M)
            return (false);
        else if (num >= (1ll << (len - 1))) {
            num -= (1ll << (len - 1));
            
            for (int i = 0; i < len; i ++)
                so.push_back(1ll);
            
            for (int i = 0; i < len - 1; i ++) {
                so[i] += min(M - 1, (num / (1ll << (len - 2 - i))));
                num -= ((1ll << (len - 2 - i)) * min(M - 1, (num / (1ll << (len - 2 - i)))));
            }
            
            if (so[len - 2] > M) {
                so[len - 1] += (so[len - 2] - M);
                so[len - 2] = M;
            }
            
            if (so[len - 1] + num > M)
                return (false);
            
            so[len - 1] += num;
        } else
            return (false);
    } else
        return (false);
    
    sol.clear();
    for (int i = 0; i < so.size(); i ++)
        sol.push_back(so[i]);
}

int main() {
    cin >> Q;
    
    long long a, b;
    for (int ii = 0; ii < Q; ii ++) {
        cin >> a >> b >> M;

        if (a == b) {
            cout << 1 << " " << a << endl;
            continue;
        }
        
        if (b - a <= M) {
            cout << 2 << " " << a << " " << b << endl;
            continue;
        }
        
        if (b - 2 * a >= 0 && b - 2 * a <= 2 * M) {
            cout << 3 << " " << a << " " << (a + ((b - 2 * a) / 2)) << " " << b << endl;
            continue;
        }
        
        bool flag = false;
        for (int i = 3; i <= 50; i ++) { //Number of terms
            if (pos(i, b, a)) {
                flag = true;
                break;
            }
        }
        
        if (!flag) {
            cout << "-1" << endl;
            continue;
        }
        
        long long sum = a;
        
        cout << sol.size() + 1 << " " << a;
        for (int i = 0; i < sol.size(); i ++) {
            cout << " " << (sum + sol[i]);
            sum += (sum + sol[i]);
        }
        
        cout << endl;
    }
    
    return (0);
}