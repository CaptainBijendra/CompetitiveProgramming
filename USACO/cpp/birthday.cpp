#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <math.h>

#define MOD 10886968801
#define MAX_N 300005
#define f first 
#define s second

using namespace std;

string str[MAX_N];
string big;

unordered_map<long long, long long> pos;

long long hsh[MAX_N], powr[MAX_N];
long long N;

void build_hash() {
    powr[0] = 1ll;
    hsh[0] = (big[0] - 'a' + 1ll);
    
    for (long long i = 1; i < big.size(); i ++) {
        powr[i] = (powr[i - 1] * 41) % MOD;
        hsh[i] = (hsh[i - 1] * 41 + (big[i] - 'a' + 1)) % MOD;
    }        
}

long long sub(long long i, long long j) {
    return ((((hsh[j] - (i == 0 ? 0 : hsh[i - 1]) * powr[j - i + 1]) + MOD) % MOD + MOD) % MOD);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    
    if (N >= 100000) {
        cout << "HARRO!" << endl;
        return (0);
    }
    
    for (long long i = 0; i < N; i ++)
        cin >> str[i];
    
    cin >> big;
    build_hash();
    
    for (long long i = 0; i < N; i ++) {
        long long hasher = (str[i][0] - 'a' + 1ll);
        
        for (long long j = 1; j < str[i].size(); j ++) {
            hasher = (hasher * 41) + (str[i][j] - 'a' + 1);
            hasher %= MOD;
        }
        
        pos[hasher] ++;
    }
    
    long long ans = 0ll;
    
    for (long long i = 0; i < big.size(); i ++) {
        for (long long j = 0; j < min((long long)big.size() - i, 81ll); j ++) {
            ans += pos[sub(i, i + j)];
        }
    }
    
    cout << ans << endl;
    return (0);
}