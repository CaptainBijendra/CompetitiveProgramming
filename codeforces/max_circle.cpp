#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int cnt[MAX_N], ar[MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        cnt[ar[i]] ++;
    }
    
    vector<int> ans;
    
    int start = -1;
    int sum = 0, big = 0;
    
    for (int i = 1; i < MAX_N; i ++) {
        if (cnt[i] == 1 && start != -1) {
            sum = 0;
            
            for (int j = start; j <= i; j ++)
                sum += cnt[j];
            
            if (sum > big) {
                big = sum;
                ans.clear();
                
                for (int j = start; j <= i; j ++)
                    ans.push_back(j);
            }
            
            start = i;
        } 
        
        if (cnt[i] == 0) {
            if (start != -1) {
                sum = 0;
                
                for (int j = start; j < i; j ++)
                    sum += cnt[j];
                
                if (sum > big) {
                    big = sum;
                    ans.clear();
                    
                    for (int j = start; j < i; j ++)
                        ans.push_back(j);
                }
            }

            start = -1;
        }
        
        if (cnt[i] >= 1 && start == -1)
            start = i;
    }
    
    if (ans.size() == 1) {
        cout << big << endl;
        cout << ans[0];
    
        for (int i = 1; i < cnt[ans[0]]; i ++)
            cout << " " << ans[0];
        
        cout << endl;
        return (0);
    }
    
    cout << big << endl;
    cout << ans[0];
    
    for (int i = 1; i < cnt[ans[0]]; i ++)
        cout << " " << ans[0];

    for (int i = 1; i < ans.size() - 1; i ++) {
        for (int j = 0; j < cnt[ans[i]] - 1; j ++)
            cout << " " << ans[i];
    }
    
    for (int i = 0; i < cnt[ans[ans.size() - 1]]; i ++)
        cout << " " << ans[ans.size() - 1];

    for (int i = ans.size() - 2; i >= 1; i --)
        cout << " " << ans[i];
    
    cout << endl; 
    return (0);
}