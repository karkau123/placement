#include<bits/stdc++.h>
#define ll long long int
#define lp(i,a,b) for(ll i=a;i<b;i++)
#define lpa(i,a,b,x) for(ll i=a;i<b;i+=x)
#define pl(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ms(a,x) memset(a,x,sizeof(a))
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vll vector<ll>
#define vvll vector<vll>
#define ff first
#define ss second
using namespace std;
 int main()
{
  ll n , x;
  cin >> n >> x;
  vll a (n);
  lp (i , 0 , n) cin >> a[i];
  sort (a.begin() , a.end());
  int i=0 ;
  int j = n-1;
  ll cnt = 0;
  while (i<=j)
  {
     if (i == j)
     {
        if (a[i] <=x)  cnt++;
       break;
     }
     if (a[i] + a[j] <= x)
     {
        cnt++;
        i++;
        j--;
     }
     else if (a[i]+a[j] > x)
     {
          cnt++;
          j--;
     }
  }
  cout << cnt << endl;
  return 0;
}
