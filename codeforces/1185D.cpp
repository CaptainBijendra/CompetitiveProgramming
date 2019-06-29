#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <string.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

ii ar[MAX_N];

int N;

int main() {
    cin >> N;
    
    if (N == 2 || N == 3) {
        cout << 1 << endl;
        return (0); 
    }
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i].f;
        ar[i].s = i;
    }
    
    sort(ar, ar + N);
    
    bool flag = true;

    //First element is wrong
    int diff = ar[2].f - ar[1].f;
    for (int i = 3; i < N; i ++) {
        if (ar[i].f - ar[i - 1].f != diff) {
            flag = false;
            break;
        }
    }
    
    if (flag) {
        cout << ar[0].s + 1 << endl;
        return (0);
    }
    
    flag = true;
    
    //Last element is wrong
    diff = ar[1].f - ar[0].f;
    for (int i = 2; i < N - 1; i ++) {
        if (ar[i].f - ar[i - 1].f != diff) {
            flag = false;
            break;
        }
    } 
    
    if (flag) {
        cout << ar[N - 1].s + 1 << endl;
        return (0);
    }

    if (N == 4) {
        int d1 = ar[1].f - ar[0].f;
        int d2 = ar[2].f - ar[1].f;
        int d3 = ar[3].f - ar[2].f;
        
        if (d1 == (d2 + d3))
            cout << ar[2].s + 1 << endl;
        else if (d2 == (d1 + d3))
            cout << "-1" << endl;
        else if (d3 == (d1 + d2))
            cout << 
        else {
            cout << "-1" << endl;
            return (0);
        }
    }
    
    flag = true;
    
    map<int, int> found;
    int cnt = 0, cnt2 = 0;
    
    //Some element in the middle is wrong
    for (int i = 1; i < N; i ++) {
        if (!found[ar[i].f - ar[i - 1].f]) 
            cnt ++;
        
        found[ar[i].f - ar[i - 1].f] ++;
        
        if (found[ar[i].f - ar[i - 1].f] >= 2)
            cnt2 ++;
    }
    
    if (!((cnt == 3 && cnt2 == 1) || (cnt == 2 && cnt2 == 2))) {
        cout << "-1" << endl;
        return (0);
    }
    
    vector<int> vc;
    
    if (cnt == 2) {
        for (map<int, int>::iterator it = found.begin(); it != found.end(); it ++)
            vc.push_back(it->first);
            
        if (vc[0] * 2 != vc[1]) {
            cout << "-1" << endl;
            return (0);
        }
        
        for (int i = 1; i < N; i ++) {
            if (ar[i].f - ar[i - 1].f == vc[0]) {
                cout << ar[i].s + 1 << endl;
                return (0);
            }
        }
        
        cout << "-1" << endl;
        return (0);
    }
    
    for (int i = 1; i < N; i ++) {
        if (found[ar[i].f - ar[i - 1].f] == 1) {
            cout << ar[i].s + 1 << endl;
            return (0);
        }
    }
    
    cout << "-1" << endl;
    return (0);
}