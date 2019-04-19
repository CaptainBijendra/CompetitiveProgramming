#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_N 5005
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;
ii cow[MAX_N];

int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> cow[i].f >> cow[i].s;
    
    sort(cow, cow + N);
    
    int far_left = cow[0].s;
    int prev = 0;
    
    int with_milk = 0;
    int no_milk = 0;
    
    for (int i = 1; i < N; i ++) {
        if (cow[i].f <= far_left)
            far_left = max(far_left, cow[i].s);
        else {
            with_milk = max(with_milk, far_left - cow[prev].f);
            no_milk = max(no_milk, cow[i].f - far_left);
            far_left = cow[i].s;
            prev = i;
        }
    }
    
    with_milk = max(with_milk, far_left - cow[prev].f);
    
    cout << with_milk << " " << no_milk << endl;
    return (0);
}