#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 100005

using namespace std;

int ar[MAX_N];
int N;

int main() {
    ifstream fin ("cbarn.in");
    ofstream fout ("cbarn.out");
    
    fin >> N;
    for (int i = 0; i < N; i ++) { fin >> ar[i]; }

    int carry = 0;
    long long dist = 0; 

    for (int i = 0; i < N; i ++) {
        carry = max(0, carry + (ar[i] - 1));
    }

    for (int i = 0; ; i ++) {
        carry = max(0, carry + (ar[i] - 1));
        
        if (carry == 0) {
            rotate(ar, ar + i, ar + N);
            break;
        }
        
        i %= N;
    }

    carry = 0;
    for (int i = 0; i < N; i ++) {
        carry = max(0, carry + (ar[i] - 1));
        dist += (carry * carry);
    }
    
    fout << dist << endl;
    return (0);
}