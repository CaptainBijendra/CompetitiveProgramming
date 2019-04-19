#include <iostream>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

vector<int> sol;

string str;

int ar[MAX_N], pre[MAX_N];
int N, A, B, K;

int main() {
    cin >> N >> A >> B >> K;
    cin >> str;

    for (int i = 0; i < N; i ++)
        ar[i] = (str[i] - '0');

    pre[0] = !ar[0];
    for (int i = 1; i < N; i ++)
        pre[i] = pre[i - 1] + !ar[i];

    int ans = 0;
    int flag = false;
    
    for (int i = B - 1; i < N; i ++) {
        if (ar[i])
            continue;
        
        if (i - B + 1 >= 0 && pre[i] - pre[i - B] == B) {
            sol.push_back(i + 1);
            i += (B - 1);
        }
    }

    cout << (sol.size() - A + 1) << endl;

    for (int i = 0; i < sol.size() - A + 1; i ++) 
        cout << sol[i] << " ";
    
    cout << endl;
    return (0);
}