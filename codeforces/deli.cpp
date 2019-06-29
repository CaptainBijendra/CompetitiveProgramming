#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

class SegTree {
    private:
        long long tree[4 * MAX_N];

    public:
        long long get_val(long long l, long long r, long long a, long long b, long long ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (0); }

            long long leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            long long rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (leftS + rightS);
        }

        long long query(long long a, long long b)
        { return (get_val(0, MAX_N, a, b, 1)); }
        
        int query2 (long long l, long long r, long long ind, long long cur_sum) {
            if (l == r)
                return (l);
            
            if (cur_sum < tree[2 * ind])
                return (query2(l, (l + r) / 2, 2 * ind, cur_sum));
            else
                return (query2((l + r) / 2 + 1, r, 2 * ind + 1, cur_sum - tree[2 * ind]));
        }

        void change_val(long long l, long long r, long long newVal, long long ind, long long tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind] = newVal;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
        }

        void update(long long ind, long long val)
        { change_val(0, MAX_N, val, 1, ind); }
};

SegTree sum[31];
SegTree cnt[31];

int ar[MAX_N];
int S, N, M;

void update(int val, int loc) {
    for (int i = 30; i >= 0; i --) {
        int x = (1 << i);
        
        if (val <= x) {
            sum[i].update(loc, val);
            cnt[i].update(loc, 1);
        }
    }
}

int main() {
    cin >> S;
    
    for (int ii = 0; ii < S; ii ++) {
        cin >> N >> M;
        
        for (int i = 0; i < 31; i ++) {
            for (int j = 0; j < N; j ++) {
                sum[i].update(j, 0);
                cnt[i].update(j, 0);
            }
        }
        
        for (int i = 0; i < N; i ++) {
            cin >> ar[i];
            update(x, i);
        }

        cout << "Scenario #" << (ii + 1) << ":" << endl;

        long long a, b, c, y;
        for (int i = 0; i < M; i ++) {
            cin >> a;

            if (a == 1) {
                cin >> b;
                
                int idx = 0;
                int tot = b;
                int prev = -1;
                
                y = 0;
                for (int k = 30; k >= 0; k --) {
                    prev = idx;
                    
                    idx = sum[k].query2(tot) - 1;
                    tot += ar[idx + 1];
                    
                    y += cnt[k].query(prev, idx);
                }

                cout << "David can get " << (y) << " toppings" << endl;
            } else {
                cin >> b >> c;
                ar[b - 1] = c;
                
                update(c, b - 1);
            }
        }
        
        if (ii + 1 != S)
            cout << endl;
    }

    return (0);
}