#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>
#include <fstream>
#include <ctime>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

long long randNum(long long min, long long max)
{
   return rand() % max + min;
}

set<int> leaves;

int ar[MAX_N], cnt[MAX_N];
int N;

int main() {
    srand(time(NULL));
        
    string str;
    
    cout << "File input" << endl;
    cin >> str;
    
    string str1 = str + ".in"; 

    ofstream fout (str1.c_str());
    N = MAX_N;
    
    ar[0] = 1;
    ar[1] = 2;
    //Completely random prufer code
    for (int i = 2; i < N - 2; i ++) {
        ar[i] = randNum(1ll, N);
    }
    
    vector<ii> edges;
    
    for (int i = 0; i < N - 2; i ++)
        cnt[ar[i]] ++;
    
    for (int i = 1; i <= N; i ++)
        if (!cnt[i]) { leaves.insert(i); }

    for (int i = 0; i < N - 2; i ++) {
        int a = ar[i];
        int b = *leaves.begin();
    
        edges.push_back(ii(a, b));
    
        leaves.erase(b);
        cnt[a] --;
        
        if (cnt[a] == 0)
            leaves.insert(a);
    }
    
    fout << N << endl;
    for (int i = 0; i < edges.size(); i ++) {
        int ord = randNum(1ll, 2ll);
        
        if (ord == 1ll)
            fout << edges[i].f << " " << edges[i].s << endl;
        else
            fout << edges[i].s << " " << edges[i].f << endl;
    }
    
    return (0);
}