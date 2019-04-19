/*
ID: akommul1
LANG: C++
PROB: zerosum
*/
 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

#define MAX_N 10

using namespace std;

vector<string> sol;

int N;

int calc(string ops) {
    ops.erase(remove(ops.begin(), ops.end(), ' '), ops.end());

    string tmp = "";
    
    int sum = 0;
    int sign = 1;

    for (int i = 0; i < ops.size(); i ++) {
        if (ops[i] == '+') { 
            sum += (sign * stoi(tmp));
            sign = 1; tmp = "";
        }

        else if (ops[i] == '-') { 
            sum += (sign * stoi(tmp));
            sign = -1; tmp = ""; 
        }
        
        else { tmp += ops[i]; }
    }

    sum += (sign * stoi(tmp));

    return (sum);
}

void solve(int cur_num, string ops) {
    if (cur_num == N) {
        ops += (to_string(cur_num));
        
        if (!calc(ops)) { sol.push_back(ops); }
        
        return;
    }
 
    solve(cur_num + 1, ops + to_string(cur_num) + '+');
    solve(cur_num + 1, ops + to_string(cur_num) + '-');
    solve(cur_num + 1, ops + to_string(cur_num) + ' ');
}

int main() {
    ifstream fin ("zerosum.in");
    ofstream fout ("zerosum.out");

    fin >> N;

    solve(1, "");
    sort(sol.begin(), sol.end());

    for (int i = 0; i < sol.size(); i ++) 
    { fout << sol[i] << endl; }

    return (0);
}
