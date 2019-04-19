/*
ID: akommul1
LANG: C++
PROB: calfflac
*/

#include <iostream>
#include <fstream>
#include <vector>

#define MAX_N 2005

using namespace std;

string org, chunk;

vector<char> ar;

int DP[MAX_N][MAX_N];
int max_len, max_r, max_l;

bool valid(char a) {
    if ((int)(a) >= 65 && (int)(a) <= 90) { return (true); }
    if ((int)(a) >= 97 && (int)(a) <= 122) { return (true); }

    return (false);
}

int solve(int left, int right) {
    if (left == right) { return (1); }
    if (left + 1 == right) { return (ar[left] == ar[right]); }
    if (DP[left][right] > 0) { return (DP[left][right]); }

    if (ar[left] == ar[right]) { DP[left][right] = (2 + solve(left + 1, right - 1)); }
    else { solve(left + 1, right); solve(left, right - 1); }

    if (max_len < DP[left][right]) { max_len = DP[left][right]; max_l = left; max_r = right; }
    if (max_len == DP[left][right]) { 
        if (max_l > left) { max_l = left; max_r = right; }
    }

    return (DP[left][right]);
}

int main() {
    ifstream fin ("calfflac.in");
    ofstream fout ("calfflac.out");

    while (fin >> chunk) { org += chunk + " "; }
    
    for (int i = 0; i < org.size(); i ++) {
        if (valid(org[i])) 
        { ar.push_back(((int)(org[i]) >= 97 ? org[i] : (char)(org[i] + 32))); }
    }
    
    max_len = 0;
    max_r = -1; max_l = -1;

    solve(0, ar.size());
    
    bool ch1 = false, ch2 = false;
    int inflate = 0;

    for (int i = 0; i < org.size(); i ++) {
        if (!valid(org[i])) { inflate ++; }         
    
        if (max_l + inflate == i && !ch1) { max_l = i; ch1 = true; }
        if (max_r + inflate == i && !ch2) { max_r = i; ch2 = true; }
    }
    
    fout << max_len << endl;

    for (int i = max_l; i <= max_r; i ++) { fout << org[i]; }
    fout << endl; 
    
    return (0);
}
