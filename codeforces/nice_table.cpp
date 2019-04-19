#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <string.h>
#include <math.h>

#define MAX_N 150005
#define f first
#define s second

using namespace std;

vector<string> ar;

unordered_map<int, char> tmp[MAX_N];
unordered_map<int, char> ans[MAX_N];

int N, M, small, flip, flip_ans;

void solve2(string a, string b) {
    int cost = 0;
        
    for (int j = 0; j < M; j ++) {
        if (j % 2 == 0) {
            tmp[0][j] = a[0];
            tmp[1][j] = b[0];
        }
        
        else {
            tmp[0][j] = a[1];
            tmp[1][j] = b[1];
        }
        
        cost += (tmp[0][j] != ar[0][j]) + (tmp[1][j] != ar[1][j]);
    }
    
    for (int i = 2; i < N; i ++) {
        char F, S;
        char ext;
    
        int cost1 = 0, cost2 = 0;
        
        if (i % 2 == 0) {
            F = a[0];
            S = a[1];
        }
        
        else {
            F = b[0];
            S = b[1];
        }
        
        for (int j = 0; j < M; j ++) {
            if (j % 2 == 0)
                ext = F;
            else
                ext = S;
            
            cost1 += (ext != ar[i][j]);
        }
        
        ext = S;
        S = F;
        F = ext;
        
        for (int j = 0; j < M; j ++) {
            if (j % 2 == 0)
                ext = F;
            else
                ext = S;
            
            cost2 += (ext != ar[i][j]);
        }
        
        if (cost1 < cost2) {
            cost += cost1;
            
            ext = S;
            S = F;
            F = ext;
            
            for (int j = 0; j < M; j ++) {
                if (j % 2 == 0)
                    tmp[i][j] = F;
                else
                    tmp[i][j] = S;
            }
        }
        
        else {
            cost += cost2;
            
            for (int j = 0; j < M; j ++) {
                if (j % 2 == 0)
                    tmp[i][j] = F;
                else
                    tmp[i][j] = S;
            }
        }
    }
    
    if (small > cost) {
        small = cost;
        
        if (flip)
            flip_ans = 1;
        
        for (int i = 0; i < N; i ++)
            for (int j = 0; j < M; j ++)
                ans[i][j] = tmp[i][j];
    }
}

void solve(string a, string b) {
	solve2(a, b);
	solve2(b, a);
}

int main() {        
    cin >> N >> M;
    
    string str;
    for (int i = 0; i < N; i ++) {
        cin >> str;
        ar.push_back(str);
    }
    
    small = MAX_N * 2;
    flip = 0;
    
    solve("AG", "CT"); solve("AG", "TC");
    solve("GA", "CT"); solve("GA", "TC");
    
    solve("AC", "GT"); solve("AC", "TG");
    solve("CA", "GT"); solve("CA", "TG");

    solve("AT", "GC"); solve("AT", "CG");
    solve("TA", "GC"); solve("TA", "CG");

    vector<string> tmp2;

    for (int i = 0; i < M; i ++) {
        string nw = "";
        
        for (int j = 0; j < N; j ++) 
            nw += ar[j][i];
        
        tmp2.push_back(nw);
    }
    
    ar.clear();
    
    int tmp3 = M;
    M = N;
    N = tmp3;

    ar = tmp2;
    flip = 1;
    flip_ans = 0;
    
    for (int i = 0; i < MAX_N; i ++) 
        tmp[i].clear();
    
    solve("AG", "CT"); solve("AG", "TC");
    solve("GA", "CT"); solve("GA", "TC");
    
    solve("AC", "GT"); solve("AC", "TG");
    solve("CA", "GT"); solve("CA", "TG");

    solve("AT", "GC"); solve("AT", "CG");
    solve("TA", "GC"); solve("TA", "CG");
    
    if (flip_ans) {
        for (int i = 0; i < M; i ++) {
            for (int j = 0; j < N; j ++) {
                cout << ans[j][i];
            }
        
            cout << endl;
        }
		
        return (0);
    }
    
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            cout << ans[i][j];
        }
        
        cout << endl;
    }
    
    return (0);
}