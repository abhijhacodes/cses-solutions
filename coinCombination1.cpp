#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    ll n,x; 
    cin >> n >> x;
    vector<ll> coins(n);
    for(ll i=0; i<n; i++) cin >> coins[i];

    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for(ll i=1; i<=x; i++)
    {
        for(ll coin: coins)
        {
            if(coin <= i)
                dp[i] = (dp[i] + dp[i-coin])%mod;
        }
    }
    cout << dp[x]%mod;
   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}