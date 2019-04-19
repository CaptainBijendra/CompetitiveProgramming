#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>

#define INF 200000000000009
#define MAX_N 300005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;
typedef pair<ii, long long> pii;

vector<pii> Q1, Q2;
vector<ii> p1, p2;

pii Q[MAX_N];
ii pos[MAX_N];

map<long long, long long> conv;

long long qind[MAX_N], ans1[MAX_N], ans2[MAX_N];
long long N, M;

class SegTree {
    private:
        ii tree[(1 << 21)];
        ii tree2[(1 << 21)];
        bool used[(1 << 21)];

    public:
        SegTree(long long N) {
            for (long long i = 0; i < (1 << 21); i ++) {
                tree[i].f = INF; tree[i].s = INF;
                tree2[i].f = -INF; tree2[i].s = -INF;
            }
        }

        ii get_val1(long long l, long long r, long long a, long long b, long long ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (ii(INF, INF)); }

            ii leftS = get_val1(l, (l + r) / 2, a, b, 2 * ind);
            ii rightS = get_val1((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (ii(min(leftS.f, rightS.f), min(leftS.s, rightS.s)));
        }

        ii query1(long long a, long long b)
        { return (get_val1(0, MAX_N, a, b, 1)); }
        
        ii get_val2(long long l, long long r, long long a, long long b, long long ind) {
            if (a <= l && r <= b) { return (tree2[ind]); }
            if (a > r || b < l) { return (ii(-INF, -INF)); }

            ii leftS = get_val2(l, (l + r) / 2, a, b, 2 * ind);
            ii rightS = get_val2((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (ii(max(leftS.f, rightS.f), max(leftS.s, rightS.s)));
        }

        ii query2(long long a, long long b)
        { return (get_val2(0, MAX_N, a, b, 1)); }

        void change_val(long long l, long long r, long long newVal, long long newVal2, long long newVal3, long long ind, long long tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                if (newVal3 == INF || used[ind]) {
                    tree[ind].f = INF; tree2[ind].f = -INF;
                    tree[ind].s = INF; tree2[ind].s = -INF;
                    used[ind] = true;
                    
                    return;
                }
                
                tree[ind].f = min(tree[ind].f, newVal2 + newVal + newVal3); tree2[ind].f = max(tree2[ind].f, newVal + newVal2 - newVal3);
                tree[ind].s = min(tree[ind].s, newVal2 - newVal + newVal3); tree2[ind].s = max(tree2[ind].s, -newVal + newVal2 - newVal3);
                return;
            }

            change_val(l, (r + l) / 2, newVal, newVal2, newVal3, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, newVal2, newVal3, 2 * ind + 1, tmp);

            tree[ind] = ii(min(tree[2 * ind].f, tree[2 * ind + 1].f), min(tree[2 * ind].s, tree[2 * ind + 1].s));
            tree2[ind] = ii(max(tree2[2 * ind].f, tree2[2 * ind + 1].f), max(tree2[2 * ind].s, tree2[2 * ind + 1].s));
        }

        void update(long long ind, long long val1, long long val2, long long val3)
        { change_val(0, MAX_N, val1, val2, val3, 1, ind); }
};

bool cmp1(long long a, long long b) {
    return (p1[a].f < p1[b].f);
}

bool cmp2(long long a, long long b) {
    return (p2[a].f < p2[b].f);
}

int main() {
    ifstream fin ("slingshot.in");
    ofstream fout ("slingshot.out");
    
    fin >> N >> M;

    vector<long long> cl;

    for (long long i = 0; i < N; i ++) {
        fin >> Q[i].f.f >> Q[i].f.s >> Q[i].s;
        
        if (Q[i].f.f <= Q[i].f.s)
            Q1.push_back(Q[i]);
        else
            Q2.push_back(Q[i]);
    }
    
    vector<int> sol;
    
    for (long long i = 0; i < M; i ++) {
        fin >> pos[i].f >> pos[i].s;
    
        if (pos[i].f <= pos[i].s) {
            p1.push_back(pos[i]);
            sol.push_back(0);
        }
        
        else {
            p2.push_back(pos[i]);
            sol.push_back(1);
        }
    }
    
    N = Q1.size();
    M = p1.size();
    
    for (long long i = 0; i < M; i ++) {
        qind[i] = i;
        cl.push_back(p1[i].s);
    }
    
    for (long long i = 0; i < N; i ++)
        cl.push_back(Q1[i].f.s);
    
    sort(cl.begin(), cl.end());
    
    long long ind = 2;
    
    conv[cl[0]] = 1;
    for (long long i = 1; i < cl.size(); i ++) {
        if (cl[i] == cl[i - 1])
            continue;
            
        conv[cl[i]] = ind;
        ind ++;
    }
    
    cl.clear();
    
    sort(Q1.begin(), Q1.end());
    sort(qind, qind + M, cmp1);
    
    SegTree in(MAX_N);
    SegTree out(MAX_N);
    
    for (long long i = 0; i < N; i ++) 
        out.update(conv[Q1[i].f.s], Q1[i].f.s, Q1[i].f.f, Q1[i].s);

    long long lft = 0;    
    
    for (long long ind = 0; ind < M; ind ++) {
        long long i = qind[ind];
        
        while (lft < N && Q1[lft].f.f <= p1[i].f) {
            out.update(conv[Q1[lft].f.s], 0, 0, INF);
            in.update(conv[Q1[lft].f.s], Q1[lft].f.s, Q1[lft].f.f, Q1[lft].s);
    
            lft ++;
        }
        
        long long a = -1 * in.query2(0, conv[p1[i].s]).f;
        long long b = -1 * in.query2(conv[p1[i].s] + 1, MAX_N - (MAX_N / 3)).s;
        long long c = out.query1(0, conv[p1[i].s]).s;
        long long d = out.query1(conv[p1[i].s] + 1, MAX_N - (MAX_N / 3)).f;

        long long pos1 = min(a + p1[i].f + p1[i].s, b + p1[i].f - p1[i].s);
        long long pos2 = min(c - p1[i].f + p1[i].s, d - p1[i].f - p1[i].s);

        ans1[i] = min(abs(p1[i].f - p1[i].s), min(pos1, pos2));
    }

    N = Q2.size();
    M = p2.size();
    
    for (long long i = 0; i < N; i ++) {
        long long tmp = Q2[i].f.f;
        Q2[i].f.f = Q2[i].f.s;
        Q2[i].f.s = tmp;
    }
    
    for (long long i = 0; i < M; i ++) {
        long long tmp = p2[i].f;
        p2[i].f = p2[i].s;
        p2[i].s = tmp;
    }
    
    for (long long i = 0; i < M; i ++) {
        qind[i] = i;
        cl.push_back(p2[i].s);
    }
    
    for (long long i = 0; i < N; i ++)
        cl.push_back(Q2[i].f.s);
    
    sort(cl.begin(), cl.end());
    conv.clear();
    
    ind = 2;
    conv[cl[0]] = 1;
    for (long long i = 1; i < cl.size(); i ++) {
        if (cl[i] == cl[i - 1])
            continue;
            
        conv[cl[i]] = ind;
        ind ++;
    }
    
    sort(Q2.begin(), Q2.end());
    sort(qind, qind + M, cmp2);
    
    SegTree in2(MAX_N);
    SegTree ot2(MAX_N);
    
    for (long long i = 0; i < N; i ++) 
        out2.update(conv[Q2[i].f.s], Q2[i].f.s, Q2[i].f.f, Q2[i].s);
        
    lft = 0;    
    
    for (long long ind = 0; ind < M; ind ++) {
        long long i = qind[ind];
        
        while (lft < N && Q2[lft].f.f <= p2[i].f) {
            out2.update(conv[Q2[lft].f.s], 0, 0, INF);
            in2.update(conv[Q2[lft].f.s], Q2[lft].f.s, Q2[lft].f.f, Q2[lft].s);
            lft ++;
        }
        
        long long a = -1 * in2.query2(0, conv[p2[i].s]).f;
        long long b = -1 * in2.query2(conv[p2[i].s] + 1, MAX_N - (MAX_N / 3)).s;
        long long c = out2.query1(0, conv[p2[i].s]).s;
        long long d = out2.query1(conv[p2[i].s] + 1, MAX_N - (MAX_N / 3)).f;
        
        long long pos1 = min(a + p2[i].f + p2[i].s, b + p2[i].f - p2[i].s);
        long long pos2 = min(c - p2[i].f + p2[i].s, d - p2[i].f - p2[i].s);   
        
        ans2[i] = min(abs(p2[i].f - p2[i].s), min(pos1, pos2));
    }
    
    int l = 0;
    int r = 0;
    
    for (long long i = 0; i < sol.size(); i ++) {
        if (sol[i] == 0) {
            fout << ans1[l] << endl;
            l ++;
        }
        
        else {
            fout << ans2[r] << endl;
            r ++;
        }
    }

    return (0);
}