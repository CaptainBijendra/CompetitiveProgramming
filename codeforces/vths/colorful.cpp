#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

string str;

int main() {
    cin >> str;
    
    vector<ii> nw;
    
    int c = str[0] - 'a';
    int s = 1;
        
    for (int i = 1; i < str.size(); i ++) {
        if (str[i] != str[i - 1]) {
            nw.push_back(ii(s, c));
                
            c = str[i] - 'a';
            s = 1;
        }
            
        else
            s ++;
    }
    
    for (int i = 0; i < nw.size(); i ++) {
        cout << nw[i].f << " " << (char)('a' + nw[i].s) << endl;
    }
    
    return (0);    
}