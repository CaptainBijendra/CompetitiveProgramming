#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> stck;

int ar[MAX_N], lf[MAX_N], r[MAX_N];
int N;

int main() {
    ifstream fin ("art2.in");
    ofstream fout ("art2.out");
    
    fin >> N;
    
    for (int i = 0; i < MAX_N; i ++) {
        lf[i] = MAX_N;
        r[i] = 0;
    }
    
    for (int i = 0; i < N; i ++) {
        fin >> ar[i];
        lf[ar[i]] = min(lf[ar[i]], i);
        r[ar[i]] = max(r[ar[i]], i);
    }
    
    int lvl = 0;
    int ans = 0;

    for (int i = 0; i < N; i ++) {
        if (ar[i] == 0 || (i != lf[ar[i]] && i != r[ar[i]]))
            continue;
        
        if (i == lf[ar[i]])
            lvl ++;
        
        stck.push_back(ar[i]);
        ans = max(ans, lvl);
        
        if (lf[ar[i]] == r[ar[i]]) {
            lvl --;
            stck.pop_back();
        }
        
        if (stck[stck.size() - 1] == stck[stck.size() - 2]) {
            stck.pop_back();
            stck.pop_back();
            lvl --;
            
            continue;
        }
    }
    
    int mx = 0;
    
    for (int i = 1; i < N; i ++) {
        if (r[ar[i]] > r[ar[mx]]) {
            mx = i;
            continue;
        }
        
        if (lf[ar[i]] < lf[ar[mx]]) {
            ans = -1;
            break;
        }
    }
    
    fout << ans << endl;
    return (0);    
}