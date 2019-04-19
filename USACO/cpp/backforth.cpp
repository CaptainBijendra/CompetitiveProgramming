#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ar1, ar2;

int pos[10000005];
int N;

int t(int a, int b, int c, int d) {
    int st = 1000;
    
    vector<int> tar1 = ar1;
    vector<int> tar2 = ar2;
    
    st -= tar1[a];
    tar2.push_back(tar1[a]);
    tar1.erase(tar1.begin() + a);
    
    st += tar2[b];
    tar1.push_back(tar2[b]);
    tar2.erase(tar2.begin() + b);
    
    st -= tar1[c];   
    tar2.push_back(tar1[c]);
    tar1.erase(tar1.begin() + c);
    
    st += tar2[d];
    tar1.push_back(tar2[d]);
    tar2.erase(tar2.begin() + d);
    
    return (st);
}

int main() {
    ifstream fin ("backforth.in");
    ofstream fout ("backforth.out");
    
    N = 10;
    
    int a;
    for (int i = 0; i < N; i ++) {
        fin >> a;
        ar1.push_back(a);
    }
    
    for (int i = 0; i < N; i ++) {
        fin >> a;
        ar2.push_back(a);
    }
    
    int ans = 1000;
    
    sort(ar1.begin(), ar1.end());
    sort(ar2.begin(), ar2.end());
    
    for (int i = 0; i < N; i ++) 
        for (int j = 0; j < N + 1; j ++) 
            for (int k = 0; k < N; k ++) 
                for (int l = 0; l < N + 1; l ++)
                    pos[t(i, j, k, l)] ++;
    
    int fans = 0;
    
    for (int i = 0; i < 10000005; i ++) {
        if (pos[i] > 0) {
            fans ++;
        }
    }
    
    fout << fans << endl;
    return (0);    
}
