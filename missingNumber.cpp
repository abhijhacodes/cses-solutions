#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    ll n; cin>>n;
    ll cur_sum = 0;
    for(ll i=0; i<n-1; i++){
        ll a; cin>>a;
        cur_sum += a;
    }
    ll acc_sum = (n*(n+1))/2;
    cout<<(acc_sum-cur_sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}