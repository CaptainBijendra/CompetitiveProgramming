#include <iostream>
#include <fstream>

#define MAX_N 100005

using namespace std;

class BIT {
    public:
        int tree[MAX_N];

        BIT(int sz) {
            for (int i = 0; i < sz; i ++) 
            { tree[i] = 0; }
        }
    
        int query(int index) {
            int sum = 0;
            
            index ++;
            
            while (index > 0) {
                sum += tree[index];
                index -= (index & (-index));
            }
        
            return (sum);
        }
        
        void update(int index, int val) {
            index ++;
            
            while (index < MAX_N) {
                tree[index] += val;
                index += (index & (-index));
            }
        }
};

int ar[MAX_N];
int N;

int main() {
    ifstream fin ("GSS4.in");
    ofstream fout ("GSS4.out");
    
    fin >> N;
    for (int i = 0; i < N; i ++) { fin >> ar[i]; }
    
    BIT sol(MAX_N);

    for (int i = 0; i < N; i ++) { sol.update(i, (i + 1)); }
    for (int i = 0; i < N; i ++) {
        cout << "INDEX " << i << ": " << sol.query(i) << endl;
    }
    
    return (0);
}