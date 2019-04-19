#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int trie[1000*27][27];
int N, ind, ans;

string str;

void add_word(string str, int depth, int indx) {
    if (depth == str.size()) {
        ind ++;
        trie[indx][26] = ind;
        
        return;
    }
    
    if (trie[indx][str[depth] - 'A'] == -1) {
        ind ++;
        trie[indx][str[depth] - 'A'] = ind;
        
        add_word(str, depth + 1, ind);
    }
    
    else {
        add_word(str, depth + 1, trie[indx][str[depth] - 'A']);
    }
}

int DFS (int indx, int ch) {
    if (ch == 26)
        return (1);
    
    long long depth = 0ll;

    for (int i = 0; i < 27; i ++) {
        if (trie[indx][i] != -1) {
            depth += DFS (trie[indx][i], i);
        }
    }
    
    if (depth == 2) {
        ans += 2;
        return (0);
    }
    
    if (depth == 1)
        return (1);
    
    if (depth > 2) {
        ans += 2;
        return (1);
    }
    
    return (0);
}

int main() {
    int T;
    cin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        cin >> N;
        ind = 0;
        
        for (int i = 0; i < 1000 * 27; i ++) {
            for (int j = 0; j < 27; j ++) {
                trie[i][j] = -1;
            }
        }
    
        for (int i = 0; i < N; i ++) {
            cin >> str;
            reverse(str.begin(), str.end());
            
            add_word(str, 0, 0);
        }
        
        ans = 0;

        for (int i = 0; i < 26; i ++)
            if (trie[0][i] != -1) {
                DFS (trie[0][i], i);
            }
        
        cout << "Case #" << (ii + 1) << ": " << ans << endl;
    }
    
    return (0);
}