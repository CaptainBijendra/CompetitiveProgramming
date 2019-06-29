#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <math.h>

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

int rem[7][18], sum[7];

int nums[7] = { 17, 13, 11, 7, 5, 3, 2 };
int N, T, M;

int main() {
    cin >> T;
    cin >> N >> M;
    
    for (int ii = 1; ii <= T; ii ++) {
        for (int jj = 0; jj < 7; jj ++) { 
            sum[jj] = 0;
            
            cout << nums[jj];
            for (int i = 1; i < 18; i ++)
                cout << " " << nums[jj];
            
            cout << endl;
            cout.flush();
            
            for (int i = 0; i < 18; i ++) { 
                cin >> rem[jj][i];
                sum[jj] += rem[jj][i];
            }
        }
        
        int s = 0;
        
        for (int j = 1; j < MAX_N; j ++) {
            bool flag = true;
                
            for (int k = 0; k < 7; k ++)
                if (j < sum[k] || ((j - sum[k]) % nums[k] != 0)) {
                    flag = false;
                    break;
                }
                    
            if (flag) {
                s = j;
                break;
            }
        }
        
        cout << s << endl;
        cout.flush();
        
        int x;
        cin >> x;
    
        if (x == -1)
            break;
    }
    
    return (0);
}