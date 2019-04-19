/*
ID: akommul1
LANG: C++
PROB: cowxor
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>

#define MAX_N 700005
#define f first
#define s second

using namespace std;

struct node {
    int lft, rght;
};

class Trie {
    private:
        node con[MAX_N];
        node default_node;

        int index;
    
    public:
        int cur;

        Trie(int N) {
            default_node.lft = -1;
            default_node.rght = -1;

            for (int i = 0; i < MAX_N; i ++) {
                con[i].lft = -1;
                con[i].rght = -1;
            }
            
            con[0] = default_node;
            index = 1;
        }
        
        void update(int loc, int ind) { 
            if (loc == 23)
                return;
            
            if (((cur) & (1 << (22 - loc))) == 0) {
                if (con[ind].lft == -1) {
                    con[ind].lft = index;
                    index ++;
                    
                    update(loc + 1, index - 1);
                }
                
                else {
                    update(loc + 1, con[ind].lft);
                }
            }
            
            else {
                if (con[ind].rght == -1) {
                    con[ind].rght = index;
                    index ++;
                    
                    update(loc + 1, index - 1);
                }
                
                else {
                    update(loc + 1, con[ind].rght);
                }
            }
        }
        
        int query(int loc, int ind) {
            if (loc == 23)
                return (0);
            
            if (((cur) & (1 << (22 - loc))) == 0) {
                if (con[ind].rght == -1) {
                    return (query(loc + 1, con[ind].lft));
                }
                
                else {
                    return ((1 << (22 - loc)) + query(loc + 1, con[ind].rght));
                }
            }
            
            else {
                if (con[ind].lft == -1) {
                    return ((1 << (22 - loc)) + query(loc + 1, con[ind].rght));
                }
                
                else {
                    return (query(loc + 1, con[ind].lft));
                }
            }
        }
};

vector<string> pos;

int ar[MAX_N], pre[MAX_N];
int N;

int main() {
    ifstream fin ("cowxor.in");
    ofstream fout ("cowxor.out");
    
    fin >> N;
    
    if (N == 1) {
        fin >> ar[0];
        fout << ar[0] << " 1 1" << endl;
        
        return (0);
    }
    
    for (int i = 0; i < N; i ++) {
        fin >> ar[i];
        
        if (i > 0)
            pre[i] = pre[i - 1] ^ ar[i];
        else
            pre[i] = ar[i];
    }
    
    Trie tri(MAX_N);

    int ans = pre[0];
    int val, tmp, tar, L, R;
    
    R = 0;
    tar = pre[0];

    for (int i = 0; i < N; i ++) {
        if (i > 0) {
            tri.cur = pre[i];
            tmp = tri.query(0, 0);
            
            val = pre[i] ^ tmp;
            
            if (val > ans) {
                tar = tmp;
                
                R = i;
                ans = val;
            }
        }
        
        tri.cur = pre[i];
        tri.update(0, 0);
    }
    
    for (int i = 0; i <= R; i ++) 
        if (tar == pre[i]) 
            L = i;
    
    fout << ans << " " << min(R + 1, (L + 2)) << " " << (R + 1) << endl;
    return (0);
}