#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 25
#define f first
#define s second

using namespace std;

string pos[MAX_N];
string str, sol;

int L, N;

bool DFS (int cur_ind) {
    if (cur_ind == L)
        return (true);
    
    for (int i = 0; i < N; i ++) {
        bool flag = true;
        
        if (cur_ind + pos[i].size() > L)
            flag = false;
        
        for (int j = 0; j < pos[i].size(); j ++) {
            if (str[cur_ind + j] == '?' || str[cur_ind + j] == pos[i][j])
                continue;
                
            flag = false;
            break;
        }
        
        if (flag) {
            string tmp = sol;
            sol += pos[i];
            
            if (DFS(cur_ind + pos[i].size()))
                return (true);
            
            sol = tmp;
        }
    }
    
    return (false);
}

int main() {
    cin >> L >> N;
    cin >> str;
    
    for (int i = 0; i < N; i ++)
        cin >> pos[i];

    sort(pos, pos + N);

    sol = "";
    DFS (0);

    cout << sol << endl;
    return (0);
}