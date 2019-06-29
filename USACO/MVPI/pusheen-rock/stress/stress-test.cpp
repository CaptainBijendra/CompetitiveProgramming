#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

long long  rock[MAX_N];
int N, X;

int main() {
    string str;
    
    cout << "File input" << endl;
    cin >> str;
    
    string str1 = str + ".in"; 
    string str2 = str + ".out";
    
    ifstream fin (str1.c_str());
    ofstream fout (str2.c_str());
    
    fin >> N >> X;
    
    for (int i = 0; i < N; i ++)
        fin >> rock[i];
    
    long long pairs = 0ll;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (i == j) { continue; }
            int numDigits = floor(log10(rock[j]) + 1); //Number of digits in the number rock[j]
            
            long long resultingNumber = (((((long long)pow(10.0, numDigits * 1.0)) % K) * (rock[i] % K)) % K) + rock[j];
            
            if (resultingNumber % K == 0)
                pairs ++;
        }
    }
    
    fout << pairs << endl;
    return (0);
}