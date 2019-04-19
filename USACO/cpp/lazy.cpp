#include <iostream>
#include <algorithm>
#include <deque>

#define MAX_N 100005

using namespace std;

deque<int> d;

int ar[MAX_N];
int T, N;

int main() {
    cin >> T;

    for (int ii = 0; ii < T; ii ++) {
        cin >> N;

        for (int i = 0; i < N; i ++)
            cin >> ar[i];

        int l = 1;
        int r = N - 1;
        int f = ar[0], s = ar[0];
        
        bool flag = false;
        
        for (int i = 0; i < N - 1; i ++) {
            if (ar[l] == f - 1) {
                f --;
                l ++;
            }
            
            else if (ar[l] == s + 1) {
                s ++;
                l ++;
            }
            
            else if (ar[r] == f - 1) {
                f --;
                r --;
            }
            
            else if (ar[r] == s + 1) {
                s ++;
                r --;
            }
            
            else {
                flag = true;
                break;
            }        
        }
        
        if (flag) {
            flag = false;
            l = 0;
            r = N - 2;
            f = ar[N - 1];
            s = ar[N - 1];
            
        for (int i = 0; i < N - 1; i ++) {
            if (ar[l] == f - 1) {
                f --;
                l ++;
            }
            
            else if (ar[l] == s + 1) {
                s ++;
                l ++;
            }
            
            else if (ar[r] == f - 1) {
                f --;
                r --;
            }
            
            else if (ar[r] == s + 1) {
                s ++;
                r --;
            }
            
            else {
                cout << "Case #" << (ii + 1) << ": no" << endl;
                flag = true;
                break;
            }        
        }
        }
        
        if (!flag)
            cout << "Case #" << (ii + 1) << ": yes" << endl;

        d.clear();
    }

    return (0);
}