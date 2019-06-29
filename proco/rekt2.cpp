#include <iostream>
#include <algorithm>
#include <string.h>
#include <string.h>
#include <queue>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

string st;

int func() {
	int M = 14000605;
    int len = st.size();
    int hash = 0;
    
    for (int i = len - 1; i >= 0; i--) {
        hash = (2*hash + 5) % M;
    }
    return hash;
}

int main() {
    string a = "theavengers";
    string b = "thanos";
    
    st = a;
    
    for (int i = 1; i < 10000; i ++) {
        int x = func(); st = b;
        int y = func(); st = a;
        
        cout << x << " " << y << endl;
        
        if (x == y) {
            cout << i << endl;
            return (0);
        }
        
        a += "theavengers";
        b += "thanos";
    }
}
