#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_N 305
#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

vector<ii> con[MAX_N];
vector<ii> con2[MAX_N];

int dist[MAX_N][MAX_N], dist2[MAX_N][MAX_N], DP[MAX_N][MAX_N], ar[MAX_N];
int A, B, N;

int main() {
    cin >> N >> A;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (i == j) { continue; }

            dist[i][j] = 1000000005;
            dist2[i][j] = 1000000005;
        }
    }
    
    int a, b, c;
    for (int i = 0; i < A; i ++) {
        cin >> a >> b >> c; a++; b ++;
        con[a - 1].push_back(ii(b - 1, c));
        con[b - 1].push_back(ii(a - 1, c));
        
        dist[a - 1][b - 1] = c;
        dist[b - 1][a - 1] = c;
    }
    
    cin >> B;
    
    for (int i = 0; i < B; i ++) {
        cin >> a >> b >> c; a ++; b ++;
        con2[a - 1].push_back(ii(b - 1, c));
        con2[b - 1].push_back(ii(a - 1, c));
        
        dist2[a - 1][b - 1] = c;
        dist2[b - 1][a - 1] = c;
    }
    
    for (int k = 0; k < N; k ++) 
        for (int i = 0; i < N; i ++) 
            for (int j = 0; j < N; j ++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j];   
                        
                if (dist2[i][k] + dist2[k][j] < dist2[i][j])
                    dist2[i][j] = dist2[i][k] + dist2[k][j];
            }
    
    int Z;
    cin >> Z;
    
    for (int i = 0; i < Z; i ++)
        cin >> ar[i];
    
    for (int i = 0; i < Z; i ++) 
        for (int k = 0; k < N; k ++) 
            DP[i][k] = 1000000005;
    
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            DP[0][j] = dist[0][j] + dist2[j][ar[0]];
    
    for (int i = 0; i < Z; i ++) { //What index are we at
        for (int k = 0; k < N; k ++) { //What index is our bike at
            //We don't have our bike, want to get bike, and then go to next index
            DP[i + 1][ar[i + 1]] = min(DP[i + 1][ar[i + 1]], DP[i][k] + dist2[ar[i]][k] + dist[k][ar[i + 1]]);
            
            //We don't have bike, we don't WANT our bike, and go to next index
            DP[i + 1][k] = min(DP[i + 1][k], DP[i][k] + dist2[ar[i]][ar[i + 1]]);
                
            //We have bike, we want to ditch bike, and then go to next index
            DP[i + 1][ar[i]] = min(DP[i + 1][ar[i]], DP[i][ar[i]] + dist2[ar[i]][ar[i + 1]]);
                
            //We have bike, we want to KEEP bike, and then go to next index
            DP[i + 1][ar[i + 1]] = min(DP[i + 1][ar[i + 1]], DP[i][ar[i]] + dist[ar[i]][ar[i + 1]]);
            
            //We have the bike, we want to put the bike somewhere, and then walk to the next place
            for (int l = 0; l < N; l ++) {
                DP[i + 1][l] = min(DP[i + 1][l], DP[i][ar[i]] + dist[ar[i]][l] + dist2[l][ar[i + 1]]);
            }
        }
        
        for (int k = 0; k < N; k ++) { 
            for (int l = 0; l < N; l ++) {
                DP[i + 1][l] = min(DP[i + 1][l], DP[i][k] + dist2[ar[i]][k] + dist[k][l] + dist2[l][ar[i + 1]]);
            }
        }
    }
    
    int ans = DP[Z - 1][ar[Z - 1]] + dist[Z - 1][0];
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            ans = min(ans, DP[Z - 1][j] + dist2[i][j] + dist[j][0]);
        }
    }
    
    cout << ans << endl;
    return (0);
}   