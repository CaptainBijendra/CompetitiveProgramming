#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAX_N 105

using namespace std;

vector<int> con[MAX_N];

int N, M, A, B;

int main() {
    ifstream fin ("telecow.in");
    ofstream fout ("telecow.out");
    
    fin >> N >> M >> A >> B;
    
    for (int i = 0; i < M; i ++) {
        fin >> a >> b;
        
        con[a - 1].push_back(b - 1);
        con[b - 1].push_back(a - 1);
    }
}