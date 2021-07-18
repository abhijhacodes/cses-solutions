#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
   ll n,q;
   cin >> n >> q;
   vector<ll> x(n+1);
   for(ll i=1; i<=n; i++) cin >> x[i];

   vector<ll> prefix(n+1);
   prefix[1] = x[1];
   for(ll i=2; i<=n; i++){
        prefix[i] = prefix[i-1] + x[i];
   }
   
   while(q--){
        ll a,b;
        cin >> a >> b;
        cout << (prefix[b]-prefix[a-1]) <<"\n";
   }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}