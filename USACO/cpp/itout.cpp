#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define MOD 200000000000000000
#define MAX_N 150005
#define f first
#define s second

using namespace std;

vector<long long> cnt[MAX_N];
vector<long long> dp[MAX_N];

bool used[MAX_N];

long long ar[MAX_N], DP[MAX_N], ways[MAX_N], loc[MAX_N];
long long N, K;

class SegTree {
    private:
        long long tree[(1 << 19)];

    public:
        SegTree(long long N) {
        }

        long long get_val(long long l, long long r, long long a, long long b, long long ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (0); }

            long long leftS = get_val(l, (l + r) / 2, a, b, 2 * ind);
            long long rightS = get_val((l + r) / 2 + 1, r, a, b, 2 * ind + 1);

            return (max(leftS, rightS));
        }

        long long query(long long a, long long b)
        { return (get_val(0, MAX_N, a, b, 1)); }

        void change_val(long long l, long long r, long long newVal, long long ind, long long tmp) {
            if (tmp > r || tmp < l) { return; }
            if (l == r) {
                tree[ind] = newVal;
                return;
            }

            change_val(l, (r + l) / 2, newVal, 2 * ind, tmp);
            change_val((r + l) / 2 + 1, r, newVal, 2 * ind + 1, tmp);

            tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
        }

        void update(long long ind, long long val)
        { change_val(0, MAX_N, val, 1, ind); }
};

bool cmp(int a, int b) {
    return (ar[a] > ar[b]);
}

int main() {
    ifstream fin ("itout.in");
    ofstream fout ("itout.out");

    fin >> N >> K;

    for (long long i = 0; i < N; i ++) {
        fin >> ar[i];
        loc[ar[i]] = i;
    }
    
    SegTree ans(MAX_N);
    ans.update(ar[N - 1], 1);

    DP[N - 1] = 1;
    ways[ar[N - 1]] = 1;
    cnt[1].push_back(N - 1);

    long long len = 0;

    for (long long i = N - 2; i >= 0; i --) {
        DP[i] = ans.query(ar[i] + 1, MAX_N) + 1;
        ans.update(ar[i], DP[i]);
        len = max(len, DP[i]);
    }
    
    for (int i = N - 2; i >= 0; i --) {
        ways[ar[i]] = 1;

        for (long long j = 0; j < cnt[DP[i] - 1].size(); j ++)
            if (ar[cnt[DP[i] - 1][j]] > ar[i]) {
                if (ways[ar[cnt[DP[i] - 1][j]]] == 1)
                    ways[ar[i]] ++;
                else
                    ways[ar[i]] += ways[ar[cnt[DP[i] - 1][j]]];
                    
                ways[ar[i]] = min(ways[ar[i]], K + 1);
            }
        
        if (ways[ar[i]] > 1)
            ways[ar[i]] --;
        
        cnt[DP[i]].push_back(i);
    }
    
    for (int i = 0; i < N; i ++)
        dp[DP[i]].push_back(i);
    
    for (int i = 1; i <= N; i ++)
        sort(dp[i].begin(), dp[i].end(), cmp);
    
    fout << (N - len) << endl;

    long long prev = -1;
    
    for (int i = len; i > 0; i --) {
        for (int j = 0; j < dp[i].size(); j ++) {
            if (loc[ar[dp[i][j]]] > prev && ways[ar[dp[i][j]]] < K) {
                K -= ways[ar[dp[i][j]]];
            }
            
            else {
                if (loc[ar[dp[i][j]]] > prev) {
                    used[ar[dp[i][j]]] = true;
                    prev = loc[ar[dp[i][j]]];
                    break;
                }
            }
        }
    }
    
    for (long long i = 1; i <= N; i ++)
        if (!used[i])
            fout << i << endl;

    return (0);
}