#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define MAX_N 100005

using namespace std;

typedef pair<int, int> ii;

vector<int> sol;

int A[MAX_N], loc[MAX_N];
int N, K;

class SegTree {
    private:
        int tree[(1 << 18)];
        ii range[(1 << 18)];

    public:
        SegTree(int N) {
            build_tree(0, N - 1, 1);
        }

        int build_tree(int l, int r, int ind) {
            if (l == r) {
                range[ind].first = l; range[ind].second = r;
                return (tree[ind] = 0);
            }

            int leftS = build_tree(l, (r + l) / 2, 2 * ind);
            int rightS = build_tree((r + l) / 2 + 1, r, 2 * ind + 1);

            range[ind].first = l; range[ind].second = r;
            tree[ind] = 0; 

            return (0);
        }

        int get_val(int l, int r, int ind) {
            if (l <= range[ind].first && range[ind].second <= r) { return (tree[ind]); }
            if (l > range[ind].second || r < range[ind].first) { return (0); }

            int leftS = get_val(l, r, 2 * ind);
            int rightS = get_val(l, r, 2 * ind + 1);

            return (max(leftS, rightS));
        }

        int query(int a, int b)
        { return (get_val(a, b, 1)); }

        void change_val(int l, int r, int newVal, int ind, int tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) { tree[ind] = newVal; return; }

            tree[ind] = max(tree[ind], newVal);
            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);
        }

        void update(int ind, int val) 
        { change_val(0, N - 1, val, 1, ind); }
};

int main() {
    ifstream fin ("friendcross.in");
    ofstream fout ("friendcross.out");

    fin >> N >> K;
    
    int a;

    for (int i = 0; i < N; i ++) { fin >> A[i]; A[i] --; }
    for (int i = 0; i < N; i ++) 
    { fin >> a; loc[a - 1] = i; }
    
    SegTree DP(N);

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= max(0, (A[i] - K - 1)); j ++) 
        { sol.push_back(loc[j]); }

        for (int j = min(N, A[i] + K + 1); j < N; j ++) 
        { sol.push_back(loc[j]); }
        
        sort(sol.begin(), sol.end());

        for (int j = sol.size() - 1; j >= 0; j --) 
        { DP.update(sol[j], DP.query(0, sol[j] - 1) + 1); }
   
        sol.clear();
    }   
    
    fout << DP.query(0, N - 1) << endl;
    return (0);
}

