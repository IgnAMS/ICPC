#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
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
    ll query(ll i)
    {
        ll ans = 0;
        for (; i; i -= i & (-i)) ans += t[i];
        return ans;
    }
    ll query(ll i, ll j) { return query(j) - query(i - 1); }
    void update(ll i, ll v)
    {
        ll s = query(i, i); // Sets
        for (; i < t.size(); i += i & (-i)) t[i] += v;
    }
    void update(ll i, ll j, ll v) { update(i, v); update(j + 1, -v); }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    FT1 ft(n); // todo inicializa en 0
    set<vi> S; S.insert({1, n, 0});
    ll inf = 1e7;
    while(q--) {
        string op; cin>>op;
        for(auto u: S) {
            for(auto x: u) cout<<x<<' '; cout<<'\n';
        }
        cout<<'\n';
        if(op == "Color") {
            ll l, r, c; cin>>l>>r>>c;
            vi L, R;

            auto low = S.lower_bound({l, 0, 0});
            if(low == S.end()) L = *prev(low), low = prev(low);
            else if((*low)[0] > l) L = *prev(low), low = prev(low);
            else L = *low;

            auto up = S.lower_bound({r, 0 , 0});
            if(up == S.end()) R = *prev(up), up = prev(up);
            else if((*up)[0] > r) R = *prev(up), up = prev(up);
            else R = *up;
            // for(auto u = low; u != next(up); u++) {
            //     for(auto x: *u) cerr<<x<<' '; cerr<<'\n';
            //     cerr<<'\n';
            // }
            S.erase(low, next(up));
            

            ll lx = l, rx = r;
            if(L[2] == c) l = L[0];
            else if(l > L[0]) S.insert({L[0], l - 1, L[2]});
            if(R[2] == c) r = R[1];
            else if(r < R[1]) S.insert({r + 1, R[1], R[2]});
            S.insert({lx, rx, c});
        }
        if(op == "Add") {
            ll c, x; cin>>c>>x;
            for(auto u: S) if(u[2] == c) ft.update(u[0], u[1], x);
        }
        if(op == "Query") {
            int i; cin>>i;
            cout<<ft.query(i)<<'\n';
        }
    }




    return 0;
}