#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <math.h>

#define MAX_N 500005
#define f first
#define s second

using namespace std;

vector<int> con[MAX_N];
vector<int> disc(MAX_N);
vector<int> tmp(MAX_N);

int rem[MAX_N];
int N, M;

bool cmp(int a, int b) {
    return (tmp[b] < tmp[a]);
}

bool pos(int days) {
    for (int i = 1; i <= N; i ++) {
        tmp[i] = rem[i];
        disc[i] = 0;
    }
    
    for (int i = 1; i <= days; i ++) 
        for (int j = 0; j < con[i].size(); j ++)
            disc[con[i][j]] = max(disc[con[i][j]], i);
    
    int num = 0;
    
    for (int i = 1; i <= days; i ++) {
        num ++;
        
        vector<int> sortd;
        for (int j = 0; j < con[i].size(); j ++) { 
            if (disc[con[i][j]] != i)
                continue;
            
            sortd.push_back(con[i][j]);
        }
        
        for (int j = 0; j < sortd.size(); j ++) {
            if (tmp[sortd[j]] >= num) {
                tmp[sortd[j]] -= num;
                num = 0;
            } else {
                num -= tmp[sortd[j]];
                tmp[sortd[j]] = 0;
            }
        }
    }
    
    int result = 0;
    for (int i = 1; i <= N; i ++)
        result += tmp[i];
    
    return (result * 2 <= num);
}

int main() {
    cin >> N >> M;
    
    for (int i = 1; i <= N; i ++)
        cin >> rem[i];
    
    int a, b;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        con[a].push_back(b);
    }
    
    int low = 1;
    int hi = MAX_N;
    
    while (low < hi) {
        int mid = (low + hi) / 2;
        
        if (pos(mid))
            hi = mid;
        else
            low = mid + 1;
    }
    
    cout << low << endl;
    return (0);
}