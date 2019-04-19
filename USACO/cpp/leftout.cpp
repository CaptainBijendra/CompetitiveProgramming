#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

#define MAX_N 1005
#define f first
#define s second

using namespace std;

int pos[MAX_N][MAX_N];
int N;

int main() {
    ifstream fin ("leftout.in");
    ofstream fout ("leftout.out");
    
    fin >> N;
    
    string str;
    for (int i = 0; i < N; i ++) {
        fin >> str;
        
        for (int j = 0; j < N; j ++) {
            if (str[j] == 'R')
                pos[i][j] = 1;
            else
                pos[i][j] = 0;
        }
    }
    
    for (int ii = 0; ii < N / 2; ii ++) {
        for (int i = 0; i < N; i ++) {
            if (pos[ii][i] == 0)
                for (int j = 0; j < N; j ++)
                    pos[j][i] = !pos[j][i];
        }
    
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++)
                pos[j][i] = !pos[j][i];
        
            bool flag = true;
        
            for (int j = 0; j < N; j ++) {
                if (j == ii)
                    continue;
                
                for (int k = 1; k < N; k ++) {
                    if (pos[j][k] != pos[j][k - 1]) {
                        flag = false;
                        break;
                    }
                }
            
                if (!flag)
                    break;
            }
        
            if (flag) {
                fout << (ii + 1) << " " << (i + 1) << endl;
                return (0);
            }
        
            for (int j = 0; j < N; j ++)
                pos[j][i] = !pos[j][i];
        }    

        int iii = N - ii - 1;
        
        for (int i = 0; i < N; i ++) {
            if (pos[iii][i] == 0)
                for (int j = 0; j < N; j ++)
                    pos[j][i] = !pos[j][i];
        }
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++)
                pos[j][i] = !pos[j][i];
        
            bool flag = true;
        
            for (int j = 0; j < N; j ++) {
                if (j == iii)
                    continue;
                
                for (int k = 1; k < N; k ++) {
                    if (pos[j][k] != pos[j][k - 1]) {
                        flag = false;
                        break;
                    }
                }
            
                if (!flag)
                    break;
            }
        
            if (flag) {
                fout << (iii + 1) << " " << (i + 1) << endl;
                return (0);
            }
        
            for (int j = 0; j < N; j ++)
                pos[j][i] = !pos[j][i];
        }        
    }
    
    fout << "-1" << endl;
    return (0);
}