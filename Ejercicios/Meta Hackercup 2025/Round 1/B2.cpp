#pragma GCC optimize("Ofast")
#include<vector>
#include<map>
#include<iostream>
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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txtß


ll n, A, B;

const ll max_pot = 1e7;
vector<bool> Prime(max_pot+1, 1);
vl P;
const ll MOD = 1e9+7;

vl Divs;
map<ll, vl> Conts;
ll F[1000001];

void backtrack(int i, int j, ll curr, ll cont, vl& Px, vl& Pot) {
    if(i == Px.size()) {
        Divs.pb(curr);
        return;
    }
    backtrack(i+1, 0, curr, cont, Px, Pot);
    if(j < Pot[i]) backtrack(i, j+1, curr * Px[i], cont+1, Px, Pot);
}


void generate_all_divisors(map<ll, ll>& dec_prime) {
    Divs.clear();
    Conts.clear();
    vl Px, Pot;
    for(auto [a, b]: dec_prime) {
        Px.pb(a); Pot.pb(b);
    }
    backtrack(0, 0, 1, 0, Px, Pot);

    for(auto d: Divs) {
        ll aux = d;
        Conts[d] = {};
        for(auto p: Px) {
            ll cont = 0;
            while(aux % p == 0) aux /= p, cont++;
            if(cont) Conts[d].pb(cont);
        }
    }
}

ll divmod(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}


ll repartir(vl &X) {
    ll ans = 1;
    for(auto x: X) {
        ll curr = 1LL;
        repx(i, n, n + x) {
            curr *= 1LL * i;
            curr %= MOD;
        }
        curr *= divmod(F[x], MOD - 2);
        curr %= MOD;
        ans *= curr;
        ans %= MOD;
    }
    return ans;
}



void solve(int caso) {
    cin>>n>>A>>B;
    ll aux = B;
    map<ll, ll> dec_prima;
    ll contador = 0;
    for(auto p: P) {
        while(aux % p == 0) {
            if(!dec_prima.count(p)) dec_prima[p] = 0;
            dec_prima[p] += 1;
            aux /= p;
            contador++;
        }
    }
    if(aux != 1) dec_prima[aux] = 1, contador++;
    generate_all_divisors(dec_prima);

    ll ans = 0;
    for(auto d: Divs) if(d <= A) {
        ll curr = (repartir(Conts[d]) * repartir(Conts[B / d])) % MOD;
        // cout<<d<<" contribuye "<<curr<<" casos\n";
        // cout<<repartir(Conts[d])<<" "<<repartir(Conts[B / d])<<"\n\n";
        ans += curr;
        ans %= MOD;
    }


    cout<<"Case #"<<caso+1<<": "<<ans<<"\n";
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; 
    F[0] = 1;
    repx(i, 1, 1000000) F[i] = (1LL * i * F[i - 1]) % MOD;
    
    for(int i = 2; i <= max_pot; i++) if(Prime[i]) {
        P.pb(i);
        for(ll j = 1LL * i * i; j <= max_pot; j+=i) {
            Prime[j] = 0;
        }
    }
    // len(P) = 664579


    rep(i, t) solve(i);
    return 0;
}