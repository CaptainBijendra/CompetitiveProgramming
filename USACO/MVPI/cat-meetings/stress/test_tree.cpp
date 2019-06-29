#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];

bool vis[MAX_N];

int DP[MAX_N];
int N;

int big_degree, big_depth, big_diameter, cur_diam;

void DFS (int ind) {
    vis[ind] = true;
    
    vector<int> vc;
    
    for (int i = 0; i < con[ind].size(); i ++)
        if (!vis[con[ind][i]]) {
            DFS (con[ind][i]);
            DP[ind] = max(DP[ind], DP[con[ind][i]] + 1);
            
            vc.push_back(DP[con[ind][i]] + 1);
        }
    
    big_degree = max(big_degree, (int)con[ind].size() - 1);
    sort(vc.begin(), vc.end());
    
    if (vc.size() == 0)
        return;
    else if (vc.size() == 1)
        cur_diam = max(cur_diam, vc[0]);
    else
        cur_diam = max(cur_diam, vc[vc.size() - 1] + vc[vc.size() - 2]);
}

int main() {
    string str;
    
    cout << "File input" << endl;
    cin >> str;
    
    string str1 = str + ".in";
    
    ifstream fin (str1.c_str());
    fin >> N;
    
    int a, b;
    for (int i = 0; i < N - 1; i ++) {
        fin >> a >> b;
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
    
    int components = 0;

    big_degree = big_depth = big_diameter = cur_diam = 0;
    for (int i = 0; i < N; i ++) {
        if (!vis[i]) {
            components ++;
            DFS(i);
            
            big_depth = max(big_depth, DP[i]);
            big_diameter = max(big_diameter, cur_diam);
            
            cur_diam = 0;
        }
    }
    
    cout << "# of components: " << components << endl;
    cout << "Maximum depth: " << big_depth << endl;
    cout << "Maximum Diameter: " << big_diameter << endl;
    cout << "Maximum degree: " << big_degree << endl;
    return (0);
}