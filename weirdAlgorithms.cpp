#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007
 
void solve()
{
    ll n;
    cin >> n;
    cout << n <<" ";
    while(n!=1)
    {
        if(n%2==0) n >>= 1;
        else n = (3*n)+1;
        cout << n <<" ";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}