#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

int n, m;
char grid[1001][1001];
bool vis[1001][1001];

void dfs(int i, int j, int n, int m)
{
	if(i<0 or i>=n or j<0 or j>=m or vis[i][j] or grid[i][j]=='#') 
		return;
	vis[i][j] = true;
	dfs(i-1, j, n, m);
	dfs(i, j+1, n, m);
	dfs(i+1, j, n, m);
	dfs(i, j-1, n, m);
}

void solve()
{
    cin >> n >> m;
 
    for(int i=0; i<n; i++)
    {
    	for(int j=0; j<m; j++)
    		cin >> grid[i][j];
    }

    int rooms = 0;

    for(int i=0; i<n; i++)
    {
    	for(int j=0; j<m; j++)
    	{
    		if(grid[i][j]=='.' and !vis[i][j])
    		{
    			dfs(i, j, n, m);
    			rooms++;
    		}
    	}
    }

    cout << rooms << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}