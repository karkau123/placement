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
  ll n;
  cin >> n;
  vll arr (n) , dep(n);
  lp (i , 0 , n)
  {
     ll a , b;
     cin >> a >> b;
     arr[i] = a;
     dep[i] = b;
  }
  int i = 0 , j = 0;
  int cc = 0; 
  int maxi = 0;
  sort (arr.begin() , arr.end());
  sort (dep.begin() , dep.end());
  while (i < n && j < n)
  {
     if (arr[i] < dep[j])
     {
       cc++;
       maxi =  max (maxi , cc);
       i++;
     }
     else
     {
        cc--;
        j++;
     }
     
  }
  cout << maxi << endl;

  
  return 0;
}
