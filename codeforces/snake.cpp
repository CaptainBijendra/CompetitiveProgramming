#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int ask (int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    cout.flush();
    
    int x;
    cin >> x;

    return (x);
}

int main() {
    int N;
    cin >> N;
    
    vector<int> row;
    vector<int> col;
    
    for (int i = 1; i <= N; i ++) {
        int x = ask(1, i, N, i);
    
        if (x % 2)
            col.push_back(i);
    }
    
    for (int i = 1; i <= N; i ++) {
        int x = ask(i, 1, i, N);
    
        if (x % 2)
            row.push_back(i);
    }
    
    if (col.size() == 2 && row.size() == 2) {
        if (ask(row[0], col[0], row[0], col[0]) % 2 == 1 && ask(row[1], col[1], row[1], col[1]) % 2 == 1) {
            cout << "! " << row[0] << " " << col[0] << " " << row[1] << " " << col[1] << endl;
            cout.flush();
        }
        
        else {
            cout << "! " << row[0] << " " << col[1] << " " << row[1] << " " << col[0] << endl;
            cout.flush();            
        }
    }
    
    else {
        if (col.size() == 2) {
            int low = 1;
            int hi = N;
            
            while (low + 1 < hi) {
                int mid = (low + hi) / 2;
                
                if (ask(1, min(col[0], col[1]) + 1, mid, max(col[0], col[1])) % 2 == 1)
                    hi = mid;
                else
                    low = mid;
            }
            
            if (ask(low, min(col[0], col[1]) + 1, low, max(col[0], col[1])) % 2 == 0)
                low ++;
            
            cout << "! " << low << " " << col[0] << " " << low << " " << col[1] << endl;
        }
        
        else {
            int low = 1;
            int hi = N;
            
            while (low + 1 < hi) {
                int mid = (low + hi) / 2;
                
                if (ask(min(row[0], row[1]) + 1, 1, max(row[0], row[1]), mid) % 2 == 1)
                    hi = mid;
                else
                    low = mid;
            }
            
            if (ask(min(row[0], row[1]) + 1, low, max(row[0], row[1]), low) % 2 == 0)
                low ++;
            
            cout << "! " << row[0] << " " << low << " " << row[1] << " " << low << endl;
        }
    }
    
    return (0);
}
