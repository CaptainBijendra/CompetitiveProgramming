#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define MAXV (1 << 30)
#define MAX_N (1 << 18)
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

unordered_map<int, node> BT;

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

int A[MAX_N], B[MAX_N], pos[MAX_N], ar[MAX_N], posA[MAX_N];
int N, M;

int main() {  
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        cin >> A[i];
        posA[A[i]] = i;
    }
    
    for (int i = 0; i < N; i ++) {
        cin >> B[i];
        pos[B[i]] = i;
    }
 
    for (int i = 0; i < N; i ++) {
        ar[i] = pos[A[i]];
        bit_add(i, ar[i], 1);
    }
  
    int a, b, c, d, e;
    for (int i = 0; i < M; i ++) {
        cin >> a;
        
        if (a == 1) {
            cin >> b >> c >> d >> e;
            b --; c --;
            cout << bit_get(b, (c + 1), e) - bit_get(b, (c + 1), d - 1) << endl;
        }
        
        else {
            cin >> b >> c;
            b --; c --;

            bit_add(posA[B[b]], ar[posA[B[b]]], -1);
            bit_add(posA[B[c]], ar[posA[B[c]]], -1);
            
            pos[B[c]] = b;
            pos[B[b]] = c;
            
            ar[posA[B[b]]] = pos[B[b]];
            ar[posA[B[c]]] = pos[B[c]];
            
            int tmp = B[c];
            B[c] = B[b];
            B[b] = tmp;
            
            bit_add(posA[B[b]], ar[posA[B[b]]], 1);
            bit_add(posA[B[c]], ar[posA[B[c]]], 1);
        }
    }

    return (0);
}