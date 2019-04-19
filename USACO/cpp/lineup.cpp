#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <set>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

multiset<int> big;

set<int> colors;
map<int, int> cnt;

int ar[MAX_N];
int N, K;

bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
   return a.second<b.second;
}

int main() {
    ifstream fin ("lineup.in");
    ofstream fout ("lineup.out");
    
    fin >> N >> K;
    
    for (int i = 0; i < N; i ++)
        fin >> ar[i];
    
    int lft = 0;
    int ans = 0;
    
    for (int i = 0; i < N; i ++) {
        if (cnt[ar[i]] == 0) {
            big.erase(cnt[ar[i]]);
            cnt[ar[i]] ++;
            big.insert(cnt[ar[i]]);
            
            colors.insert(ar[i]);
        }
        
        else {
            big.erase(cnt[ar[i]]);
            cnt[ar[i]] ++;
            big.insert(cnt[ar[i]]);
        }

        while (colors.size() == (K + 2)) {
            big.erase(cnt[ar[lft]]);
            cnt[ar[lft]] --;
            big.insert(cnt[ar[lft]]);

            if (cnt[ar[lft]] == 0)
                colors.erase(ar[lft]);
            
            lft ++;
        }

        ans = max(ans, *big.rbegin());
    }
    
    fout << ans << endl;
    return (0);
}