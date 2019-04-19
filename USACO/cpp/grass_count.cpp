#include <bits/stdc++.h>

#define ll long long

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

using namespace std;
const int INF = 1e9;
 
int N, M;

template<class T, int SZ> struct LazySegTree {
    T sum[2*SZ], mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
 
    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
    }
 
    void push(int ind, int L, int R) {
        sum[ind] += (R-L+1)*lazy[ind];
        mn[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }
 
    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    }
 
    void build() {
        for(int i = SZ-1;i>=0; i--){
            pull(i);
        }
    }
 
    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
 
        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }
 
    T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return INF;
        if (lo <= L && R <= hi) return mn[ind];
 
        int M = (L+R)/2;
        return min(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));
    }
 
    void upd(int lo, int hi, long long inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
 
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

vector<vector<int> > graph;

template<int SZ> struct HLD { // sum queries, sum updates
    int parent[SZ], heavy[SZ], depth[SZ];
    int root[SZ], treePos[SZ];
    LazySegTree<int,SZ> tree;

    void init() {
        int n = graph.size()-1;
        FOR(i,1,n+1) heavy[i] = -1;
        parent[1] = -1, depth[1] = 0;
        dfs(1);
        for (int i = 1, currentPos = 0; i <= n; ++i)
		if (parent[i] == -1 || heavy[parent[i]] != i)
			for (int j = i; j != -1; j = heavy[j]) {
				root[j] = i;
				treePos[j] = currentPos++;
			}
    }
    
    int dfs(int v) {
        int size = 1, maxSubtree = 0;
        for (auto u : graph[v]) if (u != parent[v]) {
            parent[u] = v;
            depth[u] = depth[v] + 1;
            int subtree = dfs(u);
            if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
            size += subtree;
        }
        return size;
    }

    template <class BinaryOperation>
    void processPath(int u, int v, BinaryOperation op) {
        for (; root[u] != root[v]; v = parent[root[v]]) {
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
            op(treePos[root[v]], treePos[v]);
        }
        if (depth[u] > depth[v]) swap(u, v);
        op(treePos[u]+1, treePos[v]); // assumes values are stored in edges, not vertices
    }

    void modifyPath(int u, int v, int value) { // add one to vertices along path
        processPath(u, v, [this, &value](int l, int r) { tree.upd(l, r, value); });
    }

    ll queryPath(int u, int v) { // query sum of path
        ll res = 0;
        processPath(u, v, [this, &res](int l, int r) { res += tree.qsum(l, r); });
        return res;
    }
};
 
HLD< 1 << 17 > H;

int main() {
    cin >> N >> M;
  
    graph.resize(N + 1);
  
    int a, b;	  
    for(int i = 0; i < N - 1; i ++) {
	      cin >> a >> b;
	      
	      graph[a].push_back(b); 
	      graph[b].push_back(a);
	  }
	
	  H.init();
	  
    char x;
    for (int i = 0; i < M; i ++) {
        cin >> x;
        cin >> a >> b;

        if (x == 'Q')
            cout << H.queryPath(a, b) << endl;
        else {
            H.modifyPath(a, b, 1);
        }      
    }    

    return (0);
}