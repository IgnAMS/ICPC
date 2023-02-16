#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

ll DP[1000005];
ll V[1000005];
ll Leaves[1000005];
vector<vector<ll>> G(400005, vector<ll>());


ll dp(ll u, ll x) {
    cerr<<"visito a "<<u<<' '<<x<<'\n';
    if(DP[u] != -1 and x != -1 and DP[u] != x) return DP[u] = -2;
    if(DP[u] != -1) return DP[u];
    if(x == -1 and G[u].empty()) return -1;
    if(x != -1 and x < Leaves[u]) return DP[u] = -2;

    ll notl = 0, l = 0, notvisit = 0, indnot = -1;
    for(auto v: G[u]) {
        ll val = dp(v, DP[v]);
        if(val) return DP[u] = -2;
        if(val == -1) l += Leaves[v], notvisit++, indnot = v;
        else notl += val;
    }

    // no se cuanto valgo, pero si se cuanto valen mis hijos
    if(x == -1 and notvisit == 0) return DP[u] = dp(u, notl);
    else if(x == -1) return -1; // notvisit >= 1, pero no se ni mi valor
    else if(x - notl == l) { // marco todas mis hojas con 1
        if(dp(indnot, Leaves[indnot]) < 0) return DP[u] = -2;
        return DP[x];
    }
    // no tengo hijos, pero no cuadra la suma
    else if(notvisit == 0 and x != notl) return DP[u] = -2; 
    // tengo un hijo, pero no puedo cubrir las hojas
    else if(notvisit == 1 and x - notl < Leaves[indnot]) return DP[u] = -2;
    // tengo un hijo, y me da para cubrir las hojas
    else if(notvisit == 1 and x - notl >= Leaves[indnot]) {
        if(dp(indnot, x - notl) < 0) return DP[u] = -2;
        else return DP[u]; 
    }
    return DP[u];
}


ll leaves(ll u) {
    if(G[u].size() == 0) return Leaves[u] = 1;
    if(Leaves[u] != 0) return Leaves[u];
    ll suma = 0;
    for(auto v: G[u]) suma += leaves(v);
    return Leaves[u] = suma; 
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    repx(i, 1, n) {
        int p; cin>>p; p--;
        G[p].push_back(i);
    }
    rep(i, n) {
        cin>>DP[i];
        V[i] = 0, Leaves[i] = 0;
        if(DP[i] == 0) DP[i] = -1;
    }
    

    leaves(0);
    dp(0, DP[0]);
    ll pos = 1;
    rep(i, n) if(DP[i] < 0) {
        cout<<"impossible\n";
        return 0;
    }
    rep(i, n) cout<<DP[i]<<'\n';




    return 0;
}