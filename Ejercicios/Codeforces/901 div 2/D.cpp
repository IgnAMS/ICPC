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

const int mxN = 5e3+5;
map<ll, ll> mp;
ll Mex[mxN];
ll N[mxN];
ll C[mxN];
ll DP[mxN][mxN];

ll solve(ll a, ll b) {
    if(a == 0) {
        cout<<"entre con "<<a<<' '<<b<<' '<<C[a]<<' '<<b * (C[a] - 1) + a<<'\n';
        return b * (C[a] - 1) + a;
    }
    if(DP[a][b] != -1) return DP[a][b];
    ll ans = 0;
    rep(i, a) ans = min(ans, solve(i, a));
    ans += b * (C[a] - 1) + a;
    cout<<"entre con "<<a<<' '<<b<<' '<<-+ans<<'\n';
    
    return DP[a][b] = ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        vl A(n); rep(i, n) cin>>A[i];
        rep(i, n) {
            if(!mp.count(A[i])) mp[A[i]] = 0;
            mp[A[i]]++;
        }
        ll ind = 0;
        for(auto [a, b]: mp) {
            N[ind] = a, C[ind] = b;
            ind++;
        }

        n = mp.size();
        rep(i, n + 1) rep(j, n + 1) DP[i][j] = -1;
        ll last = 0;
        rep(i, n) {
            if(N[i] == i) Mex[i] = i + 1, last = i + 1;
            else Mex[i] = last;
        }
        rep(i, n) {
            cout<<N[i]<<' '<<C[i]<<' '<<Mex[i]<<'\n';
        }
        ll ans = Mex[n - 1] == 0? 0: 1e18;
        rep(i, Mex[n - 1]) {
            ans = min(ans, solve(i, Mex[n - 1]));
        }
        cout<<ans<<'\n';
        break;
    }


    return 0;
}