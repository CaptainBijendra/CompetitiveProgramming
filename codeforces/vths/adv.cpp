#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

vector<int> stck;
string str;

int T;

int main() {
    cin >> T;

    for (int i = 0; i < T; i ++) {
        cin >> str;
        stck.clear();
        
        for (int j = 0; j < str.size(); j ++) {
            if (str[j] == '$')
                stck.push_back(1);
            if (str[j] == '|')
                stck.push_back(2);
            if (str[j] == '*')
                stck.push_back(3);
            
            if (str[j] == 'b') {
                if (stck.size() == 0) {
                    cout << "NO" << endl;
                    break;
                }   
                
                int a = stck[stck.size() - 1];
                stck.pop_back();

                if (a != 1) {
                    cout << "NO" << endl;
                    break;
                }
            }
            
            if (str[j] == 't') {
                if (stck.size() == 0) {
                    cout << "NO" << endl;
                    break;
                }
                
                int a = stck[stck.size() - 1];
                stck.pop_back();

                if (a != 2) {
                    cout << "NO" << endl;
                    break;
                }
            }
            
            if (str[j] == 'j') {
                if (stck.size() == 0) {
                    cout << "NO" << endl;
                    break;
                }        
                
                int a = stck[stck.size() - 1];
                stck.pop_back();
                
                if (a != 3) {
                    cout << "NO" << endl;
                    break;
                }
            }
        
            if (j == str.size() - 1 && stck.size() == 0)
                cout << "YES" << endl;
            else if (j == str.size() - 1 && stck.size() > 0)
                cout << "NO" << endl;
        }
    }    
}