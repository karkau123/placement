#include<bits/stdc++.h>
using namespace std;
 int main()
{
 int n ;
 cin >> n;
 vector <int> arr (n);
 for (int i=0;i<n;i++)
 {
      cin >> arr[i];
 }
 int k ;
 cin >> k;
 while (k--)
 {
   int h ;
   cin >> h;
   sort (arr.begin() , arr.end());
   int ub = upper_bound(arr.begin() , arr.end() , h) - arr.begin();
   cout << arr.size()-ub;
 }

  return 0;
}
