#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

const int mxN = 2e5 + 4;
ll T[4 * mxN];
void update(int p, int x, int l = 0, int r = mxN, int u = 0) {
    if(l == r) T[u] = x;
    else{
        ll m = (l + r) / 2;
        if(p <= m) update(p, x, l, m, 2 * u + 1);
        else update(p, x, m + 1, r, 2 * u + 2);
        T[u] = T[2 * u + 1] + T[2 * u + 2];
    }
}

ll query(int i, int j, int l = 0, int r = mxN, int u = 0) {
    if(l > r) return 0;
    if(i <= l and r <= j) return T[u];
    if(i > r or j < l) return 0;
    ll m = (l + r) / 2;
    return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);    
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin>>n>>m>>q;
    memset(T, 0, sizeof(T));
    ll unos = 0;
    string s; cin>>s;
    vl A(n); 
    rep(i, n) {
        if(s[i] == '1') A[i] = 1, unos++;
        else A[i] = 0;
    }

    set<ll> Ind; 
    rep(i, n) Ind.insert(i);
    vl F, P(n, -1);
    rep(i, m) {
        int l, r; cin>>l>>r; l--, r--;
        while(true) {
            auto it = Ind.lower_bound(l);
            if(it == Ind.end() or *it > r) break;
            P[*it] = F.size();
            if(A[*it]) update(F.size(), 1);
            F.pb(*it);
            Ind.erase(it);
        }
    }
    
    rep(i, q) {
        // actualizo las cosas
        int x; cin>>x; x--;
        if(A[x] == 1 and P[x] != -1) update(P[x], 0);
        if(A[x] == 0 and P[x] != -1) update(P[x], 1);
        if(A[x] == 1) A[x] = 0, unos--;
        else A[x] = 1, unos++;

        // Pregunto cuantos 1`s hay en los primeros min(F.size(), unos) elementos
        ll val = query(0, min(unos, ll(F.size())) - 1);
        // rep(i, min(unos, (ll)F.size())) cout<<query(i, i)<<' '; cout<<'\n';
        // La cantidad de 0s que hay intento cambiarlo por 1`s
        ll zeros = min(unos, (ll)F.size()) - val;
        ll ans = min(unos, zeros);
        cout<<ans<<'\n';
    }






    return 0;
}