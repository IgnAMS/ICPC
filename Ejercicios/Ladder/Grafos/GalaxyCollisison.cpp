#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

vector<vi> G;
vi V;
ll dfs(int u) {
    V[u] = 1;
    ll ans = 1;
    for(auto v: G[u]) if(!V[v]) ans += dfs(v);
    return ans;
}

ll f(ll x, ll y) { return abs(x - y); }
int min_search(ll x, vector<vi>& S, int l, int r) { // convex function
    while (l < r) {
        int m = (l + r) / 2;
        if(f(x, S[m + 1][1]) >= f(x, S[m][1])) r = m;
        else l = m + 1;
    }
    return l;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ii> P(n); rep(i, n) cin>>P[i].ff>>P[i].ss;
    sort(P.begin(), P.end());

    G.assign(n, vi()); V.assign(n, 0);

    vector<vector<vi>> X(500010, vector<vi>());
    rep(i, n) X[P[i].ff].push_back({P[i].ff, P[i].ss, i});
    rep(i, n) {
        rep(j, 6) if(P[i].ff - j >= 0) {
            auto& Xj = X[P[i].ff - j];
            ll s = min_search(P[i].ss, Xj, 0, Xj.size() - 1);
            cout<<"i: "<<i<<", "<<s<<' '<<Xj.size()<<'\n';
            // A lo mas 10 vecinos
            for(int k = s; k < Xj.size(); k++) {
                ll dy = (Xj[k][1] - P[i].ss);
                if(dy * dy + j * j > 25) break;
                G[i].push_back(Xj[k][2]); G[Xj[k][2]].push_back(i);
                // cerr<<i<<' '<<Xj[k][2]<<'\n';
            }
            for(int k = s - 1; k >= 0; k--) {
                ll dy = (Xj[k][1] - P[i].ss);
                if(dy * dy + j * j > 25) break;
                G[i].push_back(Xj[k][2]); G[Xj[k][2]].push_back(i);
                // cerr<<i<<' '<<Xj[k][2]<<'\n';
            }
        }
    }

    ll ans = 0;
    rep(i, n) if(!V[i]) ans += dfs(i) / 2;
    cout<<ans<<'\n';


    return 0;
}