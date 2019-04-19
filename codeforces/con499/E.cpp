#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_N 100005
#define MOD 1000000009
#define f first
#define s second

using namespace std;

bool vis[MAX_N];

queue<int> q;
vector<int> ans;

string conv;

int ar[MAX_N];
int N, K;

string convertFromBaseTo(int convertFrom, int convertTo) {
    string answer;

    while (convertFrom != 0){
        int digit = convertFrom % convertTo;

        char stringDigit;
        if (digit < 10) {
            stringDigit = '0' + digit;
        } else {
            stringDigit = digit - 10 + 'A';
        }

        answer.insert(answer.begin(), stringDigit);
        convertFrom /= convertTo;                
    }

    return answer;
}

int main() {
    cin >> N >> K;
    
    for (int i = 0; i < N; i ++) {
        int a;
        cin >> a;
        
        conv = convertFromBaseTo(a, K);
        
        if (!vis[(int)(conv[conv.size() - 1] - '0')]) {
            ans.push_back((int)(conv[conv.size() - 1] - '0'));
            q.push((int)(conv[conv.size() - 1] - '0'));
        }
        
        vis[conv[conv.size() - 1] - '0'] = true;
    }
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int i = 0; i < ans.size(); i ++) {
            if (!vis[(ans[i] + cur) % K]) {
                ans.push_back((ans[i] + cur) % K);
                vis[(ans[i] + cur) % K] = true;
            }
        }
    }
    
    cout << ans.size() << endl;
    sort (ans.begin(), ans.end());
    
    for (int i = 0; i < ans.size(); i ++) {
        if (i == 0) { cout << ans[i]; }
        else { cout << " " << ans[i]; }
    }
    
    cout << endl;
    return (0);
}