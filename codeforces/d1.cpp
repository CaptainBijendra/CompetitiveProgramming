#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

int main() {
    cin >> N;
    
    int big = 0;
    for (int i = 0; i < N; i ++) {
        cin >> ar[i];
        big = max(big, ar[i]);
    }
    
    for (int i = 0; i < N; i ++) 
        ar[i] += 2 * ((big - ar[i]) / 2);
    
    int streak = 1;
    
    for (int i = 0; i < N - 1; i ++) {
        if (ar[i] == ar[i + 1])
            streak ++;
        else {
            for (int j = i - streak; j < )
            
            strek = 1;
        }
    }
    
    cout << "YES" << endl;
    return (0);
}