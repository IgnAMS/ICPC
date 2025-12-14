#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<map>
#include<set>
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


vl X;
vector<vl> Ans[100];
void backtrack(int i, int n, int k, int suma) {
    Ans[i].pb(X);
    if(i == n) return;
    repx(j, 1, k+1) if((suma + j) % (i+1) == 0) {
        X.pb(j);
        backtrack(i+1, n, k, suma+j);
        X.pop_back();
    }
}

const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, k; cin>>N>>k;
    vector<vl> DP(2, vl(k+1, 0));
    DP[0][0] = 1;
    for(ll n = 0; n < min(N, k); n++) {
        // Itero sobre todos los multiplos de n
        for(ll i = 0; i <= k; i++) {
            ll left = (n+1 - (n * i) % (n+1));
            // itero sobre los multiplos de n+1 que puedo llegar desde i * n
            for(ll j = left; j <= k; j += n+1) {
                ll multiplo = (n * i + j) / (n+1);
                // cout<<n * i + j<<" "<<multiplo<<"\n";
                DP[1][multiplo] += DP[0][i];
                if(DP[1][multiplo] >= MOD) DP[1][multiplo] -= MOD;
            }
            
            if(n == 0) break;
        }
        rep(i, k+1) {
            DP[0][i] = DP[1][i], DP[1][i] = 0;
            // cout<<"mult: "<<i * (n+1)<<", DP: "<<DP[0][i]<<"\n";
        }
        // cout<<"\n";
    }
    ll ans = 0;
    rep(i, k+1) {
        ans += DP[0][i];
        ans %= MOD;
    }
    cout<<ans<<"\n";
    
    return 0;
}