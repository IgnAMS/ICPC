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
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

const ll MOD = 1e9 + 7;

inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }

ll binPow(ll a, ll b, const ll M = MOD){
    if (b == 0) return 1;
    ll r = binPow(a, b / 2, M); r = mul(r, r, M);
    return (b & 1) ? mul(r, a, M) : r;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    ll imp = 0; rep(i, n) if(A[i] % 2) imp++;
    
    ll g = -1;
    rep(i, n){
        if(A[i] % 2 == 0 and g == -1) g = A[i];
        else if(A[i] % 2 == 0) g = __gcd(g, A[i]);
    }
    ll l = 0;
    while(g % 2 == 0) l++, g /= 2;
    ll x = 0, y = 0;
    rep(i, n){
        if(A[i] % 2 == 0 and A[i] % (1<<l) == 0) x++;
        if(A[i] % 2 == 0 and A[i] % (1<<(1+l)) == 0) y++; 
    }
    
    ll ans = 0;
    cout<<imp<<' '<<x<<' '<<y<<'\n';
    repx(i, 1, imp+1) {
        cout<<n-i<<' '<<binPow(2, n - i)<<'\n';
        ans = add(ans, binPow(2, n - i));
    }
    cout<<ans<<'\n';
    cout<<2<<' '<<n-1<<' '<<binPow(2, n - imp)<<'\n'; 
    ans = add(ans, binPow(2, x - 1));
    ans = (ans - binPow(2, y) + MOD) % MOD;
    cout<<ans<<'\n';


    return 0;
}