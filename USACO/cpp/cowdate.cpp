#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <string.h>
#include <math.h>

#define MAX_N 1000005
#define f first
#define s second

using namespace std;

long double cow[MAX_N];
long double prefix[MAX_N];

int N;

int main() {
    ifstream fin ("cowdate.in");
    ofstream fout ("cowdate.out");
    
    fin >> N;
    
    for (int i = 0; i < N; i ++) {
        fin >> cow[i];
        cow[i] /= 1000000.0;
    }
    
    long double ans = 0.0;
    
    for (int i = 0; i < N; i ++) {
        long double cur = cow[i];
        long double prev = 0.0;
        long double tau = (long double)(1.0 - cow[i]);
        
        ans = max(ans, cur);
        
        for (int j = i + 1; j < N; j ++) {
            cur = ((long double)cur * (long double)(1.0 - cow[j]));
            cur = cur + (long double)cow[j] * tau;
            
            if (cur < prev)
                break;
            
            tau = ((long double)tau * (long double)(1.0 - cow[j]));
            ans = max(ans, cur);
            prev = cur; 
        }
    }
 
    fout << (long long)(ans * 1000000) << endl;   
    return (0);
}