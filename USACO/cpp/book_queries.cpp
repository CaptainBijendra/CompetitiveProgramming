#include <iostream>
#include <algorithm>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

int main() {
    cin >> N;
    
    int c_l = 0;
    int c_r = 0;
    
    for (int i = 0; i < N; i ++) {
        char a;
        int b;
        
        cin >> a >> b;

        if (i == 0) {
            ar[b] = 0;
            c_l --;
            c_r ++;
        
            continue;
        }

        if (a == 'L') {
            ar[b] = c_l;
            c_l --;
        }        
        
        else if (a == 'R') {
            ar[b] = c_r;
            c_r ++;
        }
        
        else {
            cout << min(ar[b] - c_l, c_r - ar[b]) - 1 << endl;
        }
    }
    
    return (0);
}