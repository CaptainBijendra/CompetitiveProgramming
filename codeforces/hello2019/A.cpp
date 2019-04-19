#include <iostream>

using namespace std;

string str;

int main() {
    cin >> str;
    
    string nstr;
    for (int i = 0; i < 5; i ++) {
        cin >> nstr;
        
        if (str[0] == nstr[0] || str[1] == nstr[1]) {
            cout << "YES" << endl;
            return (0);
        }
    }
    
    cout << "NO" << endl;
}