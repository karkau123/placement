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
  int t;
  cin >> t;
  while (t--)
  {
      int n ;
      cin >> n;
      string s = "aeiou";
      string ans;
      if (n == 1)  cout << "a" << endl;
      else if (n == 2)  cout << "ae" << endl;
      else if (n == 3)  cout << "aei" << endl;
      else if (n == 4)  cout << "aeio" << endl;
      else if (n == 5)  cout << "aeiou" << endl;
      else
      {
           int left = n;
           int x = n / 5;
           int y = n % 5;
           for (int i=0 ; i < 5 ; i++)
           {
                 for (int j=0 ; j< x ; j++) ans = ans + s[i];
                if (y > 0)  ans += s[i];
                y--;
           }
  


           

      }

  cout << ans << endl;

  }
  return 0;
}
