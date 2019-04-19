#include <bits/stdc++.h> 

#define INF 2000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> pii;

class SegTree {
    private:
        int tree[(1 << 20)];

    public:
        SegTree(int N) {
        }

        int get_val(int l, int r, int a, int b, int ind) {
            if (a <= l && r <= b) { return (tree[ind]); }
            if (a > r || b < l) { return (0); }

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

pii points[MAX_N];
map<int, int> conv;

int N;

bool cmp(pii a, pii b) {
    return (a.f.f < b.f.f);
}

int main() {
    cin >> N;
    
    vector<int> vec;
    
    for (int i = 0; i < N; i ++) {
        cin >> points[i].f.f >> points[i].f.s >> points[i].s.f >> points[i].s.s;
        vec.push_back(points[i].s.f);
    }
    
    sort(points, points + N, cmp);
    sort(vec.begin(), vec.end());
    
    int val = 0;
    
    conv[vec[0]] = val;
    val ++;
    
    for (int i = 1; i < vec.size(); i ++) {
        if (vec[i] == vec[i - 1])
            continue;
    
        conv[vec[i]] = val;
        val ++;
    }
    
    SegTree seg(MAX_N);
    seg.update(conv[points[0].s.f], 1);
    
    int big, ans = 0;
    
    for (int i = 1; i < N; i ++) {
        big = seg.query(0, conv[points[i].s.f] - 1);
        seg.update(conv[points[i].s.f], big + 1);
    
        ans = max(ans, big + 1);
    }
    
    cout << ans << endl;
    return (0);    
}