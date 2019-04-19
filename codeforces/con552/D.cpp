#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int ar[MAX_N];
int N, X, Y, A, B;

int main() {
    cin >> N >> X >> Y;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
        
    int loc = 0;
    
    A = X;
    B = Y;
        
    while ((A > 0 || B > 0) && loc < N) {
        if (ar[loc] == 0) {
            if (B > 0)
                B --;
            else
                A --;
        }
        
        else {
            if (A > 0) {
                if (B < Y) {
                    A --;
                    B = min(Y, B + 1);
                }
                
                else
                    B --;
                    
            }
            
            else
                B --;
        }
        
        loc ++;
    }
    
    cout << loc << endl;
    return (0);
}