#include <iostream>
#include <fstream>

#define MAX_N 100005

using namespace std;

int ar[MAX_N];
int C, N;

int main() {
    ifstream fin ("ppairing.in");
    ofstream fout ("ppairing.out");
    
    fin >> C >> N;
    for (int i = 0; i < N; i ++) { fin >> ar[i]; }

    int right = N - 1;

    for (int i = 0; i < N; i ++) {
        if (ar[right] >= ar[i]) {
            for (int j = 0; j < ar[i]; j ++) 
            { cout << (i + 1) << " " << (right + 1) << endl; }
    
            ar[right] -= ar[i];
            ar[i] = 0;
        }
        
        else {
            for (int j = 0; j < ar[right]; j ++) 
            { cout << (right + 1) << " " << (i + 1) << endl; }
        
            ar[i] -= ar[right];
            ar[right --] = 0;
        }
    }   

    return (0);
}