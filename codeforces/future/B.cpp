#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

string str;

int ar[MAX_N];
int N, M;

int main() {
    cin >> str;
    N = str.size();
    
    int ind = 0;
    int cnt = 0;
    
    for (int i = 0; i < str.size(); i ++)
        if (str[i] == 'a') {
            ind = i;
            cnt ++;
        }
    
    string s = "";
    
    for (int i = 0; i < ind; i ++) {
        if (str[i] == 'a') 
            continue;
        
        s += str[i];
    }
    
    int ans = -1;
    
    for (int i = ind; i < str.size(); i ++) {
        if (str[i] != 'a')
            s += str[i];  
        
        if (str.substr(i + 1, str.size() - i).compare(s) == 0) {
            ans = i;
            break;
        }
    }
    
    if (cnt == N) {
        cout << str << endl;
        return (0);
    }
    
    if (ans == -1) {
        cout << ":(" << endl;
        return (0);
    } else {
        for (int i = 0; i <= ans; i ++)
            cout << str[i];
        
        cout << endl;
    }
    
    return (0);
}