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

int A, B;

int main() {
    cin >> A >> B;
    
    if (B > A) {
        int tmp = B;
        B = A;
        A = tmp;
    }
    
    int answer = 0;
    
    for (int i = 1; i * i <= (A - B); i ++) {
        if ((A - B) % i == 0) {
            int factor1 = i; 
            int factor2 = ((A - B) / i);
            
            if (factor1 <= B)
                answer = max(answer, factor1);
            if (factor2 <= B)
                answer = max(answer, factor2);
        }
    }
    
    cout << answer << endl;
    return (0);    
}