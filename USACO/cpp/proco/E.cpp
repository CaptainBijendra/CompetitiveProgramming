#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>

#define MAX_N 
#define f first
#define s second

using namespace std;

priority_queue<int> pq;

int N, M;

int main() {
    cin >> N >> M;
    
    int x;
    for (int i = 0; i < N; i ++) {
        cin >> x;
        pq.push(x);
    }
    
    int ops = 0;
    int sum = 0;
    
    while (ops != M) {
        int cur = pq.top();
        pq.pop();
        
        pq.push(sqrt(cur));
        ops ++;
    }
    
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    
    cout << sum << endl;
    return (0);    
}