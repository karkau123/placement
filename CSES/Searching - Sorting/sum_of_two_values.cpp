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
    vpll p(n);
    lp (i , 0 , n) p[i] = {a[i] , i};
    sort (p.begin() , p.end());
    ll sum = 0;
    int i = 0;
    int j = n-1;
    pair <int , int> ans={-1 , -1};
    while (i < j)
    {
          sum =  p[i].ff + p[j].ff ;
          if (sum == x)
          {
            ans = {p[i].ss+1 , p[j].ss+1};
            break;
          }
          else if (sum > x)
          {
             j--;
          }
          else
          {
            i++;
          }
    }
  if (ans.ff == -1 && ans.ss == -1) cout << "IMPOSSIBLE" << endl;
  else 
  cout << ans.ff << " " << ans.ss << endl;
   return 0;
}
