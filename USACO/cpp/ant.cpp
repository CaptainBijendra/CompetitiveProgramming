#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> pii;

int par[MAX_N], sz[MAX_N], ans[MAX_N];
int T, N, M;

void init(int size) {
    for (int i = 0; i < size; i ++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    while (x != par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    }

    return (x);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (sz[x] > sz[y]) {
        par[y] = x;
        sz[x] += sz[y];
    }

    else {
        par[x] = y;
        sz[y] += sz[x];
    }
}

int main() {
    ifstream fin ("ant.in");
    ofstream fout ("ant.out");
    
    fin >> T;
    
    for (int ii = 0; ii < T; ii ++) {
        fout << "Colony #" << (ii + 1) << ":" << endl;
        
        int N, M;

        fin >> N;
        init(MAX_N);
        
        vector<int> con[MAX_N];
        vector<pii> query;
        
        int a, b, c;
        for (int i = 0; i < N - 1; i ++) {
            fin >> a >> b;
            con[a - 1].push_back(b - 1);
            con[b - 1].push_back(a - 1);
        }
        
        fin >> M;
        
        for (int i = 0; i < M; i ++) {
            fin >> a >> b >> c;
            query.push_back(pii(a, make_pair(b - 1, c - 1)));
            
            if (a == 2)
                continue;
                
            for (int j = 0; j < con[b - 1].size(); j ++)
                if (con[b - 1][j] == c - 1)
                    con[b - 1].erase(con[b - 1].begin() + j);
                    
            for (int j = 0; j < con[c - 1].size(); j ++)
                if (con[c - 1][j] == b - 1)
                    con[c - 1].erase(con[c - 1].begin() + j);
        }
        
        reverse(query.begin(), query.end());
         
        for (int i = 0; i < MAX_N; i ++) 
            for (int j = 0; j < con[i].size(); j ++) 
                if (find(con[i][j]) != find(i)) 
                    merge(i, con[i][j]);
        
        int cnt = 0;

        for (int i = 0; i < query.size(); i ++) {
            if (query[i].f == 1) {
                if (find(query[i].s.f) != find(query[i].s.s))
                    merge(find(query[i].s.f), find(query[i].s.s));
            }
            
            else {
                ans[cnt] = (find(query[i].s.f) == find(query[i].s.s));
                cnt ++;
            }
        }
        
        cnt --;
        reverse(query.begin(), query.end());
        
        for (int i = 0; i < query.size(); i ++) {
            if (query[i].f == 1) 
                fout << "Tunnel from " << (query[i].s.f + 1) << " to " << (query[i].s.s + 1) << " collapsed!" << endl;
            else {
                if (ans[cnt])
                    fout << "Room " << (query[i].s.f + 1) << " can reach " << (query[i].s.s + 1) << endl;
                else
                    fout << "Room " << (query[i].s.f + 1) << " cannot reach " << (query[i].s.s + 1) << endl;

                cnt --;
            }
        }
        
        fout << endl;
    }
    
    return (0);
}