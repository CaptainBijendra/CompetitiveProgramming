#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

int x[MAX_N], y[MAX_N], xpre[MAX_N], ypre[MAX_N], cx[MAX_N], cy[MAX_N], cxpre[MAX_N], cypre[MAX_N];
int nx[MAX_N], ny[MAX_N], nxpre[MAX_N], nypre[MAX_N];
int N, K;

int main() {
    ifstream fin ("lazy.in");
    ofstream fout ("lazy.out");
    
    fin >> N >> K;

    int a, b, c;
    for (int i = 0; i < N; i ++) {
        fin >> a >> b >> c;
        x[b] += a; cx[b] += b;
        y[c] += a; cy[c] += c;
        
        nx[b] ++; 
        ny[c] ++;
    }
    
    for (int i = 0; i <= 1000000; i ++) {
        xpre[i] = (i == 0 ? 0 : xpre[i - 1]) + x[i];
        cxpre[i] = (i == 0 ? 0 : cxpre[i - 1]) + cx[i];
        nxpre[i] = (i == 0 ? 0 : nxpre[i - 1]) + nx[i];
    }
    
    for (int i = 0; i <= 1000000; i ++) {
        ypre[i] = (i == 0 ? 0 : ypre[i - 1]) + y[i];
        cypre[i] = (i == 0 ? 0 : cypre[i - 1]) + cy[i];
        nypre[i] = (i == 0 ? 0 : nypre[i - 1]) + ny[i];
    }
    
    int ans = 0;
    int distance = 0;
    int loc_x = -1;
    
    for (int i = 0; i <= 1000000; i ++) {
        int dfor = cxpre[i + K] - cxpre[i];
        int dback = cxpre[i] - cxpre[max(0, i - K)] + cx[max(0, i - K)];
    
        int cfor = xpre[i + K] - xpre[i];
        int cback = xpre[i] - xpre[max(0, i - K)] + x[max(0, i - K)];
        
        int nfor = nxpre[i + K] - nxpre[i];
        int nback = nxpre[i] - nxpre[max(0, i - K)] + nx[max(0, i - K)];
        
        dfor  = dfor - nfor * i;
        dback = nback * i - dback;
        
        if (cfor + cback > ans) {
            ans = cfor + cback;
            distance = dfor + dback;
        } else if (cfor + cback == ans) {
            if (dfor + dback <= distance) {
                distance = dfor + dback;
                loc_x = i;
            }
        }
    }
    
    cout << loc_x << endl;
    
    return (0);
}