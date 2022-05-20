#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef unsigned long long ul;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


const ll MOD = 1e9 + 7;

inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }

ll mul(vi A) {
    ll aux = 1;
    for(auto u: A) aux = mul(aux, u);
    return aux;
}

ll binPow(ll a, ll b, const ll M = MOD) {
    if (b == 0) return 1LL;
    ll r = binPow(a, b / 2LL, M); r = mul(r, r, M);
    return (b & 1) ? mul(r, a, M) : r;
}

pll euclid(ll A, ll B) {
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

// find x in [0, M) such that Ax = 1 mod M
ll minv(ll A, ll M = MOD) {
    pll p = euclid(A, M);
    assert(p.ff * A + p.ss * M == 1);
    return p.ff + (p.ff < 0) * M;
}

const ll MAXN = 1000009;
ll F[MAXN];
ll choose(ll n, ll k){
    return mul(F[n], minv(mul(F[k], F[n - k]), MOD));
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, g, i, e; cin>>n>>g>>i>>e;
    // inicio el factorial
    F[0] = 1;
    repx(i, 1, 1000009) F[i] = mul(i, F[i - 1]);


    // Casos borde
    if(g + e >= 2 * n) {
        cout<<2 * n<<'\n';
        return 0;
    }
    if(g + e + i >= 2 * n) {
        cout<<g + e <<'\n';
        return 0;
    }

    // Caso general
    ll casos = 0, fel_tot = 0;

    bool cer = 0;

    // pg: pares de g, pi: pares de i, pe: pares de e
    // sg: simples de g, si, simples de i, se: simples de e
    repx(pg, max(0LL, g - n), g / 2 + 1) { // inclusivo
        // Caso de G 
        ll comb = 1, felicidad = 0;
        ll sg = g - 2 * pg;
        if(cer) cerr<<"combinatorias: ("<<n<<", "<<pg<<"), ("<<n - pg<<", "<<sg<<") * "<<2<<"^"<<sg<<"\n"; 
        comb = mul(comb, choose(n, pg)); // parejas
        comb = mul(comb, choose(n - pg, sg)); // no parejas
        comb = mul(comb, binPow(2, sg)); // posiciones de las no parejas
        felicidad += g; 

        // Caso de E
        ll b = max(0LL, e - sg);
        felicidad += min(sg, e) + (b / 2) * 2; 
        ll sb = b % 2, pb = b / 2;

        // b != 0, por ende quedan todos los puestos de sg ocupados
        if(b % 2 == 1) { 
            // comb = mul(comb, choose(n - pg - sg, pb));
            // comb = mul(comb, choose(n - pg - sg - pb, 1));
            // comb = mul(comb, 2);
        }
        else { // b == 0 o b == 2 * k
            // comb = mul(comb, choose(n - pg - sg, pb)); // b = 2 * k
            // comb = mul(comb, choose(sg, max(0LL, sg - e))); // b = 0
        }

        // Caso I
        ll disp = n - pg - sg - sb - pb; // asientos dobles disponibles
        ll unos = max(0LL, sg - e) + sb;
        ll si = 0, pi = 0;

        if(i <= disp) {
            // comb = mul(comb, choose(disp, i));
            // comb = mul(comb, binPow(2, i));
            felicidad += i;
            si = i;
        }
        else if(i <= disp + unos) { // hago la combinatoria de los unos, agrego los casos
            // comb = mul(comb, choose(unos, i - disp));
            // comb = mul(comb, binPow(2, disp));
            felicidad += disp;
            si = disp;
            if(sb) felicidad++;
        }
        else { // usa todos los unos
            if(sb) felicidad++; // ocupo el puesto del b restante
            ll d = i - unos;
            si = 2 * disp - d, pi = d - disp;
            felicidad += si;
            // comb = mul(comb, choose(disp, si));
            // comb = mul(comb, binPow(2, si));
        }
        fel_tot = add(fel_tot, mul(felicidad, comb));
        casos = add(casos, comb);
    }
    cout<<mul(fel_tot, minv(casos))<<'\n';

    return 0;
}