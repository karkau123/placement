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
int findmed(vll a , int n )
{
    ll mid = n/2;
    if (n%2 == 1)  
    {
         return a[mid];  
    }
    return ((a[mid]+a[mid-1])/2);
}
 int main()
{
  ll n ;
  cin >> n;
  vll a (n);
  lp (i , 0 , n) cin >> a[i];
  sort (a.begin() , a.end());
  int med = findmed(a , n);
  ll sum = 0;
  lp (i , 0 , n)
  {
     sum += abs (a[i] - med);
  }
  cout  << sum << endl;
  return 0;
}
