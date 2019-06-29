#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 505
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

int main() {
    ifstream fin ("fcount.in");
    ofstream fout ("fcount.out");
    
    fin >> N;
    N ++;
    
    long long s = 0ll;
    
    for (int i = 0; i < N; i ++) {
        fin >> ar[i];
        s += ar[i];
    }
    
    vector<int> v;
    
    for (int i = 0; i < N; i ++) {
        if ((s - ar[i]) % 2 == 1)
            continue;
        
        priority_queue<int> pq;
        
        for (int j = 0; j < N; j ++) {
            if (j == i || ar[j] == 0)
                continue;
            
            pq.push(ar[j]);
        }
        
        bool flag = true;
        
        while (!pq.empty()) {
            int cur = pq.top();
            pq.pop();
            
            vector<int> recover;
            
            for (int j = 0; j < cur; j ++) {
                if (pq.empty()) {
                    flag = false;
                    break;
                }
                
                int nxt = pq.top();
                pq.pop();
                
                if (nxt - 1 > 0)
                    recover.push_back(nxt - 1);
            }
            
            if (!flag)
                break;
                
            for (int j = 0; j < recover.size(); j ++)
                pq.push(recover[j]);
        }
        
        if (flag)
            v.push_back(i);
    }
    
    fout << v.size() << endl;
    for (int i = 0; i < v.size(); i ++)
        fout << v[i] + 1 << endl;
        
    return (0);
}