#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

bool flag = false;

string query(string x) {
    cout << x << endl;
    cout.flush();
    
    string y1, y2;
    cin >> y1 >> y2;
    
    if (!y2.compare("0")) {
        flag = true;
    }
    
    return (y1);
}

int main() {
    string cur = "1";
    int depth = 1;
    
    bool flag2 = false;
    
    while (true) {
        cur = query(cur);
        depth ++;
        
        if (flag) {
            if (cur.compare("0"))
                flag2 = true;
            
            depth --;
            break;
        }
    }

    long long ans = 1ll;
    
    for (int i = 0; i < depth; i ++)
        ans *= 2ll;    
    
    if (!flag2)
        ans --;
        
    cout << "Answer " << ans << endl;
    return (0);
}