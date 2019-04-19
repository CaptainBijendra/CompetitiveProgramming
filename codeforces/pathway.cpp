#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define MAX_N (1 << 20)
#define MAX_T 230005

#define f first
#define s second

struct node {
  int val;
  struct node* C[2];

  node() {
    val = 0;
    C[0] = C[1] = NULL;
  }

  node* getc(int c) {
    if (!C[c]) {
      C[c] = new node;
    }
    return C[c];
  }

  void add(int x, int v, int lo, int hi) {
    val = max(val, v);
    if (hi - lo == 1) {
      return;
    }
    int md = (lo + hi) / 2;
    if (x < md) {
      getc(0)->add(x, v, lo, md);
    } else {
      getc(1)->add(x, v, md, hi);
    }
  }

  int query(int a, int b, int lo, int hi) {
    if (a <= lo && hi <= b) {
      return val;
    } else if (hi <= a || b <= lo) {
      return 0;
    }
    int md = (lo + hi) / 2;
    return max((C[0] ? C[0]->query(a, b, lo, md) : 0), 
               (C[1] ? C[1]->query(a, b, md, hi) : 0));
  }
};

node BT[MAX_N];

int ans[MAX_N];
int N, M;

int main() {
    cin >> N >> M;
    
    int a, b, c, nt;
    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        a --; b --;
      
        nt = BT[a].query(0, c + 1, 0, MAX_N) + 1;
      
        ans[b] = max(ans[b], nt);
        BT[b].add(c + 1, nt, 0, MAX_N);
    }
    
    int final = 0;
    for (int i = 0; i < N; i ++) 
        final = max(final, ans[i]);
    
    cout << final << endl;
    return (0);
}