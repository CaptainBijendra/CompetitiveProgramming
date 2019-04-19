#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string pwr;
int T, D;

int pos(int swps) {
    int ch = 1;
    int sh = 0;
    
    for (int i = 0; i < pwr.size(); i ++) {
        if (pwr[i] == 'C') { ch *= 2; }
        else { sh ++; }
    }
    
    for (int i = 0; i < )
    
    return (false);
}

int main() {
    ifstream fin ("save.in");
    ofstream fout ("save.out");
    
    fin >> T;
    
    for (int i = 0; i < T; i ++) {
        fin >> D >> pwr;
        
        int low = 0, hi = 1000000009;
        int mid;
        
        for (int j = 0; j < 1000; j ++) {
            
        }
    }
}