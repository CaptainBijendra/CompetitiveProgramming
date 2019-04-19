#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string.h>
#include <math.h>

#define MAX_N 30005
#define f first
#define s second

using namespace std;

//0 -> right
//1 -> down
//2 -> left
//3 -> up

map<vector<int>, int> cnv;
map<int, vector<int> > rcnv;

vector<int> cur;

int con[MAX_N * 6][4];
int N, K, NUM, c;

void gen_trans(int ind) {
    if (ind == K) {
        if (cnv.find(cur) == cnv.end()) {
            cnv[cur] = NUM;
            rcnv[NUM] = cur; NUM ++;
        }
        
        return;
    }
    
    for (int i = 0; i <= c; i ++) {
        cur[ind] = i;
        gen_trans(ind + 1);
    }
    
    cur[ind] = ++c;
    gen_trans(ind + 1);
    c --;
}

vector<int> standardize(vector<int> c) {
    
}

int main() {
    cin >> N >> K;
    
    NUM = 0; c = -1; cur.resize(K);
    gen_trans(0);
    
    int x;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < K - 1; j ++) {
            cin >> x;
            
            con[i * K + j][0] = x;
            con[i * K + j + 1][2] = x; 
        }
    }
    
    for (int i = 0; i < K; i ++) {
        for (int j = 0; j < N - 1; j ++) {
            cin >> x;
            
            con[j * K + i][3] = x;
            con[(j + 1) * K + i][1] = x;
        }
    }
    
    int DP[MAX_N][2 * K - 1][NUM];
    int cnt[MAX_N][2 * K - 1][NUM];
    
    ii nxt[2 * K - 1][NUM]; //first = by adding edge 'i', connectivity state changes to what?
                            //second = by not adding edge 'i', connectivity state changes to what?
    
    for (int i = 0; i < K; i ++) {
        for (int j = 0; j < NUM; j ++) {
            vector<int> c = rcnv[j];
            
            //Connect vertical edge
            nxt[i][j].f = j;
            
            //Don't connect vertical edge
            c[i] = K; 
            c = standardize(c);
            
            nxt[i][j].s = cnv[c];
        }
    }
    
    for (int i = K; i < 2 * K - 1; i ++) {
        for (int j = 0; j < NUM; j ++) {
            vector<int> c = rcnv[j];
            
            //Connect horizontal edge
            c
            nxt[i][j].f = 
            
            //Don't connect horizontal edge
            
        }
    }
    
    return (0);
}