#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <string.h>

#define EXT 10005
#define MAX_N 100005
#define f first
#define s second

using namespace std;

map<int, int> conv;

int DP[MAX_N], pre[MAX_N], ar[MAX_N];
int N;

class SegTree {
    private:
        int tree[(1 << 19)];

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
        { return (get_val(0, (1 << 17) - 1, a, b, 1)); }

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
        { change_val(0, (1 << 17) - 1, val, 1, ind); }
};

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
    
        if (i == 0)
            pre[i] = ar[i];
        else
            pre[i] = pre[i - 1] + ar[i];
            
        conv[pre[i]] = 1;
    }
    
    int ind = 1;
    
    conv[0] = 1;
    
    for (map<int, int>::iterator it = conv.begin(); it != conv.end(); it ++)
        conv[it->f] = ind ++;
    
    SegTree ans(N);
    
    ans.update (conv[0], 1);
    for (int i = 0; i < N; i ++) {
        DP[i] = ans.query(0, conv[pre[i]]);
        ans.update(conv[pre[i]], DP[i]);
    }

    cout << DP[N - 1] << endl;
    return (0);
}