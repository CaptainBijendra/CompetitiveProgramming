#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int X;

int main() {
    cin >> X;
    
    for (int i = 1; i <= X; i ++) {
        for (int j = 1; j <= X; j ++) {
            if (i % j == 0 && i * j > X && i / j < X)  {
                cout << i << " " << j << endl;
                return (0);
            }   
        }
    }    
    
    cout << "-1" << endl;
    return (0);
}