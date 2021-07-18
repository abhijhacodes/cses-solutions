#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

ll editDistance(string s1, string s2, ll m, ll n)
{
    ll dp[m+1][n+1];
    
    for(ll i=0;i<=m;i++)
        dp[i][0]=i;
 
    for(ll j=0;j<=n;j++)
        dp[0][j]=j;
 
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}

void solve()
{
    string s1; cin>>s1;
    string s2; cin>>s2;
    cout<<editDistance(s1,s2,s1.length(),s2.length())<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}