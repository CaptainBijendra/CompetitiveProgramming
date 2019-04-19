#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <deque>
#include <cassert>
#include <ctime>
#include <cstring>
using namespace std;
#define INF 2001001001
#define MOD 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;

ll oddsum(ll terms){
  terms%=MOD;
  return (terms*terms)%MOD;
}

ll evensum(ll terms){
  ll terms2=terms*2;
  terms2%=MOD;
  return ((terms2*(terms2+1))/2)%MOD-oddsum(terms);
}

ll solve(ll ind){
  ll even=0,odd=0;
  ll cur=1,cnt=1,sum=0;
  while (sum+cur<=ind){
    if (cnt%2==1)
      odd+=cur;
    else
      even+=cur;
    sum+=cur;
    cur*=2;
    cnt++;
  }
  if (cnt%2==1)
    odd+=ind-sum;
  else
    even+=ind-sum;
  //cout<<odd<<' '<<even<<endl;
  return evensum(even)+oddsum(odd);
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  ll L,R;
  cin>>L>>R;
  if (R==1){
    cout<<1<<endl;
    return 0;
  }
  cout<<solve(573300466228828028) << endl;
  if (L==1)
    cout<<(solve(R)+MOD)%MOD<<endl;
  else
    cout<<(solve(R)-solve(L-1)+MOD)%MOD<<endl;
  return 0;
}