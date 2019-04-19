#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>

#define MAX_N 255
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

string str;

char ar[MAX_N][MAX_N];

int cnt[26][MAX_N][MAX_N];
int N, M;

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        cin >> str;
        
        for (int j = 0; j < M; j ++)
            ar[i][j] = str[j];
    }
    
    for (int i = 0; i < N; i ++) {
        cnt[ar[i][0] - 'a'][i][0] = 1;
        
        for (int j = 1; j < M; j ++) {
            for (int k = 0; k < 26; k ++) {
                if (ar[i][j] - 'a' == k)
                    cnt[k][i][j] = cnt[k][i][j - 1] + 1;
                else
                    cnt[k][i][j] = cnt[k][i][j - 1];
            }
        }
    }
    
    long long ans = 0ll;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            for (int k = i; k < N; k ++) {
                for (int l = j; l < M; l ++) {
                    if (i == k && j == l) {
                        ans ++;
                        continue;
                    }   
                    
                    bool pos = true;
                    bool odd = false;
                    
                    for (int r = i; r <= k; r ++) { 
                        odd = false;
                        
                        if ((l - j + 1) % 2 == 0) 
                            odd = true;
                            
                        for (int a = 0; a < 26; a ++) {
                            if ((cnt[a][r][l] - (j == 0 ? 0 : cnt[a][r][j - 1])) % 2 == 0)
                                continue;
                            else {
                                if (!odd)
                                    odd = true;
                                else {
                                    pos = false;
                                    break;
                                }
                            }
                        }
                        
                        if (!pos)
                            break;
                    }
                        
                    int cnter = 0;
                    for (int r = i; r <= k - cnter; r ++) {
                        for (int a = 0; a < 26; a ++) {
                            if ((cnt[a][r][l] - (j == 0 ? 0 : cnt[a][r][j - 1])) != cnt[a][k - cnter][l] - (j == 0 ? 0 : cnt[a][k - cnter][j - 1])) {
                                pos = false;
                                break;
                            }
                        }
                        
                        if (!pos)
                            break;
                            
                        cnter ++;
                    }
                    
//                    if (pos)
//                        cout << i << " " << j << " " << k << " " << l << " " << endl;
                    
                    ans += pos;
                }
            }
        }
    }
    
    cout << ans << endl;
    return (0);
}