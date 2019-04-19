#include <iostream>

using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    
    int cnt = 0;
    for (int i = 0; i < 31; i ++) {
        if ((A & (1 << i)) != (B & (1 << i)))
            cnt ++;
    }
    
    cout << cnt << endl;
    return (0);
}