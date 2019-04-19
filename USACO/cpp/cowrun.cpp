#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <queue>
#include <math.h>
#include <cstdlib>

using namespace std;

string str;

char ans[15];

long long ar[15][8];
long long N, M, K;

bool call_OR(long long depth, long long sum);

bool call_AND(long long a, long long depth, long long sum) {
    //Left Side = top
    bool an = call_OR(depth + 1, (sum + (sum * ar[depth / 2][4 * a + 2]) + ar[depth / 2][4 * a + 3]) % M);

    if (!an)
        return (false);
    
    //Right Side = bottom
    return (call_OR(depth + 1, (sum + (sum * ar[depth / 2][4 * a]) + ar[depth / 2][4 * a + 1]) % M));
}

bool call_OR(long long depth, long long sum) {
    if (depth == 2 * N) {
        return ((sum % M) <= K || (M - K <= (sum % M)));
    }    
    
    int x = (rand() % 2);
    bool a = call_AND(x, depth + 1, sum);
    
    if (a)
        return (true);    
    
    return (call_AND((x + 1) % 2, depth + 1, sum));
}

int main() {
    cin >> N >> M >> K;
    cin >> str;
    
    for (long long i = 0; i < N; i ++) 
        for (long long j = 0; j < 8; j ++) {
            cin >> ar[i][j];
            ar[i][j] %= M;
        }
        
    long long cur_sum = 0;
    for (long long i = 0; i < N; i ++) {
        if (call_AND(1, i * 2 + 1, cur_sum)) {
            cout << "B";
            
            if (str[i] == 'B')
                cur_sum = (cur_sum + (cur_sum * ar[i][6] + ar[i][7]) % M) % M;
            else
                cur_sum = (cur_sum + (cur_sum * ar[i][4] + ar[i][5]) % M) % M;
        }
        
        else {
            cout << "T";
            
            if (str[i] == 'B')
                cur_sum = (cur_sum + (cur_sum * ar[i][2] + ar[i][3]) % M) % M;
            else
                cur_sum = (cur_sum + (cur_sum * ar[i][0] + ar[i][1]) % M) % M;
        }
    }
    
    cout << endl;
    return (0);
}