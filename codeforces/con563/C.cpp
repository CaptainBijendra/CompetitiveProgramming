#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <iomanip>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

int main() {
    cin >> N;
    
    vector<int> vc;
    
    for (int i = max(0, N - 10000000); i <= N; i ++) {
        int sum = 0;
        int tmp = i;
        
        while (tmp > 0) {
            sum += (tmp % 10);
            tmp /= 10;
        }
        
        if (i + sum == N) {
            vc.push_back(i);
        }
    }
    
    cout << vc.size() << endl;
    
    for (int i = 0; i < vc.size(); i ++)
        cout << vc[i] << " ";
    
    cout << endl;
    return (0);
}