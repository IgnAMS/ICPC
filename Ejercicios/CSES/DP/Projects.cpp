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

const ll mxN = 400000 + 10;


struct ST {
    vl t; int n;

    ST(vl &arr, int N) : n(N), t(N * 2, 0)
    {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = max(t[i << 1], t[i << 1 | 1]);
    }
    void set(int p, const ll &value)
    {
        for (t[p += n] = value; p >>= 1;)
            t[p] = max(t[p << 1], t[p << 1 | 1]);
    }
    ll query(int l, int r)
    {
        ll ansl = 0, ansr = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ansl = max(ansl, t[l++]);
            if (r & 1) ansr = max(t[--r], ansr);
        }
        return max(ansl, ansr);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;

    vector<vl> A(n, vl(3)); 
    set<ll> S;
    rep(i, n) {
        cin>>A[i][0]>>A[i][1]>>A[i][2];
        S.insert(A[i][0]);
        S.insert(A[i][1]);
    }
    map<ll, ll> mp;
    ll id = 0;
    for(auto u: S) {
        mp[u] = id;
        id++;
    }
    rep(i, n) A[i][0] = mp[A[i][0]], A[i][1] = mp[A[i][1]];
    sort(A.begin(), A.end());

    
    ll ans = 0;
    vl staux(2 * n + 5, 0);
    ST st(staux, 2 * n + 5);
    for(ll i = n - 1; i >= 0; i--) {
        ll q = st.query(A[i][1] + 1, 2 * n + 3) + A[i][2];
        if(q > st.query(A[i][0], A[i][0] + 1)) st.set(A[i][0], q);
        ans = max(ans, q);
    }
    rep(i, 2 * n + 2) ans = max(ans, st.query(i, i + 1));
    
    
    cout<<ans<<'\n';    


    return 0;
}