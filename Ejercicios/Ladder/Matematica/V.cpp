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

ll V[11];
ll bignum = 100000000000LL;

ll contar(ll x, ll a) {
    ll aux = x;
    ll ans = 0;
    while(aux <= a) {
        ll div = bignum;
        while((aux / div) % 10 == 0) div /= 10;
        while(div != 0 and V[(aux / div) % 10]) div /= 10;
        ans += (div == 0);
        aux += x;
    }
    return ans;
}

ll DP[12][100010];
ll dp(ll i, ll j) {
    
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll x, a, b; cin>>x>>a>>b;
    string s; cin>>s;
    rep(i, 10) V[i] = 0;
    for(auto u: s) V[u - '0'] = 1;
    cerr<<"estoy vivo aca\n";
    if(x >= 1e5) cout<<contar(x, b) - contar(x, a - 1)<<'\n';
    else {




    }






    return 0;
}