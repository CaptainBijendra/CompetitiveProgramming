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
    
    nw.push_back(ii(s, c));
    
    int ops = 0;
    
    while (nw.size() > 1) {
        vector<ii> step1, step2;
        
        if (nw[0].f > 1)
            step1.push_back(ii(nw[0].f - 1, nw[0].s));
        
        for (int i = 1; i < nw.size() - 1; i ++) {
            if (nw[i].f > 2)
                step1.push_back(ii(nw[i].f - 2, nw[i].s));
        }
        
        if (nw[nw.size() - 1].f > 1)
            step1.push_back(ii(nw[nw.size() - 1].f - 1, nw[nw.size() - 1].s));
        
        if (step1.size() > 0) {
            s = step1[0].f;
            c = step1[0].s;
        }
        
        for (int i = 1; i < step1.size(); i ++) {
            if (step1[i].s != c) {
                step2.push_back(ii(s, c));
                
                s = step1[i].f;
                c = step1[i].s;
            }
            
            else
                s += step1[i].f;
        }
        
        step2.push_back(ii(s, c));
        ops ++;
        
        nw.clear();
        for (int i = 0; i < step2.size(); i ++)
            nw.push_back(step2[i]);
    }
    
    cout << ops << endl;
    return (0);    
}