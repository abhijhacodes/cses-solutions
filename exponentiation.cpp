#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

ll power(ll a, ll b)
{
    if(b == 0) return 1;
 
    a = a % mod;
    ll temp = power(a, b/2);
    if(b&1)
        return (((temp * temp) % mod) * a) % mod;
    else
        return (temp * temp) % mod;
}

void solve()
{
    ll n; cin>>n;
    while(n--)
    {
        ll a,b;
        cin >> a >> b;
        cout << power(a,b) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}