#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int vis[MAX_N];
int N;

int main() {
    cin >> N;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    

    return (0);
}