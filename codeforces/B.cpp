#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

char ar[MAX_N];
int N, M;

int main() {
    cin >> N >> M;
    
    bool ans = true;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        ans = (ans & (ar[i] == '0'));
    }
    
    cout << (ans ? "EASY" : "HARD");
    return (0);
}