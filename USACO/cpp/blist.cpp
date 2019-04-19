#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int ar[100005];
int N;

int main() {
    ifstream fin ("blist.in");
    ofstream fout ("blist.out");
    
    fin >> N;
    
    int a, b, c;
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        fin >> a >> b >> c;
        
        for (int j = a; j <= b; j ++) {
            ar[j] += c;
            ans = max(ans, ar[j]);
        }
    }
    
    fout << ans << endl;
}