#pragma GCC optimize("Ofast") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h> 

#define MAX_N 1005
#define MAX_M 1005
#define f first
#define s second

using namespace std;
 
struct state {
    int x, y;  
    int moves;
};
 
queue<state> players[10], next_num[10];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int speed[10], ar[MAX_N][MAX_M], cnt[256];
int N, M, P;

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

int main() {
    cin >> N >> M >> P;
    
    for (int i = 0; i < P; i ++)
        cin >> speed[i];
    
    string str;
    for (int i = 0; i < N; i ++) {
        cin >> str;
        
        for (int j = 0; j < M; j ++) {
            ar[i][j] = str[j];
            
            if (ar[i][j] != '.' && ar[i][j] != '#') {
                state cur;
                cur.x = i;
                cur.y = j;
                cur.moves = 0;
            
                players[ar[i][j] - '1'].push(cur);        
                ar[i][j] = (ar[i][j] - '1' + 1);
            }
        }
    }
    
    while (true) {
        for (int i = 0; i < 10; i ++) {
            while (!players[i].empty()) {
                state cur = players[i].front();
                players[i].pop();
                
                if (cur.moves == speed[i]) {
                    next_num[i].push(cur);
                    continue;
                }
                
                for (int j = 0; j < 4; j ++) {
                    int nx = cur.x + dx[j];
                    int ny = cur.y + dy[j];
                    
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if (ar[nx][ny] == '.') {
                            state nxt = cur;
                            nxt.x = nx;
                            nxt.y = ny;
                            nxt.moves = cur.moves + 1;
                            
                            ar[nx][ny] = (i + 1);
                            players[i].push(nxt);
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < 10; i ++) {
            while (!next_num[i].empty()) {
                state cur = next_num[i].front();
                cur.moves = 0;
                
                next_num[i].pop();
                
                players[i].push(cur);
            }
        }    
        
        bool flag = true;
        
        for (int i = 0; i < 10; i ++) {
            if (!players[i].empty()) {
                flag = false;
                break;
            }
        }
        
        if (flag)
            break;
    /*
        cout << "________" << endl;
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j ++)
                cout << ar[i][j] << " ";
            
            cout << endl;
        }
    */
    
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++)
            cnt[ar[i][j]] ++;
    }
    
    for (int i = 1; i <= P; i ++)
        cout << cnt[i] << " ";
    
    cout << endl;
    return (0);
}