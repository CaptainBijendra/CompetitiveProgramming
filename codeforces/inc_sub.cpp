#include <iostream>
#include <algorithm>

#define MAX_N 200005
#define f first
#define s second

using namespace std;

int ar[MAX_N];
int N;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i ++)
        cin >> ar[i];
    
    bool flag = false;
    
    int l = 0;
    int r = N - 1;
    int prev = -1;
    
    string ans = "";
    
    while (l <= r) {
        if (l == r) {
            if (ar[l] > prev) {
                ans += 'L';
                prev = ar[l];
            }
            
            break;
        }
        
        if (ar[l] < ar[r]) {
            if (ar[l] > prev) {
                l ++;
                ans += 'L';
                prev = ar[l - 1];
            } else if (ar[r] > prev) {
                r --;
                ans += 'R';
                prev = ar[r + 1];
            } else {
                break;
            }
        } 
        
        else if (ar[r] < ar[l]) {
            if (ar[r] > prev) {
                r --;
                ans += 'R';
                prev = ar[r + 1];
            } else if (ar[l] > prev) {
                l ++;
                ans += 'L';
                prev = ar[l - 1];
            } else {
                break;
            }
        }
        
        else {
            if (ar[l] > prev)
                flag = true;
            
            break;
        }
    }
    
    if (ar[l] == ar[r] && flag) {
        int pos1 = 1, pos2 = 1;
        int tmp = l;
        
        string p1 = "L";
        string p2 = "R";
        
        while (l < r && ar[l + 1] > ar[l]) {
            l ++;
            pos1 ++;
            p1 += 'L';
        } 
        
        l = tmp;
        
        while (r > l && ar[r - 1] > ar[r]) {
            r --;
            pos2 ++;
            p2 += 'R';
        }
        
        if (pos1 > pos2)
            ans += p1;
        else
            ans += p2;
    }
    
    cout << ans.size() << endl;
    cout << ans << endl;
    return (0);
}