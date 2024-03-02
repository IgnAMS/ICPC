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

const ll mxN = 1e3 + 5;
const ll bmx = (1<<10) + 5;
vector<vl> G(bmx, vl());
ll MOD = 1e9+7;

ll DP[mxN][bmx];
int n, m; 

ll dp(ll i, ll mask) {
    if(i == m and mask == 0) return 1;
    if(i == m) return 0;
    if(DP[i][mask] != -1) return DP[i][mask];

    DP[i][mask] = 0;
    for(auto mask2: G[mask]) {
        // cout<<"del estado "<<i<<", ";
        // rep(j, n) if(mask & (1<<j)) cout<<j<<' '; cout<<'\n';
        // cout<<"puedo ir a "<<i + 1<<", ";
        // rep(j, n) if(mask2 & (1<<j)) cout<<j<<' '; cout<<'\n';
        
        DP[i][mask] += dp(i + 1, mask2);
        if(DP[i][mask] >= MOD) DP[i][mask] -= MOD;
    }

    return DP[i][mask];
}


bool valid_transition(ll mask, ll mask2) {
    bool valid = 1;
    rep(i, n) if((mask & (1<<i)) and (mask2 & (1<<i))) valid = 0;
    rep(i, n) {
        // 1 -> 0 esta bien
        if(!(mask2 & (1<<i)) and (mask & (1<<i))) continue;
        if(i == n - 1 and !(mask2 & (1<<i))) {
            valid = 0;
            // cout<<"no se cumple esta regla\n";
        }
        if(!(mask2 & (1<<i)) and !(mask & (1<<i)) and ((mask & (1<<(i + 1))) or (mask2 & (1<<(i + 1))))) {
            // cout<<"no se cumple esta regla2\n";
            valid = 0;
        }
        if(!(mask2 & (1<<i)) and !(mask & (1<<i))) i += 1;
    }
    return valid;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(mask, 1<<n) {
        rep(mask2, 1<<n) {
            if(valid_transition(mask, mask2)) G[mask].pb(mask2);
        }
    }


    rep(i, m) rep(mask, 1<<n) DP[i][mask] = -1;

    cout<<dp(0, 0)<<'\n';

    return 0;
}