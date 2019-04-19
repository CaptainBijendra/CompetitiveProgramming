#include <iostream>

#define MAX_N 205

using namespace std;

int chain[MAX_N];
int N;

bool try_DFS (int cur_depth, int max_depth) {
    if (cur_depth == max_depth) {
        if (chain[cur_depth - 1] == N)
            return (true);
        else
            return (false);
    }

    for (int i = 0; i < cur_depth; i ++) {
        for (int j = i + 1; j < cur_depth; j ++) {
            if (chain[i] + chain[j] > chain[cur_depth - 1]) {
                chain[cur_depth] = chain[i] + chain[j];

                bool a = try_DFS(cur_depth + 1, max_depth);
                
                if (a)
                    return (true);
                
                chain[cur_depth] = 0;
            }
        }
    }
    
    return (false);
}

int main() {
    cin >> N;
    
    chain[0] = 1;
    chain[1] = 2;
        
    for (int d = 4; d < MAX_N; d ++) {
        if (try_DFS(2, d + 1)) { 
            cout << d << endl;
            return (0);
        }
    }

    return (0);
}