#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <math.h>
#include <vector>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

/*
CHECK THE FOLLOWING BEFORE SUBMITTING:
REMEMBER LONG LONG
LOOK AT ARRAY SIZE
IF NOTHING WORKS, TRY:
- BINARY SEARCH
- DYNAMIC PROGRAMMING
- GREEDY
*/

long long ar[MAX_N];
long long N, M;

bool pos(long long days) {
    long long sum = 0;
    long long max_pages = 0;
    long long sub = 0, sub_c = 0;
    
    for (long long i = 0; i < N; i ++) {
        sum += ar[i];
        max_pages = max(max_pages, sum - sub);    

        if ((i + 1) % days == 0)
            sub_c ++;
            
        sub += sub_c;
    }
    
    return (max_pages >= M);
}

int main() {
    cin >> N >> M;
    
    for (long long i = 0; i < N; i ++)
        cin >> ar[i];
    
    sort(ar, ar + N);
    reverse(ar, ar + N);

    long long low = 1;
    long long hi = 1000000009;
    
    while (low < hi) {
        long long mid = (low + hi) / 2;
        
        if (pos(mid))
            hi = mid;
        else
            low = mid + 1;
    } 
    
    cout << (low >= 1000000000 ? -1 : low) << endl;
    return (0);
}