#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 10005
#define f first
#define s second

using namespace std;

string str;

int pos[MAX_N][3], ans[MAX_N][3], perm[MAX_N];
int N;

int main() {
    cin >> str;
    N = str.size();
    
    int cnt = 0;
    
    for (int i = 0; i < 26; i ++) {
        for (int j = 0; j < 26; j ++) {
            for (int k = 0; k < 26; k ++) {
                pos[cnt][0] = i;
                pos[cnt][1] = j;
                pos[cnt][2] = k;
                
                cnt ++;
                
                if (cnt >= N)
                    break;
            }
            
            if (cnt >= N)
                break;
        }
        
        if (cnt >= N)
            break;
    }
    
    for (int i = 0; i < 3; i ++) {
        string c = "";
    
        for (int j = 0; j < N; j ++) {
            c += (pos[j][i] + 'a');
        }
            
        cout << "? " << c << endl;
        cout.flush();
        
        cin >> c;
        
        for (int j = 0; j < N; j ++)
            ans[j][i] = (c[j] - 'a');
    }
    
    for (int i = 0; i < N; i ++)
        perm[i] = -1;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (pos[i][0] == ans[j][0] && pos[i][1] == ans[j][1] && pos[i][2] == ans[j][2]) {
                perm[i] = j;
                break;
            }
        }
    }
    
    string ans = "";
    
    for (int i = 0; i < N; i ++)
        ans += str[perm[i]];
    
    cout << "! " << ans << endl;
    cout.flush();
    
    return (0);    
}