#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define MAX_N 25
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<int> val[MAX_N];

int ans[MAX_N][MAX_N];

int ar[MAX_N * MAX_N], cnt[1005];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N * N; i ++) {
        cin >> ar[i];
        cnt[ar[i]] ++;
    }
    
    sort(ar, ar + N * N);
    
    if (N % 2 == 0) {
        for (int i = 0; i < 1005; i ++)
            if (cnt[i] != 0 && cnt[i] % 4 != 0) {
                cout << "NO" << endl;
                return (0);
            }
        
        int ind = 0;
        
        for (int i = 0; i < N / 2; i ++) {
            for (int j = 0; j < N / 2; j ++) {
                ans[i][j] = ar[ind];
                ans[N - i - 1][j] = ar[ind + 1];
                ans[i][N - j - 1] = ar[ind + 2];
                ans[N - i - 1][N - j - 1] = ar[ind + 3];
                
                ind += 4;
            }
        }
    }
    
    else {
        for (int i = 0; i < 1005; i ++) {
            if (cnt[i] == 0)
                continue;
            
            if (cnt[i] % 2 == 1) {
                cnt[i] --;
                val[1].push_back(i);
            }
            
            if (cnt[i] % 4 == 0) {
                for (int j = 0; j < cnt[i] / 4; j ++)
                    val[4].push_back(i);
            }
            
            else if (cnt[i] % 2 == 0) {
                val[2].push_back(i);
                cnt[i] -= 2;
                
                for (int j = 0; j < cnt[i] / 4; j ++)
                    val[4].push_back(i);
            }
        }
        
        if (val[4].size() < (N / 2) * (N / 2)) {
            cout << "NO" << endl;
            return (0);
        }
        
        if (val[1].size() != 1) {
            cout << "NO" << endl;
            return (0);
        }
        
        int ind = 0;
        
        for (int i = 0; i < N / 2; i ++) {
            for (int j = 0; j < N / 2; j ++) {
                ans[i][j] = val[4][ind];
                ans[N - i - 1][j] = val[4][ind];
                ans[i][N - j - 1] = val[4][ind];
                ans[N - i - 1][N - j - 1] = val[4][ind];
                
                ind ++;
            }
        }
        
        for (int i = ind; i < val[4].size(); i ++) {
            val[2].push_back(val[4][i]);
            val[2].push_back(val[4][i]);
        }

        if (val[2].size() != 2 * (N / 2)) {
            cout << "NO" << endl;
            return (0);
        }
        
        ind = 0;
        
        for (int i = 0; i < N / 2; i ++) {
            ans[N / 2][i] = val[2][ind];
            ans[N / 2][N - i - 1] = val[2][ind];
            
            ind ++;
        }
        
        for (int i = 0; i < N / 2; i ++) {
            ans[i][N / 2] = val[2][ind];
            ans[N - i - 1][N / 2] = val[2][ind];
        
            ind ++;
        }
        
        ans[N / 2][N / 2] = val[1][0];
    }
    
    cout << "YES" << endl;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++)
            cout << ans[i][j] << " ";
        
        cout << endl;
    }   
    
    return (0);
}