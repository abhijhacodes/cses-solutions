#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

int getMid(int s, int e) {return s+(e-s)/2;}

int buildStUtil(int *arr, int ss, int se, int *st, int si)
{
    if(ss==se) {
        return st[si] = arr[ss];
    }
    int mid = getMid(ss, se);
    int left = buildStUtil(arr, ss, mid, st, 2*si+1);
    int right = buildStUtil(arr, mid+1, se, st, 2*si+2);
    return st[si] = min(left, right);
}

int *buildSt(int *arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int sz = 2*(int)pow(2,x)-1;
    int *st = new int[sz];
    buildStUtil(arr, 0, n-1, st, 0);
    return st;
}

int getMinQuery(int *st, int qs, int qe, int ss, int se, int pos)
{
    if(ss > qe or se < qs) return INT_MAX;
    if(ss >= qs and se <= qe) return st[pos];
    int mid = getMid(ss, se);
    int left = getMinQuery(st, qs, qe, ss, mid, 2*pos+1);
    int right = getMinQuery(st, qs, qe, mid+1, se, 2*pos+2);
    return min(left, right);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int *st = buildSt(arr, n);
    int a, b;
    while(q--)
    {
          cin >> a >> b;
          a--, b--;
          cout << getMinQuery(st, a, b, 0, n-1, 0) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}