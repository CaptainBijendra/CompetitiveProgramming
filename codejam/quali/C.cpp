#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    long long T;
    cin >> T;

    vector<long long> ar;
    vector<long long> nxt;
    vector<long long> sorted;
    vector<long long> converted;
        
    for (long long i = 0; i < T; i ++) {
        long long N, P;
        cin >> N >> P;
        
        ar.clear();
        nxt.clear();
        sorted.clear();
        converted.clear();

        long long x;
        for (long long j = 0; j < P; j ++) {
            cin >> x;
            ar.push_back(x);
        }
        
        for (long long j = 0; j <= P; j ++) {
            nxt.push_back(1);
            sorted.push_back(1);
            converted.push_back(0);
        }
        
        long long chck = 0;
        
        nxt[1] = __gcd(ar[0], ar[1]);
        chck = (long long)(sqrt(ar[1]));
        
        if (chck * chck == ar[1])
            nxt[1] = chck;
        
        nxt[0] = ar[0] / nxt[1];

        sorted[0] = nxt[0];
        sorted[1] = nxt[1];
        
        for (long long j = 2; j <= P; j ++) {
            nxt[j] = ar[j - 1] / nxt[j - 1];
            sorted[j] = nxt[j];
        }
        
        sort(sorted.begin(), sorted.end());
        converted[0] = sorted[0];
        
        long long cnt = 1;
        
        for (long long j = 1; j <= P; j ++) {
            if (sorted[j] == sorted[j - 1])
                continue;
            
            converted[cnt] = sorted[j];
            cnt ++;
        }
        
        string str = "";
        
        for (long long j = 0; j <= P; j ++) {
            for (long long k = 0; k < 26; k ++) 
                if (converted[k] == nxt[j]) {
                    str += ('A' + k);
                    break;
                }
        }
        
        cout << "Case #" << (i + 1) << ": " << str << endl;
    }
}