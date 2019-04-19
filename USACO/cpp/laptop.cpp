#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <queue>
#include <map>

#define INF 2000000009
#define PI 3.14159265
#define MAX_N 20
#define f first
#define s second

using namespace std;

long double dist[MAX_N], DP[(1 << MAX_N)][MAX_N];

char col[MAX_N];

int cnt[256];
int T, N, M;

long double q_dist(int d) {
    if (d > N / 2)
        d = (N - d);

    return (dist[d]);
}

inline long double round (long double val) {
    if( val < 0 ) return ceil(val - 0.5);
    return floor(val + 0.5);
}

int main() {
    ifstream fin ("laptop.in");
    ofstream fout ("laptop.out");
    
    fin >> T;

    for (int ii = 0; ii < T; ii ++) {
        fin >> N >> M;
        
        for (int i = 0; i < N; i ++) {
            fin >> col[i];
            cnt[col[i]] ++;
        }
        
        long double c_dist = 0.0;
        for (int i = 1; i <= N / 2; i ++) {
            c_dist += 360.0 / (N * 1.0);
            
            if (c_dist > 180.0)
                c_dist = 180.0;
        
            dist[i] = M * 1.0 * (long double)(sin(c_dist * PI / 180.0) / sin(((180.0 - c_dist) / 2.0) * PI / 180.0)); 
        }
        
        for (int i = 0; i < (1 << (N)); i ++) 
            for (int j = 0; j < N; j ++)
                DP[i][j] = INF;
            
        for (int i = 0; i < N; i ++) {
            if (col[i] == 'R')
                DP[(1 << i)][i] = 0.0;
            if (col[i] == 'G' && cnt['R'] == 0)
                DP[(1 << i)][i] = 0.0;
            if (col[i] == 'B' && cnt['R'] == 0 && cnt['G'] == 0)
                DP[(1 << i)][i] = 0.0;
        }
        
        for (int i = 0; i < (1 << (N)); i ++) {
            for (int j = 0; j < N; j ++) {
                char c_col;
                
                int R = 0;
                int G = 0;
                int B = 0;
                
                for (int k = 0; k < N; k ++) {
                    if (i & (1 << k)) {
                        if (col[k] == 'R')
                            R ++;
                        if (col[k] == 'G')
                            G ++;
                        if (col[k] == 'B')
                            B ++;
                    }
                }
                
                if (R < cnt['R'])
                    c_col = 'R';
                else if (R == cnt['R'] && G < cnt['G'])
                    c_col = 'G';
                else if (R == cnt['R'] && G == cnt['G'] && B < cnt['B'])
                    c_col = 'B';
                
                for (int k = 0; k < N; k ++) {
                    if (j == k) { continue; }
                    
                    if (!(i & (1 << k)) && col[k] == c_col)
                        DP[i | (1 << k)][k] = min(DP[i | (1 << k)][k], DP[i][j] + q_dist(abs(k - j)));    
                }
            }
        }
        
        long double ans = INF;
        
        for (int i = 0; i < N; i ++)
            ans = min(ans, DP[(1 << (N)) - 1][i]);
        
        ans = round(ans * 10000.0) / 10000.0; 
        fout << "Scenario #" << (ii + 1) << ": " << ans << endl;
    
        cnt['R'] = 0;
        cnt['G'] = 0;
        cnt['B'] = 0;
    }
}