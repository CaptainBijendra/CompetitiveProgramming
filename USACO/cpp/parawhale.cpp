#include <iostream>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

long long p[MAX_N];
int N;

int main() {
    p[0] = 1;
    for (int i = 1; i < 50; i ++)
        p[i] = p[i - 1] * 2;
        
    cin >> N;
    
    long long a;
    for (int i = 0; i < N; i ++) {
        cin >> a;
        
        for (int i = log2(a) + 1; i < 50; i ++) {
            if (p[i] >= a) {
                cout << p[i] - a << endl;
                break; 
            }
        }
    }
    
    return (0);
}   