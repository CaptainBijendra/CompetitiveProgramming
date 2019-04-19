#include <bits/stdc++.h>

#define MAX_N 100005
#define f first
#define s second
 
using namespace std;
 
bool cmp(int a, int b) {
    //Since we're sorting in descending order, we want to prioritize a 
    //over b if (a < b)
    
    if (a < b)
        return (true);
    else
        return (false);
}

int A[MAX_N], B[MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> A[i];
    
    for (int j = 0; j < N; j ++)
        cin >> B[j];
        
    sort(A, A + N, cmp);
    sort(B, B + N, cmp);
    
    int index_A = N - 1;
    int index_B = N - 1;
    
    //This is to prevent Overflow
    long long score_A = 0;
    long long score_B = 0;
    
    bool turn = true;
    
    while (index_A >= 0 || index_B >= 0) {
        if (index_B < 0 || A[index_A] > B[index_B]) {
            //If it's A's turn
            if (turn) {
                score_A += A[index_A];
                index_A --;
            }
            
            else {
                index_A --;
            }
        }
        
        else {
            if (turn) {
                index_B --;
            }
            
            else {
                score_B += B[index_B];
                index_B --;
            }
        }
        
        turn = !turn;
    }
    
    cout << (score_A - score_B) << endl;
    return (0);
}