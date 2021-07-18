#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
   ll n,m,k;
   cin >> n >> m >> k;
   vector<ll> a(n), b(m);
   for(ll i=0; i<n; i++) cin >> a[i];
   for(ll i=0; i<m; i++) cin >> b[i];
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
 
   ll cnt = 0, i = 0, j = 0;
   
   while(i<n and j<m){
          if(abs(a[i]-b[j]) <= k){
               cnt++;
               i++; j++;
          }
          else{
               if(a[i]-b[j] > k) j++;
               else i++;
          }
   }
   cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}