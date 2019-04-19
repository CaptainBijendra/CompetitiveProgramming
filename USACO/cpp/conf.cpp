#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <queue>

#define MAX_N 100000
#define f first
#define s second

using namespace std;

int ar[MAX_N], ar2[MAX_N];
int T, N, M;

int main() {
    ifstream fin ("conf.in");
    ofstream fout ("conf.out");
    
    fin >> T;
    
    for (int i = 0; i < T; i ++) {
        fin >> N >> M;
        
        for (int j = 0; j < N; j ++)
            fin >> ar[j];
        
        for (int j = 0; j < M; j ++)
            fin >> ar2[j];
        
        sort(ar, ar + N); 
        sort(ar2, ar2 + M);
        
        int l = 0;
        int cnt = 0;
        int ans = 0;
        
        for (int r = 0; r < M; r ++) {
            while (l != N && ar[l] <= ar2[r]) 
                l ++;
                    
            if (l + cnt > (N - l - cnt)) {
                ans ++;
                cnt ++;
            }
        }
        
        fout << "Expansion #" << (i + 1) << ": " << ans << endl;
    }
    
    return (0);
}