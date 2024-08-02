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

const ll MOD = 1e9+7;
ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll minv(ll x) {
    return binpow(x, MOD - 2);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vl Div[100005];
    for(ll i = 1; i < 100005; i++) {
        for(ll j = i; j < 100005; j += i) {
            Div[j].pb(i);
        }
    }

    int n; cin>>n;
    ll ans = 0;
    for(auto g: Div[n]) {
        // C no es divisor de g
        ll x = n / g;
        ll notdivg = (x - x / g) * (x - x / g + 1) / 2;
        notdivg %= MOD;

        cout<<"no divisores de "<<g<<" hasta "<<x<<": "<<notdivg<<'\n';
        for(auto g2: Div[x]) {
            ll aux = (notdivg * g2) % MOD;
            aux = (aux * (x / g2)) % MOD;
            aux = (aux * (x / g2)) % MOD;
            ans += aux;
            ans %= MOD;
        }

        // C si es divisor de g
        ll divg = (x / g) * (x / g + 1) / 2;
        cout<<"multiplos de "<<g<<" hasta "<<x<<": "<<divg<<'\n';
        divg %= MOD;
        for(auto g2: Div[x]) if(g2 % g != 0) {
            cout<<"entre aca con "<<g2<<'\n';
            cout<<divg<<' '<<g2<<' '<<x / g2<<'\n';
            ll aux = (divg * g2) % MOD;
            aux = (aux * (x / g2)) % MOD;
            aux = (aux * (x / g2)) % MOD; 
            ans += aux;
            ans %= MOD;
        }
    }
    cout<<ans<<'\n';


    return 0;
}