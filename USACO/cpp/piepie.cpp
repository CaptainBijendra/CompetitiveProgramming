#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin ("piepie.in");
    ofstream fout ("piepie.out");
    
    fin >> N >> D;
    
    for (int i = 0; i < N; i ++) {
        fin >> cows[i].first >> cows[i].second;
    }
}