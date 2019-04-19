#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <math.h>

#define MAX_N 1000000
#define f first
#define s second

using namespace std;

int rem[7][18];

int nums[7] = { 17, 13, 11, 7, 5, 3 };
int N, T, M;

int main() {
    cin >> T >> N >> M;
    
    for (int ii = 1; ii <= T; ii ++) {
        for (int jj = 0; jj < 7; jj ++) { 
            cout << nums[jj];
            for (int i = 1; i < 18; i ++)
                cout << " " << nums[jj];
            
            cout << endl;
            cout.flush();
            
            for (int i = 0; i < 18; i ++)   
                cin >> rem[jj][i];
        }
        
        int sum = 0;
        
        for (int i = 0; i < 18; i ++) {
            for (int j = 0; j < MAX_N; j ++) {
                bool flag = true;
                
                for (int k = 0; k < 7; k ++)
                    if (j % nums[k] != rem[k][i]) {
                        flag = false;
                        break;
                    }
                    
                if (flag) {
                    cout << i << " " << j << endl;
                    sum += j;
                    break;
                }
            }
        }
        
        cout << "Case #" << ii << ": " << sum << endl;
    }
    
    return (0);
}