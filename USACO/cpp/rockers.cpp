#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 25
#define MAX_M 25
#define MAX_T 25

int disks[MAX_N];
int N, T, M;

using namespace std;

int main() {
    ifstream fin ("rockers.in");
    ofstream fout ("rockers.out");
    
    fin >> N >> T >> M;
    
    for (i = 0; i < N; i ++) { fin >> disks[i]; } 
}