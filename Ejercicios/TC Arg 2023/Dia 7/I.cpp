#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define ff first
#define ss second
#define rep(i, n) for(int i = 0; i < n; i++)

vector<vl> g;
ll a = 0, b = 0;

void dfs(int v, int flag, int p)
{
    if(flag) a++;
    else b++;
    for(auto it : g[v])
    {
        if(it != p)
            dfs(it, !flag, v);
    }
}

int main() {

    int n;
    cin >> n;
    g.assign(n, vl(0));
    rep(i, n-1)
    {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, 1, -1);

    cout << min(a, b) - 1 << "\n";
    return 0;
}