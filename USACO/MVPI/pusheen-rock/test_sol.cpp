#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <math.h>

#define MAX_N 100005
#define f first
#define s second

using namespace std;

long long rock[MAX_N];

unordered_map<long long, long long> cnt[11];

int N, X;

int main() {
    string str;
    
    cout << "File input" << endl;
    cin >> str;
    
    string str1 = str + ".in"; 
    string str2 = str + ".out";
    
    ifstream fin (str1.c_str());
    ofstream fout (str2.c_str());
    
    fin >> N >> X;
    
    for (int i = 0; i < N; i ++)
        fin >> rock[i];

    for (int i = 0; i < N; i ++) {
        long long mult = 1ll;
        
        for (int j = 1; j <= 10; j ++) {
            mult *= 10ll;
            cnt[j][(((mult % X) * (rock[i] % X)) % X)] ++;
        }
    }

    long long ans = 0ll;

    for (int i = 0; i < N; i ++) {
        int numDigits = floor(log10(rock[i]) + 1); //Number of digits in the number rock[j]
        ans += cnt[numDigits][(X - (rock[i] % X)) % X];
    }
    
    for (int i = 0; i < N; i ++) {
        int numDigits = floor(log10(rock[i]) + 1); //Number of digits in the number rock[j]

        long long resultingNumber = (((((long long)pow(10, numDigits)) % X) * (rock[i] % X)) % X) + (rock[i] % X);
            
        if (resultingNumber % X == 0)
            ans --;
    }
    
    fout << ans << endl;
    return (0);
}