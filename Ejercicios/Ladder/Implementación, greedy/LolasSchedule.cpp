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

ll f(ll s, ll d, ll i, ll x) {
    if(s + d < i) return 0;
    ll l = max(s, i) - 1;
    if(i < s) return (s + d - i) / x - (l - i) / x;
    return (s + d - i) / x + 1;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x; cin>>n>>x;
    vi S(n), D(n); rep(i, n) cin>>S[i]>>D[i];
    ll ans = LLONG_MAX;
    ll ind = -1;
    rep(i, 481) {
        ll cont = 0;
        rep(j, n) cont += f(S[j], D[j], i, x);
        if(cont < ans) ans = cont, ind = i;
        
    }
    cout<<ind<<' '<<ans<<'\n';





    return 0;
}