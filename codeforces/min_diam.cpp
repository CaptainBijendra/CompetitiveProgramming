#include <iostream>
#include <vector>
#include <iomanip>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

int N, S;

int main() {
    cin >> N >> S;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        cin >> a >> b; a--; b--; 
        con[a].push_back(b);
        con[b].push_back(a);
    }
    
    int c = 0;
    for (int i = 0; i < N; i ++)
        if (con[i].size() == 1)
            c ++;
    
    cout << setprecision(20) << (2.0 * (S * 1.0 / c * 1.0)) << endl;
    return (0);
}