#include "bits/stdc++.h"
using namespace std;
#define ll long long

int getMid(int s, int e) {return s+(e-s)/2;}

ll buildStUtil(int *arr, int ss, int se, ll *st, int si)
{
    if(ss==se) {
        return st[si] = arr[ss];
    }
    int mid = getMid(ss, se);
    return st[si] = buildStUtil(arr, ss, mid, st, 2*si+1)
                + buildStUtil(arr, mid+1, se, st, 2*si+2);
}

ll *buildSt(int *arr, int n)
{
    int x = (int)(ceil(log2(n)));
    int sz = 2*(int)pow(2,x)-1;
    ll *st = new ll[sz];
    buildStUtil(arr, 0, n-1, st, 0);
    return st;
}

void updateQuery(ll *st, int ss, int se, int i, int diff, int pos)
{
    if(i > se or i < ss) return;
    st[pos] += diff;
    if(se > ss){
        int mid = getMid(ss, se);
        updateQuery(st, ss, mid, i, diff, 2*pos+1);
        updateQuery(st, mid+1, se, i, diff, 2*pos+2);
    }
}

ll getSumQuery(ll *st, int qs, int qe, int ss, int se, int pos)
{
    if(ss > qe or se < qs) return 0;
    if(ss >= qs and se <= qe) return st[pos];
    int mid = getMid(ss, se);
    return getSumQuery(st, qs, qe, ss, mid, 2*pos+1) 
         + getSumQuery(st, qs, qe, mid+1, se, 2*pos+2);
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    ll *st = buildSt(arr, n);
    int a, b, k, u;
    int type;
    while(q--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> k >> u;
            int diff = u - arr[k];
            arr[k] = u;
            updateQuery(st, 0, n-1, k, diff, 0);
        }
        else
        {
            cin >> a >> b;
            b--;
            cout << getSumQuery(st, a, b, 0, n-1, 0) << "\n";
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

