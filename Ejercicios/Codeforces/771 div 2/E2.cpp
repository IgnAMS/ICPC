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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt
struct FT1 // anade
{
    vi t;
    FT1(int N) { t.resize(N + 1, 0); }
    ll query(ll i) {
        ll ans = 0;
        for (; i; i -= i & (-i)) ans += t[i];
        return ans;
    }
    ll query(ll i, ll j) { return query(j) - query(i - 1); }
    void update(ll i, ll v) {
        ll s = query(i, i); // Sets
        for (; i < t.size(); i += i & (-i)) t[i] += v;
    }
    void update(ll i, ll j, ll v) { update(i, v); update(j + 1, -v); }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    FT1 ft(n); // todo inicializa en 0
    set<vi> S; S.insert({1, n, 1});
    ll inf = 1e7;
    vi Col(n + 3, 0);
    while(q--) {
        string op; cin>>op;
        // for(auto u: S) cout<<u[0]<<' '<<u[1]<<' '<<u[2]<<'\n'; cout<<'\n';
        if(op == "Color") {
            // cout<<"cambio de color!\n";
            ll l, r, c; cin>>l>>r>>c;
            vector<vi> E, A;
            auto low = prev(S.lower_bound({l + 1, 0, 0}));
            auto high = S.lower_bound({r + 1, 0, 0});
            for(auto it = low; it != high; it++) {
                ll lx = (*it)[0], rx = (*it)[1], cx = (*it)[2];
                // cout<<"itero en "<<lx<<' '<<rx<<' '<<cx<<'\n';
                if(lx < l)  {
                    A.push_back({lx, l - 1, cx});
                    ft.update(l, min(rx, r), Col[cx] - Col[c]);
                }
                if(l <= lx and rx <= r) {
                    ft.update(lx, rx, Col[cx] - Col[c]);
                }
                if(rx > r) {
                    A.push_back({r + 1, rx, cx});
                    if(lx >= l) ft.update(lx, r, Col[cx] - Col[c]);
                }
                E.push_back({lx, rx, cx});
            }
            for(auto u: E) S.erase(u);
            for(auto u: A) S.insert(u);
            // for(auto u: S) cout<<u[0]<<' '<<u[1]<<' '<<u[2]<<'\n'; cout<<'\n';
            if(l != 1) {
                low = prev(S.lower_bound({l, 0, 0}));
                if((*low)[2] == c) { l = (*low)[0]; S.erase(low); }
            } 
            if(r != n) {
                high = S.lower_bound({r + 1, 0, 0});
                if((*high)[2] == c) { r = (*high)[1]; S.erase(high); }
            }
            S.insert({l, r, c});
        }
        if(op == "Add") {
            ll c, x; cin>>c>>x;
            Col[c] += x;
        }
        if(op == "Query") {
            int i; cin>>i;
            ll col = (*prev(S.lower_bound({i + 1, 0, 0})))[2];
            // cout<<"El color de la query es: "<<col<<'\n';
            cout<<ft.query(i) + Col[col]<<'\n';
        }
    }




    return 0;
}