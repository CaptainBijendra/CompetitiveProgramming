#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> pii;

class SegTree {
    private:
        long long tree[4 * MAX_N][10];
        int lazy[4 * MAX_N][10];

    public:
        SegTree(int N) {

        }

        void propogate (int ind, bool eq) {
            if (lazy[ind][0]) {
                tree[ind][lazy[ind][0]] += (long long)(tree[ind][0] * lazy[ind][0]);
                tree[ind][0] = 0;
            }
            
            if (eq)
                lazy[ind][0] = 0;
            
            for (int i = 1; i <= 9; i ++) { //switch digit i to digit lazy[ind][i]
                if (lazy[ind][i]) {
                    tree[ind][lazy[ind][i]] += ((tree[ind][i] / i) * lazy[ind][i]);
                    tree[ind][i] = 0;
                }
                
                if (eq)
                    lazy[ind][i] = 0;
            }
        }        

        long long get_val(int l, int r, int l1, int r1, int ind) {
            if (l1 > r || r1 < l) { return (0); }
            if (l <= l1 && r1 <= r) { 
                long long sum = 0;

                for (int i = 1; i <= 9; i ++)
                    sum += tree[ind][i];
                
                return (sum);
            }

            for (int i = 0; i <= 9; i ++) {
                if (lazy[ind][i] != 0) {
                    if (!lazy[2 * ind][i])
                        lazy[2 * ind][i] = lazy[ind][i];
                    
                    if (!lazy[2 * ind + 1][i])
                        lazy[2 * ind + 1][i] = lazy[ind][i];
                    
                    lazy[ind][i] = 0;
                }
            }
            
            propogate(2 * ind, (l1 == (r1 + l1) / 2));
            propogate(2 * ind + 1, ((r1 + l1) / 2 + 1 == r1));
            
            long long leftS = get_val(l, r, l1, (r1 + l1) / 2, (2 * ind));
            long long rightS = get_val(l, r, (r1 + l1) / 2 + 1, r1, 2 * ind + 1);

            return (leftS + rightS);
        }

        long long query(int a, int b)
        { return (get_val(a, b, 0, MAX_N, 1)); }

        void change_val(int l, int r, int prev, int cur, int ind, int a, int b) {
            if (l > b || r < a) { return; }
            if (a <= l && r <= b) {
                if (cur == -1) {
                    int num = 1;
                    int dig;
                    
                    while (prev != 0) {
                        dig = prev % 10;
                        
                        if (dig == 0)
                            tree[ind][0] += num;
                        else
                            tree[ind][dig] += num * dig;
                    
                        prev /= 10; 
                        num *= 10;
                    }
                }
                
                else {
                    if (!lazy[ind][prev])
                        lazy[ind][prev] = cur;
                        
                    propogate(ind, l == r);
                }
            
                return;
            }

            for (int i = 0; i <= 9; i ++) {
                if (lazy[ind][i] != 0) {
                    if (!lazy[2 * ind][i])
                        lazy[2 * ind][i] = lazy[ind][i];
                    
                    if (!lazy[2 * ind + 1][i])
                        lazy[2 * ind + 1][i] = lazy[ind][i];
                    
                    lazy[ind][i] = 0;
                }
            }
            
            propogate(2 * ind, (l == (r + l) / 2));
            propogate(2 * ind + 1, ((r + l) / 2 + 1 == r));
            
            change_val(l, (r + l) / 2, prev, cur, 2 * ind, a, b);
            change_val((r + l) / 2 + 1, r, prev, cur, 2 * ind + 1, a, b);
            
            for (int i = 0; i <= 9; i ++)
                tree[ind][i] = tree[2 * ind][i] + tree[2 * ind + 1][i];
        }

        void update(int a, int b, int val, int nR)
        { change_val(0, MAX_N, val, nR, 1, a, b); }
};

int N, Q;

int main() {
    cin >> N >> Q;
    SegTree seg(MAX_N);
    
    int x;
    for (int i = 0; i < N; i ++) {
        cin >> x;
        seg.update(i, i, x, -1);
    }
    
    int a, b, c, d, e;
    for (int i = 0; i < Q; i ++) {
        cin >> a;
        
        if (a == 1) {
            cin >> b >> c >> d >> e;
            
            if (d == e)
                continue;
            
            seg.update(b - 1, c - 1, d, e);
        }
        
        else {
            cin >> b >> c;
            cout << seg.query(b - 1, c - 1) << endl;
        }
    }
    
    return (0);
}