#include <iostream>
#include <fstream>
#include <vector>

#define MOD 12345678910 

using namespace std;

vector<long long> stack;

int N, element;

int main() {
    ifstream fin ("paren.in");
    ofstream fout ("paren.out");
    
    fin >> N;

    long long nxt = 0ll;
    int in = -1; 

    for (int i = 0; i < N; i ++) {
        fin >> element;
        stack.push_back((element == 0 ? -1 : -2));

        in ++;
    
        if (in <= 0) { continue; }
        if (stack[in - 1] == -1 && stack[in] == -2) {
            stack.pop_back(); stack.pop_back();
            stack.push_back(1);
            
            in --;
        }

        else if ((in >= 2) && (stack[in - 2] == -1 && stack[in - 1] > 0 && stack[in] == -2)) {
            nxt = ((stack[in - 1] % MOD) * 2) % MOD;
            
            stack.pop_back(); stack.pop_back(); stack.pop_back();
            stack.push_back(nxt);

            in -= 2;
        }

        if ((in > 0) && stack[in] > 0 && stack[in - 1] > 0) {
            nxt = (stack[in - 1] % MOD) + (stack[in] % MOD);
            
            stack.pop_back(); stack.pop_back();
            stack.push_back(nxt);

            in --;
        }
    }
    
    fout << stack[0] << endl;
    return (0);
}


