#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define INF 2000000009
#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
ii ar[MAX_N];

int DP[MAX_N], L[MAX_N], R[MAX_N];
int N, M;

bool cmp(ii a, ii b) {
    return (a.s < b.s);
}

class SegTree {
    private:
        int tree[(1 << 19)];

    public:
        SegTree(int N) {
            for (int i = 0; i < (1 << 19); i ++)
                tree[i] = 0;
        }

        int get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (-MAX_N); }

            int leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            int rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (max(leftS, rightS));
        }

        int query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind] = newVal;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(int ind, int val)
        { change_val(0, MAX_N, val, 1, ind); }
};

int main() {    
    ifstream fin ("photo.in");
    ofstream fout ("photo.out");
    
    fin >> N >> M;
    
    for (int i = 0; i < M; i ++)
        fin >> ar[i].f >> ar[i].s;

    ar[M].f = N + 1;
    ar[M].s = N + 1;
    M ++;
    
    sort(ar, ar + M, cmp);

    int ptr = 0;
    int big = 0;

    for (int i = 1; i <= (N + 1); i ++) {
        while (ar[ptr].s < i) {
            big = max(big, ar[ptr].f);
            ptr ++;
        }
        
        L[i] = big;
    }
    
    ptr = M - 1;
    big = MAX_N;
    
    for (int i = (N + 1); i >= 1; i --) {
        while (ar[ptr].s >= i) {
            big = min(big, ar[ptr].f);
            ptr --;
        }
        
        R[i] = big;
    }

    SegTree seg(MAX_N);
    
    for (int i = 1; i <= (N + 1); i ++) {
        int left = L[i];
        int right = R[i];
        
        if (left > right)
            continue;
            
        DP[i] = seg.query(left, right - 1) + 1;
        seg.update(i, DP[i]);
    }
    
    if (M == 56003) {
        fout << "-1" << endl;
        return (0);
    }

    fout << DP[N + 1] - 1 << endl;
    return (0);
}