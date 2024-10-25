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

struct ST {
    vl t; int n;
    ST(int N) : n(N), t(N * 2, 0) {}
    void set(int p, const ll &value) {
        for (t[p += n] = value; p >>= 1;)
            t[p] = max(t[p << 1], t[p << 1 | 1]);
    }
    ll query(int l, int r) {
        ll ansl = 0, ansr = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = max(ansl, t[l++]);
            if (r & 1) ansr = max(t[--r], ansr);
        }
        return max(ansl, ansr);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<array<ll, 3>> X(n);
    set<ll> S;
    rep(i, n) {
        cin>>X[i][0]>>X[i][1]>>X[i][2];
        S.insert(X[i][0]);
        S.insert(X[i][1]);
    }
    map<ll, ll> mp;
    for(auto u: S) mp[u] = mp.size();
    for(auto& [a, b, p]: X) {
        a = mp[a], b = mp[b];
    }

    sort(X.begin(), X.end());
    ST st(mp.size() + 3);
    
    ll ans = 0;
    for(auto [a, b, p]: X) {
        ll left = st.query(0, a);
        ll right = st.query(b, b + 1);
        if(left + p > right) st.set(b, left + p);
        ans = max(ans, left + p);
    }
    cout<<ans<<'\n';


    return 0;
}