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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vi F(16, 1); repx(i, 1, 16) F[i] = F[i - 1] * i;
    vector<vector<int>> G(16);
    rep(i, 16) rep(j, 40) {
        if(F[i] & (1LL << j)) G[i].push_back(j);
    }
    // cout<<F[14]<<'\n';
    // cout<<(1LL<<39)<<'\n';
    // rep(i, 16) {
    //     cout<<F[i]<<": ";
    //     for(auto u: G[i]) cout<<u<<' '; cout<<'\n';
    // }
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        ll ans = 50;
        rep(i, (1 << 15)) {
            ll suma = 0, cont = 0;
            rep(j, 15) if(i & (1LL << j)) suma += F[j], cont++;
            if(suma > n) continue;
            rep(j, 40) if((n - suma) & (1LL << j)) cont++;
            ans = min(ans, cont);
        }
        cout<<ans<<'\n';

    }


    return 0;
}