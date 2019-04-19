#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define eps 0.0001
#define MAX_N 305
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

ii point[MAX_N];

long long pre[MAX_N][MAX_N];
long long ans[MAX_N];

long long N;

bool eq(long long i, long long j) {
    return (point[i].f == point[j].f && point[i].s == point[j].s);
}

bool below(long long i, long long j, long long k, bool f) {
    if (point[j].f < point[i].f) {
        long long tmp = j;
        j = i;
        i = tmp;
    }
    
    if (!(point[k].f >= point[i].f && point[k].f <= point[j].f) && f)
        return (false);
    
    long double slope = (point[j].s * 1.0 - point[i].s * 1.0) / (point[j].f * 1.0 - point[i].f * 1.0);
    
    if ((point[k].s * 1.0 <= (point[k].f - point[j].f) * slope + point[j].s))
        return (true);
    else
        return (false);
}

int main() {
    ifstream fin ("triangles.in");
    ofstream fout ("triangles.out");
    
    fin >> N;
    
    for (long long i = 0; i < N; i ++)
        fin >> point[i].f >> point[i].s;
    
    for (long long i = 0; i < N; i ++) {
        for (long long j = i + 1; j < N; j ++) {
            for (long long k = j + 1; k < N; k ++)
                pre[i][j] += below(i, j, k, true);
            
            pre[j][i] = -1pre[i][j];
        }
    }
                
    for (long long i = 0; i < N; i ++) {
        for (long long j = i + 1; j < N; j ++) {
            for (long long k = j + 1; k < N; k ++) {
                long long cnt = 0;
                
                if (below(i, j, k, false))
                    cnt += pre[i][j] - below(i, j, k, true);
                else
                    cnt -= (pre[i][j] - below(i, j, k, true));
                
                if (below(i, k, j, false))
                    cnt += pre[i][k] - below(i, k, j, true);
                else
                    cnt -= (pre[i][k] - below(i, k, j, true));
                
                if (below(j, k, i, false))
                    cnt += pre[j][k] - below(j, k, i, true);
                else
                    cnt -= (pre[j][k] - below(j, k, i, true));
                
                if (cnt < 0)
                    cout << "HARRO!" << endl;
                
                ans[cnt] ++;
            }
        }
    }
    
    long long sum = 0;
    
    for (long long i = 0; i < N - 2; i ++) 
        fout << ans[i] << endl;
    
    return (0);
}