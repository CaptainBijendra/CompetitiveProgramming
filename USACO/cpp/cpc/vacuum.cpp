#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<pair<long long, string> > sol;

long long N;

int main() {
    cin >> N;
    
    string str;
    for (long long i = 0; i < N; i ++) {
        cin >> str;
        
        long long s = 0;
        
        for (long long j = 0; j < str.size(); j ++) {
            if (str[j] == 's')
                s ++;
        }
        
        sol.push_back(make_pair(((s * -1000000ll) / ((int)str.size())), str));
    }
    
    sort(sol.begin(), sol.end());
    
    long long ans = 0;
    long long s = 0;
    
    for (long long i = 0; i < sol.size(); i ++) {
        for (long long j = 0; j < sol[i].second.size(); j ++) {
            if (sol[i].second[j] == 's')
                s ++;
            else
                ans += s;
        }
    }
    
    cout << ans << endl;
    return (0);
}