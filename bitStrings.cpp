#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007
 
ll exponent(ll x, unsigned int y){
    ll res = 1; 
    x = x%mod;
    while(y>0){
        if (y&1) res = (res*x)%mod; 
        y = y>>1; 
        x = (x*x)%mod;
    }
    return res;
}

void solve()
{
    ll n;
    cin>>n;
    cout<<exponent(2,n);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}