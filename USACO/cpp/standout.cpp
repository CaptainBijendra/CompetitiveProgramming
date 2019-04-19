#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <math.h>

#define MOD 59616771737983
#define MAX_N 300005
#define f first 
#define s second

using namespace std;

string str[MAX_N];

char big[MAX_N];

vector<long long> hash_sub[1005];
unordered_map<long long, long long> pos;

long long hsh[MAX_N], powr[MAX_N];
long long N;

void build_hash() {
    powr[0] = 1ll;
    hsh[0] = (big[0] - 'a' + 1ll);
    
    for (long long i = 1; i < MAX_N; i ++) {
        powr[i] = (powr[i - 1] * 41) % MOD;
        hsh[i] = (hsh[i - 1] * 41 + (big[i] - 'a' + 1)) % MOD;
    }        
}

vector<long long> build_sub(string str) {
    vector<long long> sol;
    sol.push_back(str[0] - 'a' + 1);
    
    for (long long i = 1; i < str.size(); i ++)
        sol.push_back((sol[i - 1] * 41 + (str[i] - 'a' + 1) % MOD)); 

    return (sol);
}

long long sub(long long i, long long j) {
    return ((((hsh[j] - (i == 0 ? 0 : hsh[i - 1]) * powr[j - i + 1]) + MOD) % MOD + MOD) % MOD);
}

long long hsh_sub(long long ind, long long i, long long j) {
    return ((((hash_sub[ind][j] - (i == 0 ? 0ll : hash_sub[ind][i - 1]) * powr[j - i + 1]) + MOD) % MOD + MOD) % MOD);
}

int main() {
    ifstream fin ("standingout.in");
    ofstream fout ("standingout.out");
    
    fin >> N;
    
    long long cnt = 0;
    
    for (long long i = 0; i < N; i ++) {
        fin >> str[i];
        
        for (long long j = 0; j < str[i].size(); j ++) {
            big[cnt] = str[i][j];
            cnt ++;
        }    
        
        big[cnt] = 'X';
        cnt ++;
    }
    
    build_hash();
    
    for (long long i = 0; i < N; i ++)
        hash_sub[i] = build_sub(str[i]);
    
    for (long long i = 0; i < cnt; i ++)
        for (long long j = i; j < cnt; j ++) 
            pos[sub(i, j)] ++;

    long long ans = 0ll;    
    for (long long ii = 0; ii < N; ii ++) {
        ans = 0ll;
        
        unordered_map<long long, long long> copies;
        unordered_map<long long, bool> vis;

        for (long long i = 0; i < str[ii].size(); i ++)
            for (long long j = i; j < str[ii].size(); j ++) 
                copies[hsh_sub(ii, i, j)] ++;
 
        for (long long i = 0; i < str[ii].size(); i ++) {
            for (long long j = i; j < str[ii].size(); j ++) {
                if (!vis[hsh_sub(ii, i, j)] && copies[hsh_sub(ii, i, j)] == pos[hsh_sub(ii, i, j)]) {
                    ans ++;
                    vis[hsh_sub(ii, i, j)] = true;
                }
            }
        } 
        
        fout << ans << endl;
    }
    
    return (0);
}