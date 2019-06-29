#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

string str;

int ar[MAX_N];
int N, M;

int main() {
    cin >> str;
    N = str.size();
    
    int cnt = 0;
    
    for (int i = 0; i < str.size(); i ++)
        if (str[i] == 'a')
            cnt ++;
        
    while (N >= 2 * cnt)
        N --;
    
    cout << N << endl;
    return (0);
}