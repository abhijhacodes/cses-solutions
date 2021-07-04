#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
   ll n; cin>>n;
   for(ll i=0; i<(1<<n); i++){
        ll a = i^(i>>1);
        bitset<32> b(a);
        string s = b.to_string();
        cout<<s.substr(32-n)<<endl;
   }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}