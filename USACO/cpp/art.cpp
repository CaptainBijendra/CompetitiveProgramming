#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> in;
vector<ii> out;

bool bad[MAX_N * MAX_N], vis[MAX_N * MAX_N];

int conv[MAX_N * MAX_N];

int L[MAX_N * MAX_N], R[MAX_N * MAX_N], T[MAX_N * MAX_N], B[MAX_N * MAX_N];
int ar[MAX_N][MAX_N];
int N;

class SegTree {
    private:
        int tree[(1 << 18)];

    public:
        SegTree(int N) {
        }

        int get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (0); }

            int leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            int rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (leftS + rightS);
        }

        int query(int a, int b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {   
                tree[ind] += newVal;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
        }

        void update(int ind, int val)
        { change_val(0, MAX_N, val, 1, ind); }
};

int main() {
    ifstream fin ("art.in");
    ofstream fout ("art.out");
    
    fin >> N;
    
    for (int i = 1; i <= N * N; i ++) {
        L[i] = N;
        T[i] = N;
    }
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            fin >> ar[i][j];   
                
            vis[ar[i][j]] = true;
            L[ar[i][j]] = min(L[ar[i][j]], j);
            R[ar[i][j]] = max(R[ar[i][j]], j);
            T[ar[i][j]] = min(T[ar[i][j]], i);
            B[ar[i][j]] = max(B[ar[i][j]], i);
        }
    } 
    
    int a = -1;
    
    for (int i = 1; i <= N * N; i ++) {
        if (vis[i]) { 
            in.push_back(ii(L[i], i));
            out.push_back(ii(R[i], i));
        
            if (a == -1)
                a = N * N - 1;
            else
                a = -2;
        }    
    }
    
    if (a != -2) {
        fout << a << endl;
        return (0);
    }
        
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());
    
    SegTree ans(MAX_N);
    
    int l1 = 0;
    int l2 = 0;
    
    for (int i = 0; i < N; i ++) {
        while (l1 < in.size() && in[l1].f == i) {
            ans.update(T[in[l1].s], 1);
            ans.update(B[in[l1].s] + 1, -1);
            l1 ++;
        }

        for (int j = 0; j < N; j ++) 
            if (ans.query(0, j) > 1) 
                bad[ar[j][i]] = true;
    
        while (l2 < out.size() && out[l2].f == i) {
            ans.update(T[out[l2].s], -1);
            ans.update(B[out[l2].s] + 1, 1);
            l2 ++;
        }
    }
    
    int f_ans = 0;
    
    for (int i = 1; i <= N * N; i ++)
        if (!bad[i]) 
            f_ans ++;
    
    fout << f_ans << endl;
    return (0);
}