#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>

#define MOD 1000000007
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

vector<ii> cHi, cLow;

long long ar[MAX_N], low[MAX_N];
long long N;

long long calc(long long a, long long b, long long c, long long d) {
    if (b >= d)
        return (0);
        
    return (((c - a + 1) * (c - a) / 2) * ((d - b + 1) * (d - b) / 2));
}

int main() {
    ifstream fin ("sprinklers.in");
    ofstream fout ("sprinklers.out");
    
    fin >> N;
    
    long long a, b;
    for (long long i = 0; i < N; i ++) {
        fin >> a >> b;
        ar[a] = b;
        low[a] = MAX_N;
    }
    
    low[0] = ar[0];

    for (long long i = 1; i < N; i ++) 
        low[i] = min(low[i - 1], ar[i]);
        
    long long big = ar[N - 1];

    cHi.push_back(ii(N - 1, ar[N - 1]));
    for (int i = N - 2; i >= 0; i --) 
        if (big < ar[i]) {
            cHi.push_back(ii(i, ar[i]));
            big = ar[i];
        }
    
    reverse(cHi.begin(), cHi.end());

    long long ans = 0ll;
    long long sweep = 0ll;
    
    for (int i = 0; i < N; i ++) {
        while (sweep < cHi.size() && cHi[sweep].f <= i)
            sweep ++;
        
        for (int j = sweep; j < cHi.size(); j ++) {
            long long delta_x = cHi[j].f - i;
            long long delta_y = cHi[j].s - low[i] + 1;
            
            if (delta_y <= 0ll)
                break;
            
            ans += (delta_x * delta_y * (delta_y - 1)) / 2;
            ans %= MOD;
            
            if (sweep != j) {
                delta_x = cHi[j - 1].f - i;
                
                ans -= (delta_x * delta_y * (delta_y - 1)) / 2;
                ans += MOD; ans %= MOD;
                ans += MOD; ans %= MOD;    
            }
        }
    }
    
    fout << ans << endl;
    return (0);
}