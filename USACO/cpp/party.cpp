#include <iostream>
#include <fstream>
#include <vector>

#define MAX_N 22
#define INF 200000000

using namespace std;

vector<int> con[MAX_N];
vector<int> ans;

int DP[MAX_N][(1 << MAX_N)];
int N, M;

int main() {
    ifstream fin ("party.in");
    ofstream fout ("party.out");
    
    fin >> N >> M;
//    cin >> N >> M;

    for (int i = 0; i < M; i ++) {
        int a, b;

        fin >> a >> b;
//        cin >> a >> b;

        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
   
    if (M <= 1) { cout << 0 << endl; return (0); }

    for (int i = 0; i < N; i ++) { 
        for (int j = 0; j < (1 << N); j ++) 
        { DP[i][j] = INF; }
    }

    for (int i = 0; i < N; i ++) 
    { DP[i][0] = 0; con[i].push_back(i); }

    for (int i = 0; i < (1 << N); i ++) {
        for (int j = 0; j < N; j ++) {
            int mask = i;

            for (int k = 0; k < con[j].size(); k ++) 
            { mask = (mask | (1 << con[j][k])); }

            for (int k = 0; k < con[j].size(); k ++) {
                DP[con[j][k]][mask] = min(DP[con[j][k]][mask], (DP[j][i] | (1 << j)));
            }
        }
    }

    int mIn = -1;

    for (int i = 0; i < N; i ++) { mIn = (mIn == -1 ? i : (DP[i][(1 << N) - 1] < DP[mIn][(1 << N) - 1] ? i : mIn)); }
    for (int j = 0; j < N; j ++) { 
        if (DP[mIn][(1 << N) - 1] & (1 << j)) 
        { ans.push_back(j + 1); }
    }

    fout << ans.size() << endl;
    fout << ans[0];

//    cout << ans.size() << endl;
//    cout << ans[0];

    for (int i = 1; i < ans.size(); i ++) {
        fout << " " << ans[i];
//        cout << " " << ans[i];
    }

    fout << endl;
//    cout << endl;
    return (0);
}