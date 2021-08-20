#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

vector<ll> parent[200001];
ll sub[200001];

void dfs(ll src, ll par)
{
    sub[src] = 1;
    for(ll adj: parent[src])
    {
        if(adj != par)
        {
            dfs(adj, src);
            sub[src] += sub[adj];
        }
    }
}

void solve()
{
    ll n; cin >> n;
   
    for(int i=2; i<=n; i++)
    {
        ll x; cin >> x;
        parent[i].push_back(x);
        parent[x].push_back(i);
    }

    dfs(1, 0);
    
    for(int i=1; i<=n; i++)
    {
        cout << sub[i]-1 << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}