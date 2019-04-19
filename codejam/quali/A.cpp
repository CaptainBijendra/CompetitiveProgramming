#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        string x;
        cin >> x;
        
        string a = "";
        string b = "";
        
        bool flag = false;
        
        for (int j = 0; j < x.size(); j ++) {
            if (x[j] == '0' && flag) {
                a += '0';
                b += '0';
            }
            
            if (x[j] == '1') {
                a += '1';
                
                if (flag)
                    b += '0';
            }
            
            else
                flag = true;
            
            if (x[j] == '2') {
                a += '1';
                b += '1';
            }
            
            if (x[j] == '3') {
                a += '2';
                b += '1';
            }
            
            if (x[j] == '4') {
                a += '3';
                b += '1';
            }
            
            if (x[j] == '5') {
                a += '3';
                b += '2';
            }
            
            if (x[j] == '6') {
                a += '5';
                b += '1';
            }
            
            if (x[j] == '7') {
                a += '6';
                b += '1';
            }
            
            if (x[j] == '8') {
                a += '7';
                b += '1';
            }
            
            if (x[j] == '9') {
                a += '8';
                b += '1';
            }
        }
        
        cout << "Case #" << (i + 1) << ": " << a << " " << b << endl;
    }
    
    return (0);
}