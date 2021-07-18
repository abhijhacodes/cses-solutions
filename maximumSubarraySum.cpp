#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i=0; i<n; ++i) cin>>v[i];

    ll curSum = v[0], ans = v[0];
    for(ll i=1; i<n; ++i){
        curSum = max(curSum+v[i], v[i]);
        ans = max(ans, curSum);
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}