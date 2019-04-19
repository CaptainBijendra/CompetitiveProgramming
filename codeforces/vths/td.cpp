#include <iostream>

using namespace std;

int ar[100005];
int N;

int main() {
    cin >> N;
    
    int sum = 0, cnt = 0, cnter = 0;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        sum += ar[i];
        cnt += ar[i];
        cnter ++;
        
        if ((cnter % 4 == 0 && cnter != 0)) {
            if (cnt < 10)  
                break;
        }
        
        if (cnt >= 10) {
            cnt = 0;
            cnter = 0;
        }
    
        if (sum >= 80) {
            cout << "Touchdown" << endl;
            return (0);
        }
        
        else if (sum == -20) {
            cout << "Safety" << endl;
            return (0);
        }
    }
    
    cout << "Nothing" << endl;
    return (0);
}