#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <set>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int cnt[255];

int ar[MAX_N];
int N, M;

int main() {
    string str;
    cin >> str;
    
    for (int i = 0; i < str.size(); i ++) {
        cnt[str[i]] ++;
    }
    
    int max = 0;
    int ans = -1;
    
    for (int i = 0; i < 255; i ++) {
        if (cnt[i] > max) {
            ans = i;
            max = cnt[i];
        }
    }
    
    cout << (char)(ans) << endl;
    cout << str << endl;
    return (0);
}