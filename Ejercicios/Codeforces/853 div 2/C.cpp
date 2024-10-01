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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, m; cin>>n>>m;
        vl A(n); rep(i, n) cin>>A[i];
        vl S(n + m + 2, 0);
        vl Curr(n + m + 2, 0);
        rep(i, n + m + 1) Curr[i] = m + 1;
        rep(i, n) Curr[A[i]] = 0;
        repx(i, 1, m + 1) {
            int p, v; cin>>p>>v; p--;
            S[A[p]] += i - Curr[A[p]];
            Curr[A[p]] = m + 1;
            A[p] = v;
            Curr[v] = i;
        }
        rep(i, n + m + 1) S[i] += m + 1 - Curr[i];
        ll ans = 0;
        // rep(i, n + m + 1) cout<<(m * (m + 1)) / 2 - ((m - S[i]) * (m - S[i] + 1)) / 2<<' '; cout<<'\n';
        rep(i, n + m + 1) ans += (m * (m + 1)) / 2 - ((m - S[i]) * (m - S[i] + 1)) / 2;
        cout<<ans<<'\n';
    }


    return 0;
}