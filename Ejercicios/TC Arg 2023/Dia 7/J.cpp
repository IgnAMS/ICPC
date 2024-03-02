#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define ff first
#define ss second
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
ll M = 1e9 + 7;
vector<int> Up, Down;

ll maxlog2(ll x)
{
    return (63 - __builtin_clzll(x));
}

struct SparseTableLCA
{
    ll maxlg;
    vector<vl> SP;
    vl D;
    SparseTableLCA(vector<vector<pair<int, int>>>& g)
    {
        ll n = g.size();
        vector<int> vis(n, 0);
        vl parent(n, -1);
        Up.assign(n, 0); Down.assign(n, 0);
        D.resize(n, 1e9); D[0] = 0;
        queue<int>q;
        q.emplace(0);

        while(!q.empty())
        {
            ll k  = q.front(); q.pop();
            //cout << k+1 << " " << Up[k] << " " << Down[k] << endl;
            if(!vis[k])
            {
                vis[k] = 1;
                for(auto it : g[k])
                {
                    int v = it.ff, x = it.ss;
                    if(!vis[v])
                    {
                        parent[v]  = k;
                        D[v] = D[k]+1;
                        q.push(v); // Le doy al hijo la info de la arista
                        if(x == 1)
                            Down[v] = 1;
                        else if(x == -1) Up[v] = 1;

                        Down[v] += Down[k];
                        Up[v] += Up[k];
                    }
                }
            }
        }

        SP.clear();
        SP.push_back(parent);
        maxlg = 63 - __builtin_clzll(n);

        repx(i, 1, maxlg+1)
        {
            vl aux;
            rep(j, n)
            {
                if(SP[i-1][j]!=-1)
                    aux.push_back(SP[i-1][SP[i-1][j]]);
                else aux.push_back(-1);
            }
            SP.push_back(aux);
        }
    }
    ll level(ll a, ll n)
    {
        while(D[n] != a)
            n = SP[maxlog2(D[n]-a)][n];
        return n;
    }
    ll LCA(ll u, ll v)
    {
        ll x = u, y = v;
        if(D[u] <= D[v]) swap(x, y);

        if(D[x] != D[y])
            x = level(min(D[x], D[y]), x);

        if(x == y) return x;

        for(ll i = maxlg; i >= 0; i--)
        {
            if(SP[i][x] != SP[i][y] && SP[i][x] != -1)
            {
                x = SP[i][x];
                y = SP[i][y];
            }
        }
        return SP[0][x];
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vl p2(100001, 0);
    ll mul = 1, ans = 0;
    rep(i, 100001)
    {
        p2[i] = mul;
        mul = (mul * 2) % M;
    }

    int n, k;
    cin >> n;
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>(0));
    rep(i, n-1)
    {
        int a, b, x;
        cin >> a >> b >> x;
        a--; b--;

        g[a].push_back({b, x});
        g[b].push_back({a, -x});
    }

    SparseTableLCA LCA(g); 
    //cout << "hola"<<endl;

    cin >> k;
    int a_l = 0;
    rep(i, k)
    {
        int a_r;
        cin >> a_r;
        a_r--;

        int lca = LCA.LCA(a_l, a_r);
        //ll cont = 1;
        ll cont = Down[a_l] - Down[lca] + Up[a_r] - Up[lca];
        //cout << cont <<" "<<lca<< endl;
        ans += (p2[cont] + M - 1) % M;
        ans %= M; 
        a_l = a_r;
    }

    cout << ans << "\n";    




    return 0;
}