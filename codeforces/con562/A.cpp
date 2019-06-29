#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <vector>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N, A, X, B, Y;

int main() {
    cin >> N >> A >> X >> B >> Y;
    
    int daniel = A;
    int vlad = B;
    
    bool flag = true;
    
    while (true) {
        
        if (daniel == vlad && (flag || (daniel != X && vlad != Y))) {
            cout << "YES" << endl;
            return (0);
        }
        
        if (daniel == X && vlad == Y) {
            break;
        }
        
        if (daniel != X) {
            if (daniel < N)
                daniel ++;
            else
                daniel = 1;
        } else 
            flag = false;
    
        if (vlad != Y) {
            if (vlad > 1)
                vlad --;
            else
                vlad = N;
        }  else
            flag = false;
    }
    
    cout << "NO" << endl;

    return (0);
}