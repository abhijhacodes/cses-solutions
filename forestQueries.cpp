#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

#define N 1001
ll forest[N][N];

ll getSum(ll sx, ll sy, ll ex, ll ey)
{
	return forest[ex][ey] - forest[sx-1][ey] - forest[ex][sy-1] + forest[sx-1][sy-1];
}

void solve()
{
    ll n, q;
    char tree;

    cin >> n >> q;

    for(int i=1; i<=n; i++)
    {
    	for(int j=1; j<=n; j++)
    	{
    		cin >> tree;
    		forest[i][j] = tree == '*';
    		forest[i][j] += forest[i][j-1];
    	}
    }

    for(int i=1; i<=n; i++)
    {
    	for(int j=1; j<=n; j++)
    	{
    		forest[i][j] += forest[i-1][j];
    	}
    }

    ll a, b, c, d;
    for(int i=1; i<=q; i++)
    {	
    	cin >> a >> b >> c >> d;
    	cout << getSum(a, b, c, d) << "\n";
    }
   
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}