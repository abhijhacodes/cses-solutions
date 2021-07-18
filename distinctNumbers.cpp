#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    ll n; cin >> n;
    set<ll> s;
    for (ll i = 0; i < n; ++i)
    {
        ll x; cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}