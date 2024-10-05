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
  ll n , m , k;
  cin >> n >>m >>k ;
  vll a (n) , b(m);
  lp (i , 0 , n ) cin >> a[i];    // n people   i  
  lp (i , 0 ,m) cin >> b[i];      // m apartments  j 
  ll cnt = 0;
  ll i =0 , j =0 ;
  sort (a.begin() , a.end());
  sort (b.begin() , b.end());
  while (j < m && i < n)
  {
    if (abs(a[i] - b[j]) <= k) {
			++i;
			++j;
			++cnt;
		}
      else
      { 
          // apatment chota hai
          if (a[i]-b[j] > k)
          {
              // search next bigger apartment
                j++;
          }
          else {
            i++;
          }
      }
  }
  cout << cnt << endl;
  return 0;
}
