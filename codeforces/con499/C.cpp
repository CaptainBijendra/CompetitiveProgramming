#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>

#define MAX_N 105
#define f first
#define s second

using namespace std;

string str;

int ar[MAX_N];
int N;

bool pos(int a) {
    int sum = 0;
    
    for (int i = 0; i < N; i ++) {
        sum += ar[i];
        
        if (sum == a) {
            sum = 0;
        }
        
        if (sum > a) {
            return (false);
        }
    }
    
    return (true);
}

int main() {
    cin >> N;
    cin >> str;
    
    for (int i = 0; i < N; i ++) {
        ar[i] = (str[i] - '0');
    }
    
    for (int i = 1; i <= 900; i ++) {
        if (pos(i)) {
            cout << "YES" << endl;
            return (0);
        }
    }
    
    cout << "NO" << endl;
    return (0);
}