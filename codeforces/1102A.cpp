#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int N;
int main() {
    cin >> N;
    
    if ((N + 1) % 4 == 0 || (N % 4 == 0)) {
        cout << "0" << endl;
        return (0);
    }
    
    cout << "1" << endl;
    return (0);    
}