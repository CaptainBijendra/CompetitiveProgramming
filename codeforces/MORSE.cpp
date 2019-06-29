#include <iostream> 
#include <algorithm>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 10005
#define f first
#define s second

using namespace std;

map<int, int> DP[MAX_N];

int trie[MAX_N * 20][27];
int N, D, ind;

void addword(string str, int in, int depth) {
    if (depth == str.size()) {
        if (trie[in][26] == -1)
            trie[in][26] = 1;
        else
            trie[in][26] ++;
             
        return;
    }
    
    if (trie[in][str[depth] - 'A'] != -1)
        addword(str, trie[in][str[depth] - 'A'], depth + 1);
    else {
        ind ++;
        trie[in][str[depth] - 'A'] = ind;
        
        addword(str, ind, depth + 1);
    }
}

void print (int in) {
    for (int i = 0; i < 26; i ++) {
        if (trie[in][i] != -1) {
            cout << (trie[in][i]) << " " << (char)(i + 'A') << endl;
            print (trie[in][i]);
        }
    }
}

int main() {
    cin >> D;
    
    string conv[26] { ".-", "-...", "-.-.", "-..", ".", 
                      "..-.", "--.", "....", "..", ".---", 
                      "-.-", ".-..", "--", "-.", "---", ".--.", 
                      "--.-", ".-.", "...", "-", "..-", "...-", 
                      ".--", "-..-", "-.--", "--.." };

    for (int ii = 0; ii < D; ii ++) {
        for (int i = 0; i < MAX_N * 20; i ++) {
            for (int j = 0; j <= 26; j ++)
                trie[i][j] = -1;
        
            if (i < MAX_N)
                DP[i].clear();
        }
        
        ind = 0;
        
        string str;
        cin >> str;
        cin >> N;
        
        string x;
        for (int i = 0; i < N; i ++) {
            cin >> x;
            addword(x, 0, 0);
        }
        
        DP[0][0] = 1;
        
        for (int i = 0; i < str.size(); i ++) {
            for (map<int, int>::iterator it = DP[i].begin(); it != DP[i].end(); it ++) {
                int tNode = it->first;
                int num = it->second;
                
                for (int j = 0; j < 26; j ++) {
                    if (i + conv[j].size() > str.size()) { continue; }
                    if (trie[tNode][j] != -1 && !str.substr(i, conv[j].size()).compare(conv[j])) {
                        DP[i + conv[j].size()][trie[tNode][j]] += DP[i][tNode];
                    }
                }
                
                if (trie[tNode][26] != -1) {
                    for (int j = 0; j < 26; j ++) {
                        if (i + conv[j].size() > str.size()) { continue; }
                        if (trie[0][j] != -1 && !str.substr(i, conv[j].size()).compare(conv[j])) {
                            DP[i + conv[j].size()][trie[0][j]] += (DP[i][tNode] * trie[tNode][26]);
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        
        for (map<int, int>::iterator it = DP[str.size()].begin(); it != DP[str.size()].end(); it ++) {
            if (trie[it->first][26] != -1)
                ans += (trie[it->first][26] * it->second);
        }
        
        cout << ans << endl;
    }
    
    return (0);
}