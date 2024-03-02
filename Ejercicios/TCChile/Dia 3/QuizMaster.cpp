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

vl Sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    vl P;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            P.pb(i);
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return P;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin>>t;
    vl P = Sieve(1e5 + 4);
    cout<<P.size()<<'\n';

    while(t--) {
        int n, m; cin>>n>>m;
        vl A(n); rep(i, n) cin>>A[i];
        sort(A.begin(), A.end());
        vector<vl> divA(m);
        rep(i, n) {
            for(auto u: P) if(A[i] % u == 0) divA[i].pb(u);
        }

        vl Acc(m + 1, 0);
        ll curr = 0;
        ll i = 0;
        ll ans = 1e6;
        rep(j, n) {
            for(auto u: divA[i]) {
                if(Acc[u] == 0) 
                if(Acc[A[j] % m] == 0) curr++;
            }
            Acc[A[j] % m]++;
            rep(k, m + 1) cout<<Acc[k]<<' '; cout<<'\n';
            while(true){
                Acc[A[i] % m]--, i++;
            }
            if(curr == m) ans = min(ans, A[j] - A[i]);
        }
        cout<<ans<<'\n';
    }

    return 0;
}