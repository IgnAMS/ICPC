#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
typedef pair<ll, ll> pll;
typedef unsigned long long ul;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt

const ll MOD = 1e9 + 7;
const int MAXN = 1000;

pll euclid(ll A, ll B){
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

// find x in [0, M) such that Ax = 1 mod M
ll minv(ll A, ll M = 1000000007){
    pll p = euclid(A, M);
    assert(p.ff * A + p.ss * M == 1);
    return p.ff + (p.ff < 0) * M;
}

// find (x, y)'s such that Ax + By = R where R is multiplle of gcd(A, B);
pair<pll, pll> diophantine(ll A, ll B, ll R){
    ll g = __gcd(A, B), x, y; A /= g, B /= g, R /= g;
    tie(x, y) = euclid(A, B); x *= R, y *= R;
    assert(A * x + B * y == R);
    return {{x, y}, {-B, A}}; // solutions: p+t*ans.snd
}

inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }

ll binPow(ll a, ll b, const ll M)
{
    if (b == 0) return 1;
    ll r = binPow(a, b / 2, M); r = mul(r, r, M);
    return (b & 1) ? mul(r, a, M) : r;
}

ul modMul(ul a, ul b, const ul M){
    ll r = a * b - M * (ul)((db)a * b / M);
    return r + ((r < 0) - (r >= (ll)M)) * M;
}

ul modPow(ul a, ul b, const ul M){
    if (b == 0) return 1;
    ul r = modPow(a, b / 2, M); r = modMul(r, r, M);
    return b & 1 ? modMul(r, a, M) : r;
}
ll C[MAXN + 1][MAXN + 1];
void init_C(){
    rep(m, MAXN + 1) if (m){
        C[m][0] = C[m][m] = 1;
        rep(k, m) if (k) C[m][k] = add(C[m - 1][k], C[m - 1][k - 1]);
    }
}

// By definition and euclid
ll F[MAXN];
ll choose(int n, int k){
    return mul(F[n], minv(mul(F[k], F[n - k]), MOD));
}

// Multinomial Coefficient
ll multinomial(vector<int> K){
    ll n = 0, ans = 1;
    for (int k : K) n += k, ans = mul(ans, choose(n, k));
    return ans;
}

int DP[10][52][900];
int nums[10];
int pares[10];
int total = 0;
ll ans = 0;
int N;

void compute(){
    int imp[10]; rep(i, 10) imp[i] = nums[i] - pares[i];
    if(N % 2){ // impar > par
        ll aux1 = F[N/2];
        ll div1 = 1;
        rep(i, 10) div1 = mul(F[pares[i]], div1);
        aux1 = mul(aux1, minv(div1));
        cout<<F[N/2]<<' '<<div1<<' '<<minv(div1)<<'\n';

        ll div20 = 1, div21 = 1; 
        rep(i, 10) div20 = mul(F[imp[i]], div20);
        repx(i, i, 10) div21 = mul(F[imp[i]], div21);
        ll m0 = F[N/2 + 1], m1 = F[N/2 + 1 - imp[0]];
        ll aux2 = mul(m0, minv(div20));
        if(imp[0]) aux2 = ((aux2 - mul(m1, minv(div21))) % MOD + MOD) % MOD;

        ans = add(ans, mul(aux2, aux1));
        // cout<<"aux1 y aux2: "<<aux1<<' '<<aux2<<'\n';
        // cout<<"impares: "; rep(i, 10) cout<<imp[i]<<' '; cout<<'\n';
        // cout<<"pares: "; rep(i, 10) cout<<pares[i]<<' '; cout<<'\n';
        // cout<<"anado: "<<mul(aux1, aux2)<<"\n\n";
    }
    else{
        ll m0 = F[N/2], m1 = F[N/2 - pares[0]];
        ll div10 = 1, div11 = 1;
        rep(i, 10) div10 = mul(div10, F[pares[i]]);
        repx(i, 1, 10) div11 = mul(div11, F[pares[i]]);
        ll aux1 = mul(m0, minv(div10));
        if(pares[0]) aux1 = ((aux1 - mul(m1, minv(div11))) % MOD + MOD) % MOD;

        ll aux2 = F[N/2];
        ll div2 = 1;
        rep(i, 10) div2 = mul(div2, F[imp[i]]);
        aux2 = mul(aux2, minv(div2));
        ans = add(ans, mul(aux1, aux2));
        
        // cout<<"aux1 y aux2: "<<aux1<<' '<<aux2<<'\n';
        // cout<<"impares: "; rep(i, 10) cout<<imp[i]<<' '; cout<<'\n';
        // cout<<"pares: "; rep(i, 10) cout<<pares[i]<<' '; cout<<'\n';
        // cout<<"anado: "<<mul(aux1, aux2)<<"\n\n";
    }
}

bool dp(int x, int k, int suma){ // busca un caso posible
    if(k == 0 and (suma - (total - suma)) % 11 == 0) { // si es 1 puedo calcular la respuesta
        // computo la respuesta y devuelvo
        // termine los pares, asi que inicializo los impares
        rep(i, x) pares[i] = 0;
        compute();
        return 1;
    }
    if(x == -1 and k == 0 and (suma - (total - suma)) % 11 != 0) return 0;
    if(DP[x][k][suma] == 0) return bool(DP[x][k][suma]);
    if(x < 0) return 0;
    DP[x][k][suma] = 0; // marco como que no tiene respuesta, cosa de no extender la busqueda
    rep(i, min(k, nums[x]) + 1){
        pares[x] = i;
        if(dp(x - 1, k - i, suma + x * i)) DP[x][k][suma] = 1;
    }
    return DP[x][k][suma];
}





int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string linea;
    F[0] = 1;
    repx(i, 1, 103) F[i] = mul(F[i-1], i);

    while(cin>>linea){
        // seteo cosas iniciales
        int n = linea.length(); N = n;
        memset(nums, 0, sizeof nums);
        memset(pares, 0, sizeof pares);
        ans = 0, total = 0;
        for(auto c: linea) nums[c-'0']++, total += c-'0';
        rep(i, 10) rep(j, n/2 + 2) rep(k, total + 1) DP[i][j][k] = -1;

        // calculo la respuesta
        auto u = dp(9, n/2, 0);
        cout<<ans<<'\n';
        cerr<<"\n";
    }

    return 0;
}