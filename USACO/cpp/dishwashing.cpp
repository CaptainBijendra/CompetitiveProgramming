#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

vector<int> stacks[MAX_N];

int N;

int main() {
    ifstream fin ("dishes.in");
    ofstream fout ("dishes.out");
    
    fin >> N;
    
    int x;
    int ind = 0;
    
    int smallest = -1;
    
    for (int i = 0; i < N; i ++) {
        fin >> x;
        
        if (smallest != -1 && x < smallest) {
            fout << i << endl;
            return (0);
        }
        
        if (i > 0) {
            for (int j = 0; j < ind; j ++) {
                if (stacks[j].size() > 0 && stacks[j][0] > x) {
                    if (stacks[j][stacks[j].size() - 1] < x) {
                        for (int k = 0; k < j; k ++)
                            stacks[k].clear();
                        
                        smallest = max(smallest, stacks[j][stacks[j].size() - 1]);
                            
                        while (stacks[j].size() > 0 && stacks[j][stacks[j].size() - 1] < x) {
                            if (stacks[j][stacks[j].size() - 1] < smallest) {
                                fout << i << endl;
                                return (0);
                            }
                            
                            stacks[j].erase(stacks[j].end() - 1);
                        }
                    }
                    
                    stacks[j].push_back(x);
                    break;
                }
            
                if (j == ind - 1) {
                    stacks[ind].push_back(x);
                    ind ++;
                    
                    break;
                }
            }
        }
        
        else {
            stacks[ind].push_back(x);
            ind ++;
        }
    }
    
    fout << N << endl;
    return (0);
}