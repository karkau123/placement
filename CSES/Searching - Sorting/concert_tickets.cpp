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
   int n, m;
    cin >> n >> m;
    vector<int> h(n), t(m);
    
 
    for (int i = 0; i < n; i++) cin >> h[i];
    
 
    for (int i = 0; i < m; i++) cin >> t[i];
 
   
    multiset<int> tickets(h.begin(), h.end());
    
    for (int i = 0; i < m; i++) {
        auto it = tickets.upper_bound(t[i]);   // this will pass all cases 
        
        // auto it = upper_bound (tickets.begin() , tickets.end() , t[i]);     -> this gives tle
        if (it == tickets.begin()) {
            cout << -1 << endl;  
        } else {
            it--;  
            cout << *it << endl;
            tickets.erase(it);  
        }
    }
 
    return 0;
}

 