#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

typedef pair<long long, long long> ii;

vector<ii> event;

long long cnt[MAX_N];
long long N;

int main() {
    cin >> N;
    
    long long a, b;
    for (long long i = 0; i < N; i ++) {
        cin >> a >> b;
    
        event.push_back(ii(a, 1));
        event.push_back(ii(b + 1, 2));
    }
    
    sort(event.begin(), event.end());
    
    long long depth = 0;
    for (long long i = 0; i < event.size(); i ++) {
        if (event[i].s == 1)
            depth ++;
        else
            depth --;
        
        cnt[depth] += event[i + 1].f - event[i].f;
    }
    
    for (long long i = 1; i <= N; i ++)
        cout << cnt[i] << " ";
    
    cout << endl;
    return (0);
}