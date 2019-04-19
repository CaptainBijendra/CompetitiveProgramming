#include <iostream>
#include <map>

using namespace std;

map<string, int> cnt;

int N, M, Q;

int main() {
    cin >> N >> M >> Q;
    
    string str;
    
    for (int i = 0; i < N; i ++)
        cin >> str;
    
    bool flag = false;
    int val;
    for (int i = 0; i < Q; i ++) {
        cin >> str >> val;
        
        bool print = true;
        if (cnt[str] >= M)
            print = false;
            
        cnt[str] += val;
        
        if (cnt[str] >= M && print) {
            cout << str << " wins!" << endl;
            flag = true;
        }        
    }

    if (!flag)
        cout << "No winner!" << endl;
}