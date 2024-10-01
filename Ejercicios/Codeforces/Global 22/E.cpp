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

const ll MOD = 998244353;
ll SUMA;
ll DP[50][1000];
ll A[50];
ll dp(ll i, ll suma) {
    if(i == -1 and suma == SUMA) return 1;
    if(DP[i][suma] != -1) return DP[i][suma];

    DP[i][suma] = 0;
    if(suma - A[i] < 0) return DP[i][suma] = 0;
    else if(suma == 0 and A[i] == 0) DP[i][suma] = (2 * dp(i - 1, suma)) % MOD; 
    else if(suma - A[i] == 0) DP[i][suma] = dp(i - 1, SUMA);
    else DP[i][suma] = dp(i - 1, suma - A[i]);
    return DP[i][suma];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        ll mx = 0;
        ll suma = 0;
        rep(i, n) {
            cin>>A[i];
            mx = max(mx, A[i]);
            suma += A[i];
        }
        ll ans = 0;
        repx(val_sum, mx, suma + 1) {
            rep(i, n) rep(j, val_sum + 1) DP[i][j] = -1;
            SUMA = val_sum;
            ll val = dp(n - 1, val_sum);
            ans += val;
        }
        cout<<ans<<'\n';
    }





    return 0;
}