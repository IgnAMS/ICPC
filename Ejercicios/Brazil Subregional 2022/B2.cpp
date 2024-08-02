#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

struct AC {
    ll c = 0, ec = 0, M, A, af = -1;
    vector<vl> N, G; vl L, E;
    vl val;
    // L -> suffix link G -> anti L
    // E -> string finish
    AC (ll M, ll A) : M(M), A(A), N(M, vl(A, 0)), G(M, vl()), E(M, 0), L(M, 0) {}
    ll add(string s){ // return endpoint
        af++;
        ll p = 0;
        ll ind = 0;
        for (char l : s){
            int t = l - 'a';
            if (!N[p][t]) N[p][t] = ++c;
            p = N[p][t];
            E[p] = ++ind;
        }
        return p;
    }
    void init() {
        queue<int> q; q.push(0); L[0] = -1;
        while (!q.empty()){
            int p = q.front(); q.pop();
            for(int c = 0; c < A; c++){
                int u = N[p][c]; if (!u) continue;
                L[u] = L[p] == -1 ? 0 : N[L[p]][c], q.push(u);
                G[L[u]].push_back(u);
            }
            if (p) for(int c = 0; c < A; c++) if (!N[p][c]) N[p][c] = N[L[p]][c];
        }
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    string s; cin>>s;
    AC ac(100005, 26);
    rep(i, m) {
        string aux; cin>>aux;
        ac.add(aux);
    }

    ll ans = n;
    ll p = 0;
    multiset<ll> S;
    ll gap = 0;
    vl Closed[3 * n];
    rep(i, 2 * n) {
        p = ac.N[p][s[i % n] - 'a'];
        S.insert(gap);
        if(gap + ac.E[p] < 3 * n) Closed[gap + ac.E[p]].pb(gap);
        cout<<gap<<" "<<ac.E[p]<<" lo mando a cerrar en "<<gap + ac.E[p]<<'\n';
        for(auto u: Closed[gap]) S.erase(S.find(u));
        gap++;
    }

    rep(i, n) {
        p = ac.N[p][s[i] - 'a'];
        S.insert(gap);
        if(gap + ac.E[p] < 3 * n) Closed[gap + ac.E[p]].pb(gap);
        for(auto u: Closed[gap]) S.erase(S.find(u));
        
        gap++;

        cout<<gap<<'\n';
        for(auto u: S) cout<<gap - u<<' '; cout<<'\n';
        if(!S.empty()) ans = min(ans, gap - *S.begin());

    }
    cout<<ans<<'\n';



    return 0;
}