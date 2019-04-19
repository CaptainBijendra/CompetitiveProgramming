#include <iostream>
#include <fstream>

#define MAX_N 1200

using namespace std;

struct letter 
{ bool bit[20][20]; };

letter cmp[28];

letter reset() {
    letter a;
    
    for (int i = 0; i < 20; i ++) {
        for (int j = 0; j < 20; j ++) { a.bit[i][j] = 0; }
    }
    
    return (a);
}

int main() {
    ifstream read("font.in");
    
    string ln;
    letter tmp;
    
    for (int i = 0; i < 20; i ++) { cmp[i] = reset(); } read >> ln;
    for (int i = 0; i < 540; i ++) {
        read >> ln;
    
        for (int j = 0; j < 20; j ++)
        { cmp[(i / 20)].bit[(i % 20)][j] = (ln[j] == '1');  }
        
    }
    
    ifstream fin ("charrec.in");
    ofstream fout ("charrec.out");
    
    for (int i = 0; i < 28; i ++) {
        for (int j = 0; j < 20; j ++) {
            for (int k = 0; k < 20; k ++) {
                cout << cmp[i].bit[i][j];
            }
            
            cout << endl;
        }
    }
    
    return (0);
}