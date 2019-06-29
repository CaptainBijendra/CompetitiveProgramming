#include <iostream>
#include <vector>

using namespace std;

int main() {
    for (int i = 131000; i < 1310100; i ++) {
        long long ans = 8590000128;
        
        vector<long long> stck;
        stck.push_back(i);
        
        while (true) {
            stck.push_back(stck[stck.size() - 1]);
            stck.push_back(1);
            long long a = stck[stck.size() - 1]; stck.pop_back();
            long long b = stck[stck.size() - 1]; stck.pop_back();
            stck.push_back(b - a);
            
            if (stck[stck.size() - 1] == 0)
                break;
        }
        
        while (true) {
            stck.push_back(stck.size());
            stck.push_back(1);
            long long a = stck[stck.size() - 1]; stck.pop_back();
            long long b = stck[stck.size() - 1]; stck.pop_back();
            stck.push_back(b - a);
        
            if (stck[stck.size() - 1] == 0)
                break;
        
            stck.pop_back();
            a = stck[stck.size() - 1]; stck.pop_back();
            b = stck[stck.size() - 1]; stck.pop_back();
            stck.push_back(a + b);
        }
        
        stck.pop_back();
        
        if (stck[0] == ans) {
            cout << i << endl;
            break;
        }
    }
}