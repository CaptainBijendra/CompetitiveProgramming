#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 305
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

ii ar[MAX_N];

int T, N;

int main() {
    cin >> T;

    for (int ii = 0; ii < T; ii ++) {
        cin >> N;
        
        map<pair<int, int>, bool> vis;
        
        for (int i = 0; i < N; i ++)
            cin >> ar[i].f >> ar[i].s;
        
        for (int i = 0; i < N; i ++) {
            for (int j = i + 1; j < N; j ++) {
                if (ar[i].f <= ar[j].f && ar[i].s <= ar[j].s || 
                    ar[j].f <= ar[i].f && ar[j].s <= ar[i].s)
                    continue;
                
                if (ar[j].s == ar[i].s)
                    vis[pair<int, int>(-1, 1)] = true;
                else {
                    int num = abs(ar[i].f - ar[j].f);
                    int den = abs(ar[i].s - ar[j].s);
                
                    vis[pair<int, int>(num / __gcd(num, den), den / __gcd(num, den))] = true;
                }
            }
        }
        
        cout << "Case #" << (ii + 1) << ": " << (vis.size() + 1) << endl;
    }
        
    return (0);
}