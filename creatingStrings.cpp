#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void permute(string s, string cur, vector<string> &ans)
{
    if(s.length() == 0)
    {
        ans.push_back(cur);
        return;
    }
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        string left = s.substr(0,i);
        string right = s.substr(i+1);
        string rest = left + right;
        permute(rest , cur+ch, ans);
    }
}

void solve()
{
    string s;
    cin >> s;
    vector<string> ans;
    permute(s, "", ans);
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(string a: ans)
        cout << a << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}