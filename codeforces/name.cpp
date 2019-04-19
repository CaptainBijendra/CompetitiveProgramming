#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <string.h>
#include <string>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

string str;

int N;

bool palin(string a) {
    bool pal = true;
    
    for (int i = 0; i < a.size(); i ++) {
        if (i >= a.size() - 1 - i)
            break;
        
        pal = (pal && (a[i] == a[a.size() - 1 - i]));
    }
    
    return (pal);
}

bool test(string a, string b) {
    return (palin(b + a) && (!((b + a).compare(str) == 0)));
}

int main() {
    cin >> str;
    N = str.size();

    if (N == 1) {
        cout << "Impossible" << endl;
        return (0);
    }

    bool same = true;
    bool same2 = true;

    for (int i = 1; i < N; i ++)
        same = (same && (str[i] == str[0]));

    for (int i = 1; i < N; i ++) {
        if (i == N / 2)
            continue;
        
        same2 = (same2 && (str[i] == str[0]));
    }
        
    if (N % 2 == 0) {
        if (same) {
            cout << "Impossible" << endl;
            return (0);
        }
    }

    else {
        if (same2) {
            cout << "Impossible" << endl;
            return (0);
        }    
    }

    for (int i = 0; i < N - 1; i ++) {
        if (test(str.substr(0, (i + 1)), str.substr((i + 1), (N - i - 1)))) {
            cout << 1 << endl;
            return (0);
        }
    }
    
    cout << 2 << endl;
    return (0);
}