#include <iostream>

using namespace std;

int a, b, h;

int main() {
    cin >> a >> b >> h;

    int c_h = 0, cnt = 0;
    
    while (true) {
        c_h += a;
        cnt ++;

        
        if (c_h >= h)
            break;
        
        c_h -= b;
    }
    
    cout << cnt << endl;
    return (0);
}