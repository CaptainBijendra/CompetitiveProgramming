#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>

#define MAX_N 10005
#define f first
#define s second

using namespace std;

string str;

int ar[MAX_N];
int N;

int main() {
    cin >> N;
    cin >> str;
    
    int sumOfDigits = 0;
    
    for (int i = 0; i < N; i ++) {
        ar[i] = (str[i] - '0');
        sumOfDigits += ar[i];
    }
    
    if (sumOfDigits == 0) {
        cout << "YES" << endl;
        return (0);
    }
    
    for (int i = 0; i < sumOfDigits; i ++) {
        int sum = 0;
        int split = 0;
        
        bool flag = true;
    
        for (int j = 0; j < N; j ++) {
            sum += ar[j];
        
            if (j == N - 1) {
                if (sum != i) {
                    flag = false;
                    break;
                }
            }
        
            if (sum == i) {
                sum = 0;
                split ++;
            }
        
            if (sum > i) {
                flag = false;
                break;
            }
        }
    
        if (flag && split >= 1) { 
            cout << "YES" << endl;
            return (0);
        }        
    }
    
    cout << "NO" << endl;
    return (0);
}