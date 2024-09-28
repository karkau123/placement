#include<bits/stdc++.h>
using namespace std;
 int main()
{
    string s ;
    cin >> s;
    int n = s.length();
    int d = 0;
    int c = 0;
    for (int i=0;i<n;i++)
    {
          if (isdigit(s[i]))
          {
              d++;
          }
          if (isalpha(s[i]))
          {
            c++;
          }
    }
    cout << d << endl;
    cout << c << endl; 
  return 0;
}
