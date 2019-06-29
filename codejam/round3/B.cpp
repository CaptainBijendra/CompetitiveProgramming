#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <math.h>
#include <string.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

map<string, bool> vis;

int ar[MAX_N];
int N;

int main() {
    int T, F;
    cin >> T >> F;

    for (int ii = 0; ii < T; ii ++) {
        bool A = false, B = false, C = false, D = false, E = false;
        char c;
        
        string s = "";
        vis.clear();
        
        for (int i = 1; i <= 590; i ++) {
            if (i % 5 == 0) {
                if (!A)
                    s += '0';
                if (!B)
                    s += '1';
                if (!C)
                    s += '2';
                if (!D)
                    s += '3';
                if (!E)
                    s += '4';
                
                vis[s] = true;
                
                s.clear();
                A = B = C = D = E = false;
                continue;
            }
            
            cout << i << endl;
            cout.flush();
            
            cin >> c;
        
            if (c == 'A') {
                s += '0';
                A = true;
            }
            
            if (c == 'B') {
                B = true;
                s += '1';
            }
            
            if (c == 'C') {
                C = true;
                s += '2';
            }
            
            if (c == 'D') {
                D = true;
                s += '3';
            }
            
            if (c == 'E') {
                E = true;
                s += '4';
            }
        } 
        
        vector<string> n;
        vector<int> ind;
        
        for (int i = 0; i < 5; i ++) {
            for (int j = 0; j < 5; j ++) {
                for (int k = 0; k < 5; k ++) {
                    for (int l = 0; l < 5; l ++) {
                        for (int m = 0; m < 5; m ++) {
                            if (i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m)
                                continue;
                            
                            string s = "XXXXX";
                            s[0] = (char)(i + '0');
                            s[1] = (char)(j + '0');
                            s[2] = (char)(k + '0');
                            s[3] = (char)(l + '0');
                            s[4] = (char)(m + '0');
                            
                            if (!vis[s])
                                n.push_back(s);
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < 5; i ++) {
            if (n[0][i] != n[1][i]) {
                ind.push_back(i);
            }
        }
        
        char x, y;
        
        cout << 591 + ind[0] << endl;
        cout.flush();
        
        cin >> x;
        
        cout << 591 + ind[1] << endl;
        cout.flush();
        
        cin >> y;
        
        string tmp = ""; tmp += n[0];
        n[0][ind[0]] = (x - 'A' + '0');
        n[0][ind[1]] = (y - 'A' + '0');
        
        if (!n[0].compare(tmp)) {
            n[1][0] = (n[1][0] - '0' + 'A');
            n[1][1] = (n[1][1] - '0' + 'A');
            n[1][2] = (n[1][2] - '0' + 'A');
            n[1][3] = (n[1][3] - '0' + 'A');
            n[1][4] = (n[1][4] - '0' + 'A');
        
            cout << n[1] << endl;
            cout.flush();
        } else {
            n[0] = tmp;
            
            n[0][0] = (n[0][0] - '0' + 'A');
            n[0][1] = (n[0][1] - '0' + 'A');
            n[0][2] = (n[0][2] - '0' + 'A');
            n[0][3] = (n[0][3] - '0' + 'A');
            n[0][4] = (n[0][4] - '0' + 'A'); 
        
            cout << n[0] << endl;
            cout.flush();
        }
        
        char zz;
        cin >> zz;
        
        if (zz == 'N') {
            break;
        }
    }
    
    return (0);
}