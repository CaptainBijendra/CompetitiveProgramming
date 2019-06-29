#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

string str;

int use[MAX_N], pre[MAX_N];
int N;

int sum(int l, int r) {
    if (l > r)
        return (0);
        
    return (pre[r] - pre[l] + (str[l] == '(' ? 1 : -1));
}

int main() {
    cin >> N;
    cin >> str;
    
    int big = 0;
    int res = -1, cur = -1;
    for (int i = 0; i < str.size(); i ++) {
        if (str[i] == '(')
            pre[i] = (i == 0 ? 0 : pre[i - 1]) + 1;
        else
            pre[i] = pre[i - 1] - 1;
        
        big = max(big, pre[i]);
    }
    
    res = (big + 1) / 2;
    cur = 0;
    
    int l = 0, r = str.size() - 1;
    while (l + 1 <= r) {
        if (cur == res) {
            break;
        }
        
        if (str[l] == '(' && str[l + 1] == ')' && l + 1 <= r && sum(l + 2, r) == 0) {
            use[l] = 1;
            use[l + 1] = 1;
            
            l += 2;
            
            if (cur + 1 == res) {
                break;
            }
        }
        
        else if (str[r - 1] == '(' && str[r] == ')' && r - 1 >= l && sum(l, r - 2) == 0) {
            use[r - 1] = 1;
            use[r] = 1;
            
            r -= 2;
            
            if (cur + 1 == res) {
                break;
            }
        }        
        
        else if (str[l] == '(' && str[r] == ')' && sum(l + 1, r - 1) == 0) {
            use[l] = 1;
            use[r] = 1;
            
            l ++;
            r --;
            cur ++;
        }
    }
    
    for (int i = 0; i < N; i ++)
        cout << use[i];

    cout << endl;
    return (0);
}