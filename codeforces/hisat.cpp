#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

map<string, int> cnv;

int event[MAX_N], cnt[41];
int N, M;

int main() {
    cin >> N >> M;
    
    int a, ind = 1;
    string str;
    
    for (int i = 0; i < N; i ++) {
        cin >> a;
    
        if (a == 1)
            event[i] = -1;
        else {
            cin >> str;
            
            if (cnv[str] == 0) {
                cnv[str] = ind;
                ind ++;
            }
            
            event[i] = cnv[str];
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        if (event[i] == -1) {
            int big = 0;
            
            for (int i = 0; i < 41; i ++) {
                big = max(big, cnt[i]);
                cnt[i] = 0;
            }
            
            ans += big;
            continue;
        }
        
        else {
            cnt[event[i]] ++;
        }
    }
    
    int big = 0;
    
    for (int i = 0; i < 41; i ++)
        big = max(big, cnt[i]);
    
    cout << (ans + big) << endl;
    return (0);
}