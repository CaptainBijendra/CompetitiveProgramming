#include <iostream>
#include <fstream>

#define MAX 5

using namespace std;

char pos;

long long DP[MAX + 1][MAX + 1][MAX + 1][MAX + 1][MAX + 1];
long long N;

char final_str[MAX * MAX + 1];

ifstream fin ("twofive.in");
ofstream fout ("twofive.out");

int get_way() {
    int ind[5];
    
    DP[MAX][MAX][MAX][MAX][MAX] = 1;
    
    for (ind[0] = MAX; ind[0] >= 0; ind[0] --) {
        for (ind[1] = ind[0]; ind[1] >= 0; ind[1] --) {
            for (ind[2] = ind[1]; ind[2] >= 0; ind[2] --) {
                for (ind[3] = ind[2]; ind[3] >= 0; ind[3] --) {
                    for (ind[4] = ind[3]; ind[4] >= 0; ind[4] --) {
                        long long pos = 0;

                        for (int nxt = 0; nxt < MAX; nxt ++) {
                            if (ind[nxt] < MAX && (nxt == 0 || ind[nxt] + 1 <= ind[nxt - 1])) { 
                                ind[nxt] ++;
                                pos += DP[ind[0]][ind[1]][ind[2]][ind[3]][ind[4]];
                                ind[nxt] --;
                            }
                        }
                        
                        DP[ind[0]][ind[1]][ind[2]][ind[3]][ind[4]] += pos;                          
                    }
                }
            }
        }
    }
}

void solve_for_num() {
    char sol[5 * 5 + 1];
    int ind[5] = { 0, 0, 0, 0, 0 };
    
    long long num_skip = 0;

    for (int i = 0; i < MAX * MAX; i ++) {
        int j = 0;

        for (j = 0; j < MAX; j ++) {
            long long skip = 0;
            
            if (ind[j] + 1 <= MAX && (j == 0 || ind[j] + 1 <= ind[j - 1])) {
                ind[j] ++;
                skip += DP[ind[0]][ind[1]][ind[2]][ind[3]][ind[4]];
                ind[j] --;
                
                if (num_skip + skip >= N) { break; }
            
                num_skip += skip;
            }
        }
        
        sol[j * MAX + ind[j]] = char(i + 'A');
        ind[j] ++;
    }
    
    for (int i = 0; i < MAX * MAX; i ++) { fout << sol[i]; }
    fout << endl;
}

void solve_for_str() {
    int ind[5] = { 0, 0, 0, 0, 0 }; 
    
    long long val_ind = 1;
    
    for (int i = 0; i < MAX * MAX; i ++) {
        int j;
        
        for (j = 0; j < MAX; j ++) {
            if (ind[j] < MAX) {
                if (final_str[j * MAX + ind[j]] == (i + 'A')) {
                    break;
                }
                
                else {
                    ind[j] ++;
                    val_ind += DP[ind[0]][ind[1]][ind[2]][ind[3]][ind[4]];
                    ind[j] --;
                }
            }
        }
        
        ind[j] ++;
    }
    
    fout << val_ind << endl;
}

int main() {
    fin >> pos;
    
    get_way();
    
    if (pos == 'N') {
        fin >> N;
        solve_for_num(); 
    }
    
    else {
        fin >> final_str;
        solve_for_str();
    }
    
    return (0);
}