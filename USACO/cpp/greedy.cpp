#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

#define INF 2000000009
#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N], num[MAX_N];
int N;

bool pos(int loc) { 
    vector<int> a;
    
    for (int i = 0; i < loc; i ++)
        a.push_back(ar[i]);
    
    sort(a.begin(), a.end());
    
    int tmp = loc;
    
    for (int i = a.size() - 1; i >= 0; i --) {
        if (a[i] >= tmp)
            tmp --;
        else
            return (true);
    }
        
    return (false);
}

int main() {
    ifstream fin ("greedy.in");
    ofstream fout ("greedy.out");
    
    fin >> N;
    
    for (int i = 0; i < N; i ++) {
        fin >> ar[i];
        ar[i] = (N - 1 - ar[i]);
    }    
    
    int low = 0;
    int hi = N - 1;
    
    while (low < hi) {
        int mid = (low + hi) / 2;
        
        if (pos(mid))
            hi = mid;
        else
            low = mid + 1;
    }

    fout << (N - low) << endl;
    return (0);
}
