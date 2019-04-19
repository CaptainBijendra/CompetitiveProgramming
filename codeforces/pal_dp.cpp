#include <iostream>
#include <algorithm>

#define MAX_N 5205
#define f first
#define s second

using namespace std;

string str;

bool pal[MAX_N][MAX_N];

long long DP[MAX_N][MAX_N], ar[MAX_N];
long long N, M;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> str;
    N = str.size();
    
    for (int i = 0; i < N; i ++) {
        ar[i] = str[i] - 'a';
        DP[i][i] = 1;
        pal[i][i] = 1;
    
        if (i > 0) {
            if (ar[i] == ar[i - 1]) {
                DP[i - 1][i] = 3;
                pal[i - 1][i] = 1;
            }
            
            else
                DP[i - 1][i] = 2;
        }
    }
    
    for (int len = 3; len <= N; len ++) {
        for (int l = 0; l < N; l ++) {
            int r = (l + len - 1);
            
            if (r > N)
                break;
            
            if (ar[l] == ar[r])
                pal[l][r] = pal[l + 1][r - 1];
                
            DP[l][r] = DP[l + 1][r] + DP[l][r - 1] - DP[l + 1][r - 1];
            DP[l][r] += pal[l][r];
        }
    }
    
    cin >> M;
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        cout << DP[a - 1][b - 1] << '\n';
    }

    return (0);
}