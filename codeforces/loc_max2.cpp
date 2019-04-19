#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <set>
#include <cassert>
#include <deque>
using namespace std;
#define INF 2001001001
#define MOD 998244353
#define endl '\n'
typedef long long ll;

int N,arr[100001];
ll dp[100001][201][2];

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>N;
  for (int i=1;i<=N;i++)
    cin>>arr[i];
  for (int i=1;i<=N;i++){
    if (arr[i]!=-1){
      if (i==1)
	dp[i][arr[i]][0]=1;
      else{
	for (int j=1;j<arr[i];j++){
	  dp[i][arr[i]][0]+=dp[i-1][j][0]+dp[i-1][j][1];
	  dp[i][arr[i]][0]%=MOD;
	}
	dp[i][arr[i]][1]+=dp[i-1][arr[i]][0];
	dp[i][arr[i]][1]%=MOD;
	for (int j=arr[i];j<=200;j++){
	  dp[i][arr[i]][1]+=dp[i-1][j][1];
	  dp[i][arr[i]][1]%=MOD;
	}
      }
    }
    else{
      if (i==1){
	for (int j=1;j<=200;j++)
	  dp[i][j][0]=1;
      }
      else{
	ll temp=0;
	//comes from bad
	for (int j=1;j<=200;j++){
	  dp[i][j][1]+=dp[i-1][j][0];
	  dp[i][j][1]%=MOD;
	  dp[i][j][0]+=temp;
	  dp[i][j][0]%=MOD;
	  temp+=dp[i-1][j][0];
	  temp%=MOD;
	}
	//comes from good
	temp=0;
	for (int j=200;j>=1;j--){
	  temp+=dp[i-1][j][1];
	  temp%=MOD;
	  dp[i][j][1]+=temp;
	  dp[i][j][1]%=MOD;
	}
	temp=0;
	for (int j=1;j<=200;j++){
	  dp[i][j][0]+=temp;
	  dp[i][j][0]%=MOD;
	  temp+=dp[i-1][j][1];
	  temp%=MOD;
	}
      }
    }
  }
  ll ans=0;
  for (int i=1;i<=200;i++)
    ans=(ans+dp[N][i][1])%MOD;
  cout<<ans<<endl;
  return 0;
}