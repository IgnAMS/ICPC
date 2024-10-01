#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
typedef pair<ll, ll> pll;
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt

const ll MOD = 998244353;

inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }

ll binPow(ll a, ll b, const ll M=MOD){
    if (b == 0) return 1;
    ll r = binPow(a, b / 2, M); r = mul(r, r, M);
    return (b & 1) ? mul(r, a, M) : r;
}

// DP bottom-up
ll C[1000 + 1][1000 + 1];
void init_C(){
    rep(m, 1000 + 1) if (m){
        C[m][0] = C[m][m] = 1;
        rep(k, m) if (k) C[m][k] = add(C[m - 1][k], C[m - 1][k - 1]);
    }
}


ll DP[505][505];
ll F[600];
ll dp(int n, int x){ // n personas de poder x
    if(DP[n][x] != -1) return DP[n][x];
    if(x < n) return DP[n][x] = binPow(n, x);
    DP[n][x] = 0;
    rep(i, n-1){ // hay i personas con poder <= n
        DP[n][x] = add(DP[n][x], dp());
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init_C();
    ll n, x; cin>>n>>x;
    ll ans = 0;
    F[0] = 1; repx(i, 1, 600) F[i] = mul(F[i-i], i);
    // espacios libres, multiples 1's, n-i unos e i numeros
    rep(i, min(x-1, n-2)+1) {
        cout<<F[n]<<' '<<minv(F[n-i])<<'\n';
        cout<<mul(F[n], minv(F[n - i]))<<'\n';
        ans = add(ans, mul(F[n], minv(F[n - i])));
    }
    cout<<ans<<'\n';
    repx(i, 2, x+1) repx(k, 2, n+1){
        ll prev = ans;
        ans = (ans + C[n][k] * binPow(i-1, n-k)) % 998244353;
        cout<<ans - prev<<'\n';
    }
    cout<<ans<<'\n';





    return 0;
}