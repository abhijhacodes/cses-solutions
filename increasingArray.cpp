#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];
    ll ans = 0;
    for (ll i = 0; i < n; ++i)
    {
        if(a[i] > a[i+1]){
            ans += abs(a[i] - a[i+1]);
            a[i+1] = a[i];
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}