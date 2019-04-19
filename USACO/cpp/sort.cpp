#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
ii ar[MAX_N];

int N;

int main() {
    ifstream fin ("sort.in");
    ofstream fout ("sort.out");
    
    fin >> N;
    
    for (int i = 0; i < N; i ++) {
        fin >> ar[i].f;
        ar[i].s = i;
    }

    sort(ar, ar + N);
    
    if (N % 2 == 0) {
        fout << max((abs(ar[N / 2].s - (N / 2)) * 2), abs(ar[N / 2 + 1].s - (N / 2)) * 2) << endl;
        return (0);
    }
    
    fout << (abs(ar[N / 2].s - (N / 2)) * 2) << endl;
    return (0);
}