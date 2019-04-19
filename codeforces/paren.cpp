#include <iostream>
#include <math.h>

using namespace std;

string str;

int N;

int abs(int a) {
    return (a < 0 ? -a : a);
}

int main() {
    cin >> N;
    cin >> str;

    int s = 0;
    int q = 0;

    for (int i = 0; i < N; i ++) {
        if (str[i] == '(')
            s ++;
        if (str[i] == ')')
            s --;
        if (str[i] == '?')
            q ++;
    }
    
    if ((q - abs(s)) % 2 == 1 || abs(s) > q) {
        cout << ":(" << endl;
        return (0);
    }
    
    int pos = ((q - abs(s)) / 2) + max(0, -s);
    int pre = 0;

    for (int i = 0; i < N; i ++) {
        if (str[i] == '?') {
            if (pos) {
                str[i] = '(';
                pos --;
                pre ++;
            }
            
            else {
                str[i] = ')';
                pre --;
            }
        }
        
        else
            pre += (str[i] == '(' ? 1 : -1);
        
        if (pre <= 0 && i != N - 1) {
            cout << ":(" << endl;
            return (0);
        }
    }
    
    if (pre != 0) {
        cout << ":(" << endl;
        return (0);
    }
    
    cout << str << endl;
    return (0);
}