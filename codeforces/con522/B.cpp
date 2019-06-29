#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>   
#include <vector>
#include <map>
#include <set>
#include <iomanip>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N, M;

int main() {
    string str;
    cin >> str;
    N = str.size();
    
    for (int i = 1; i <= 5; i ++) {
        //if (N % i == 0) {
            int x = -1;
            
            for (int j = 1; j <= 20; j ++)
                if (i * j >= N) {
                    x = j;
                    break;
                }
            
            if (x == -1)
                continue;
            
            cout << i << " " << x << endl;
            
            int stars = i * x - N;
            int st_row = stars % i;
            int cnt = 0;
            
            for (int ii = 0; ii < i; ii ++) {
                for (int jj = 0; jj < stars / i; jj ++)
                    cout << "*";
                
                bool flag = false;
                if ((i - ii) == st_row) {
                    cout << "*";
                    st_row --;
                    
                    flag = true;
                }
                
                for (int jj = stars / i + flag; jj < x; jj ++) {
                    cout << str[cnt];
                    cnt ++;
                }
            
                cout << endl;
            }
            
            break;
        //}
    }
    
    return (0);
}