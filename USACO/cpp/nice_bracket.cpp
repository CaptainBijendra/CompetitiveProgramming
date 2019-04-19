#include <iostream>
#include <fstream>
using namespace std;
string s;
int N;

int main()
{
    cin >> N;
    cin >> s;
    
    int ans = 0;
    int depth = 0;
    int closingSeen = 0; //since start of string
    int openingSeen = 0; //since last time with depth = 1
    
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            depth++;
            openingSeen++;
        }
        else
        {
            depth--;
            closingSeen++;
        }
        
        if(depth <= 1)
            openingSeen = 0;
        if(depth == -1)
        {
            ans = closingSeen;
            break;
        }
    }
    
    if(depth > 0)
        ans = openingSeen;
    
    cout << ans << "\n";
    return 0;
}