#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

int main() {
    ifstream fin ("lemonade.in");
    ofstream fout ("lemonade.out");
    
    fin >> N;
    
    for (int i = 0; i < N; i ++)
        fin >> ar[i];

    sort(ar, ar + N);
    reverse(ar, ar + N);
    
    int ans = N;
    
    for (int i = 0; i < N; i ++)
        if (ar[i] < i)
            ans --;

    fout << ans << endl;
    return (0);
}