#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

int main() {
    ifstream fin ("sleepy.in");
    ofstream fout ("sleepy.out");
    
    fin >> N;
    
    for (int i = 0; i < N; i ++)
        fin >> ar[i];
    
    int lft = -1;
    
    for (int i = N - 2; i >= 0; i --) {
        if (ar[i] > ar[i + 1]) {
            lft = i;
            break;
        }
    }
    
    if (lft == -1) {
        fout << "0" << endl;
        return (0);
    }
    
    fout << (lft + 1) << endl;
    return (0);
}