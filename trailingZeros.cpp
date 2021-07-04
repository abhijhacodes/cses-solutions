#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    ll res = 0;
    for(ll i=5; i<=n; i=i*5)
    {
        res += (n / i);
    }
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}