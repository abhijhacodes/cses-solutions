#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    ll n;
    cin >> n;
    if(n==1) cout<<1;
    else if(n==3 or n==2) cout<<"NO SOLUTION";
    else{
        if(n%2==0){
            for(ll i=n-1; i>=1; i-=2)
                cout<<i<<" ";
            for(ll j=n; j>=2; j-=2)
                cout<<j<<" ";
        }
        else{
            for(ll i=n-1; i>=2; i-=2)
                cout<<i<<" ";
            for(ll j=n; j>=1; j-=2)
                cout<<j<<" ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}