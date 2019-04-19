#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N], cmp[MAX_N], mp[30];
int N, K, S;

int main() {
    cin >> N >> K >> S;

    for (int i = 0; i < N; i ++) 
        cin >> ar[i];
        
    for (int i = 0; i < K; i ++)
        cin >> cmp[i];
        
    int cnter = 0;
    int ind = MAX_N;
    
    vector<int> sol;
    
    for (int i = 0; i < N; i ++) {
        vector<int> a;
        
        for (int j = 0; j < K; j ++)
            a.push_back(ar[i + j]);
        
        sort(a.begin(), a.end());
        
        int cnt = 0;
        bool flag = true;
        
        for (int j = 0; j < K; j ++) {
            cnt ++;
    
            if (j > 0 && a[j] == a[j - 1]) 
                cnt --;
                
            mp[a[j]] = cnt;
        }
        
        for (int j = 0; j < K; j ++) {
            if (mp[ar[i + j]] == cmp[j])
                continue;
            
            flag = false;
            break;
        }
        
        if (flag) { 
            cnter ++;
            sol.push_back(i + 1);
        }
        
        a.clear();
    }

    cout << cnter << endl;
    
    for (int i = 0; i < sol.size(); i ++)
        cout << sol[i] << endl;

    return (0);
}