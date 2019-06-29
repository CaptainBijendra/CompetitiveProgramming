#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <fstream>
#include <ctime>

using namespace std;

long long randNum(long long min, long long max)
{
   return rand() % max + min;
}

int main() {
    srand(time(NULL));
        
    string str;
    
    cout << "File input" << endl;
    cin >> str;
    
    string str1 = str + ".in"; 

    ofstream fout (str1.c_str());

    int N = 100000;
    long long cur = 10;

    fout << N << " " << randNum(2ll, 100000ll) << endl;
    
    for (int i = 1; i <= N; i ++) {
        if (i != 1)
            fout << " " << randNum(cur / 10ll, cur);
        else
            fout << randNum(cur / 10ll, cur);
    
        if ((i % 10) != 0)
            cur *= 10;
        else
            cur = 10;
    }

    fout << endl;
}