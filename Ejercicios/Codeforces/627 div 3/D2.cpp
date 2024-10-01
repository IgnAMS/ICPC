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


struct FT
{
    vi t;
    FT(int N) { t.resize(N + 1, 0); }
    ll query(int i)
    {
        ll ans = 0;
        for (; i; i -= i & (-i)) ans += t[i];
        return ans;
    }
    ll query(int i, int j) { return query(j) - query(i - 1); }
    void update(int i, ll v)
    {
        int s = query(i, i); // Sets
        for (; i < t.size(); i += i & (-i)) t[i] += v;
    }
    void update(int i, int j, ll v) { update(i, v); update(j + 1, -v); }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    vi B(n); rep(i, n) cin>>B[i];
    vi D(n); rep(i, n) D[i] = A[i] - B[i];
    
    // rep(i, n) cout<<D[i]<<' '; cout<<'\n';
    set<ll> S;
    rep(i, n) S.insert(D[i]);
    map<ll, ll> mp;
    int cont = 0;
    // for(auto it = S.rbegin(); it != S.rend(); it++) mp[*it] = ++cont;
    // for(auto u: S) mp[u] = ++cont;
    S.insert(0);
    for(auto it = S.lower_bound(0); ; it--) {
        mp[*it] = ++cont;
        if(it == S.begin()) break;
    }
    FT ft1(n + 1);
    ll ans = 0;
    ll pos = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(D[i] > 0) {
            auto it = S.lower_bound(1 - D[i]);
            ll x = ft1.query(mp[*it]);
            ll prev = ans;
            ans += x;
            ans += pos++;
        }
        else ft1.update(mp[D[i]], cont, 1);
    }

    FT ft2(n + 1);
    rep(i, n) {
        if(D[i] > 0) {
            auto it = S.lower_bound(1 - D[i]);
            ll x = ft2.query(mp[*it]);
            ll prev = ans;
            ans += x;
        }
        else {
            ft2.update(mp[D[i]], cont, 1);
        }
    }

    cout<<ans<<'\n';







    return 0;
}