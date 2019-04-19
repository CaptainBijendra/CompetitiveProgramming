#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int DP[255], pDP[255];
int N;

int main() {
    cin >> N;

    string str;

    bool all_same = false;
    int pre, suf;

    for (int i = 0; i < N; i ++) {
        cin >> str;
        all_same = false;

        for (pre = 1; pre < str.size() && str[pre] == str[pre - 1]; pre ++);
        for (suf = str.size() - 2; suf >= 0 && str[suf] == str[suf + 1]; suf --);
        
        suf = str.size() - suf - 1;

        if (pre + suf > str.size() || str.size() == 1) {
            all_same = true;
        }

        int streak = 1;

        for (int j = 1; j < str.size(); j ++) {
            if (str[j] != str[j - 1]) {
                DP[str[j - 1]] = max(DP[str[j - 1]], streak);
                streak = 1;
            }

            else
                streak ++;
        }
        
        DP[str[str.size() - 1]] = max(DP[str[str.size() - 1]], streak);

        if (i > 0) {
            if (str.size() == 1)
                DP[str[0]] = max(DP[str[0]], pDP[str[0]] * 2 + 1);
            
            else {
                if (all_same && pDP[str[0]]) {
                    DP[str[0]] = max(DP[str[0]], (int)str.size() * (pDP[str[0]] + 1) + pDP[str[0]]);
                }   

                else {
                    if (str[0] == str[str.size() - 1] && pDP[str[0]]) {
                        DP[str[0]] = max(DP[str[0]], 1 + pre + suf);
                    }

                    else {
                        if (pDP[str[0]]) {
                            DP[str[0]] = max(DP[str[0]], pre + 1);
                        }

                        if (pDP[str[str.size() - 1]]) {
                            DP[str[str.size() - 1]] = max(DP[str[str.size() - 1]], suf + 1);
                        }
                    }
                }
            }
        }
        
        for (int j = 0; j < 255; j ++) {
            if (DP[j]) {
                pDP[j] = DP[j];
                DP[j] = 1;
            }
            
            else {
                pDP[j] = 0;
            }
        }
        
        

        //Cases:
        //If they are all the same
        //  Then multiply the length of this by the maximum length of a certain character
        //Otherwise
        //  Calculate the number of same of both prefix and suffix
        //  Check whether that character exists or not
    }
        
    int answer = 1;

    for (int i = 0; i < 255; i ++)
        answer = max(answer, pDP[i]);

    cout << min(1000000000, answer) << endl;
    return (0);
}