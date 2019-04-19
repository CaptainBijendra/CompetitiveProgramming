#include <iostream>
#include <fstream>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
ii cow[MAX_N];

int vis[MAX_N];
int N;

int sq(int a) {
    return (a * a);
}

int dist(int a, int b) {
    return (sq(cow[a].f - cow[b].f) + sq(cow[a].s - cow[b].s));
}

void DFS (int ind, int rad) {
    vis[ind] = 1;
    
    for (int i = 0; i < N; i ++) 
        if (!vis[i] && dist(i, ind) <= rad)
            DFS (i, rad);
}

bool pos(int rad) {
    for (int i = 0; i < N; i ++)
        vis[i] = 0;
    
    DFS (0, rad);
    
    for (int i = 0; i < N; i ++)
        if (vis[i] == 0)
            return (false);
    
    return (true);    
}

int main() {
    ifstream fin ("moocast.in");
    ofstream fout ("moocast.out");
    
    fin >> N;
    
    for (int i = 0; i < N; i ++) 
        fin >> cow[i].f >> cow[i].s;

    int low = 0;
    int hi = 1250000001;
    
    while (low < hi) {
        int mid = (low + hi) / 2;
        
        if (pos(mid))
            hi = mid;
        else
            low = mid + 1;
    }
    
    fout << low << endl;
    return (0);
}