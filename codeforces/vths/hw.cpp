#include <iostream>

using namespace std;

int A, B, C, D;

int main() {
    cin >> A >> B >> C >> D;
    
    bool flag = false;
    
    for (int i = 0; i <= 250; i ++) {
        for (int j = 0; j <= 250; j ++) {
            for (int k = 0; k <= 250; k ++) {
                if (A * i + B * j + C * k == D) {
                    cout << i << " " << j << " " << k << endl;
                    flag = true;        
                }    
            }
        }
    }
    
    if (!flag)
        cout << "impossible" << endl;
    
    return (0);
}