#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second


vl a;
int memo[4][300001];
int dp(int sum, int i)
{
    if(i == a.size())
    {
        if(sum == 0 || sum > 1)
            return 1;
        else 
            return 0;
    }

    if(memo[sum][i] != -1)
        return memo[sum][i];

    ll ans = 0;
    cout << i << " " << sum << endl;

    if(sum == 0 || sum > 1)
        ans += dp(a[i], i+1);

    if(i > 0 && sum + a[i] < 4)
    {
        ans += dp(sum + a[i], i+1);
    }

    return memo[sum][i] = ans;

}

int main() {
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());

    vector<vl> g, seg;
    vl act;

    vl E(n);
    rep(i, n) {
        if(i < n - 3 and A[i+1]-A[i] <= 1000 and A[i+2]-A[i+1] <= 1000 and A[i+3]-A[i+2] <= 1000) {
            cout<<"Impossible\n";
            return 0;
        }
        if(i < n - 2 and A[i+1]-A[i] >= 2000 and A[i+2]-A[i+1] >= 2000) {
            cout<<"Impossible\n";
            return 0;
        }

        if(act.empty() || A[i]-A[i-1] <= 1000)
        {
            act.push_back(A[i]);
        }
        else if(!act.empty())
        {
            g.push_back(act);
            act.clear();
            act.push_back(A[i]);
        }

    }
    if(!act.empty())
        g.push_back(act);
    act.clear();
    rep(i, g.size())
    {
        if(g[i].size() == 3)
        {
            if(!act.empty())
                seg.push_back(act);
            continue;
        }
        else if(g[i].size() > 3)
            return 1;

        if(act.empty() || g[i][0]-g[i-1].back() < 2000)
        {
            act.push_back(g[i].size());
        }
        else if(!act.empty())
        {
            seg.push_back(act);
            act.clear();
            act.push_back(g[i].size());
        }
    }

    if(!act.empty())
        seg.push_back(act);

    for(auto it : g)
    {
        for(auto it2 : it)  cout << it2 << " ";
        cout << endl;
    }

    for(auto it : seg)
    {
        for(auto it2 : it)  cout << it2 << " ";
        cout << endl;

        a = it;
        rep(i, a.size())
            rep(z, 4)
                memo[z][i] = -1;
        cout << dp(0, 0) << "\n";
    }

    return 0;
}