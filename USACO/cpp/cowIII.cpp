#include <stdio.h>

#define MAXV (1 << 30)
#define MAX_N (1 << 18)

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
    val += v;
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
    return (C[0] ? C[0]->query(a, b, lo, md) : 0) +
           (C[1] ? C[1]->query(a, b, md, hi) : 0);
  }
};

node BT[MAX_N];

/* Logically executes array[y + 1].add(x, v) += v. */
void bit_add(int x, int y, int v) {
  for(unsigned j = y | MAX_N; j < (MAX_N << 1); j += j & -j) {
    BT[j ^ MAX_N].add(x, v, 0, MAXV);
  }
}
    
/* Returns the sum of array[i].query(x0, x1) for 0 <= i < y */
int bit_get(int x0, int x1, int y) {
  int ret = 0;
  for(int j = y - 1; y != 0; j &= j - 1) {
    ret += BT[j].query(x0, x1, 0, MAXV);
    if (!j) break;
  }
  return ret;
}

int A[MAX_N], B[MAX_N], pos[MAX_N], ar[MAX_N];
int N, K;

int min(int a, int b) {
    return (a < b ? a : b);
}

int main() {
    freopen("friendcross.in","r",stdin);
    freopen("friendcross.out","w",stdout);
    
    scanf("%d %d", &N, &K);
    
    for (int i = 0; i < N; i ++)
        scanf("%d", &A[i]);
        
    for (int i = 0; i < N; i ++) {
        scanf("%d", &B[i]);
        pos[B[i]] = i;
    }   
    
    for (int i = 0; i < N; i ++)
        ar[i] = pos[A[i]];
    
    long long sum = 0;
    for (int i = N - 1; i >= 0; i --) {
        if (A[i] - K >= 0)
            sum += bit_get(0, A[i] - K, ar[i]);

        sum += bit_get(min(N, A[i] + K + 1), N, ar[i]);
        bit_add(A[i], ar[i], 1);
    }
    
    printf("%lld\n", sum);
    return (0);
}