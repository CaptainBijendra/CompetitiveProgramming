#include <iostream>
#include <algorithm>

using namespace std;

string str;
int O, N;

int main() {
    cin >> O;
    cin >> str;
    cin >> N;
    
    int cnt = 0;
    for (int i = 0; i < N; i ++) {
        int v = 0;

        for (int i = 0; i < str.size(); i ++) {
            int a = (str[i] - 'a' + O) % 26;
            char b = a + 'a';
        
            if (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u' || b == 'y')
                v ++;
            
            str[i] = b;
        }
    
        if (2 * v >= (str.size() - v))
            cnt ++;
    }

    if (cnt < N - cnt)
        cout << "Boris" << endl;
    else
        cout << "Colleague" << endl;

    return (0);
}