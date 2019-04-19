#include <iostream>
#include <fstream>
#include <vector>

#define MAX_N 100005

using namespace std;

vector<long long> con[MAX_N];
vector<long long> dir;

bool vis[MAX_N];

long long DP[MAX_N], num_el[MAX_N];

long long len[MAX_N], con2[MAX_N];
long long N;

long long DFS (long long ind) {
    long long cind, ans;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        cind = con[ind][i];
        
        if (con[cind].size() == 0) { 
            DP[ind] += len[cind];
            DP[cind] = len[cind]; 
            
            num_el[ind] ++; num_el[cind] = 1;
        }
        
        else {
            ans = DFS(cind);
            num_el[ind] += num_el[cind];
            
            DP[ind] += (ans + (num_el[cind]) * (len[cind] + 1));
        }
    }

    return (DP[ind]);
} 

long long DFS_2 (long long ind, long long depth, long long prev) {
    long long sum = 0, cind;
    
    for (int i = 0; i < con[ind].size(); i ++) {
        cind = con[ind][i];
        
        if (cind != prev) {
            if (con[cind].size() == 0) {
                sum += (3 * depth) + len[cind];
            }

            else {
                sum += (3 * depth * num_el[cind]) + DP[cind] + 
                       (len[cind] + 1) * num_el[cind];
            }
        }
    }
    
    if (ind != 0) 
    { sum += DFS_2 (con2[ind], depth + 1, ind); }
        
    return (sum);
}

int main() {
    ifstream fin ("dirtraverse.in");
    ofstream fout ("dirtraverse.out");

    fin >> N;
    string tmp;
    
    long long a, b;

    for (int i = 0; i < N; i ++) {
        fin >> tmp >> a;
     
        len[i] = tmp.size();

        for (int j = 0; j < a; j ++) {
            fin >> b; 
        
            con[i].push_back(b - 1);
            con2[b - 1] = i;
        }

        if (a > 0) { dir.push_back(i); }
    }
    
    long long ans = 9223372036854775807;

    DFS (0);   

    if (dir.size() == N)
    { fout << 0 << endl; return (0); }

    for (int i = 0; i < dir.size(); i ++) 
    { ans = min(ans, DFS_2(dir[i], 0, -1)); }

    fout << ans << endl;
    return (0);
}