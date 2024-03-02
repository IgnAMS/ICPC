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

const int mxN = 1e6+5;

ll DP[mxN][3][2];
ll A[mxN];
ll dp(ll i, ll sum, bool init = 0) {
    if(i == -1 and sum == 0 and init) return 1;
    if(i == -1) return 0;

    if(DP[i][sum][init] != -1) return DP[i][sum][init];

    if(!init) {
        DP[i][sum][init] = dp(i - 1, A[i] % 3, 1) + dp(i - 1, 0, 0);
    }
    else {
        DP[i][sum][init] = (sum == 0) + dp(i - 1, (sum + A[i]) % 3, 1);
    }

    return DP[i][sum][init];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    vector<vl> S;
    vl aux;
    for(auto c: s) {
        if(0 <= c - '0' and c - '0' <= 9) aux.pb(c - '0');
        else {
            if(aux.size()) S.pb(aux);
            aux.clear();
        }
    }
    if(aux.size()) S.pb(aux);

    ll ans = 0;
    for(auto vec: S) {
        rep(i, vec.size()) {
            A[i + 1] = vec[i] % 3;
            // rep(j, 3) rep(k, 2) DP[i][j][k] = 0;
        }
        // ans += dp(vec.size() - 1, 0, 0);

        DP[0][0][1] = 1;

        repx(i, 1, vec.size() + 1) {
            rep(sum, 3) {
                rep(init, 2) {
                    if(!init) {
                        DP[i][sum][init] = DP[i - 1][A[i] % 3][1] + DP[i - 1][0][0];
                    }
                    else {
                        DP[i][sum][init] = (sum == 0) + DP[i - 1][(sum + A[i]) % 3][1];
                    }
                }
            }
        }
        // cout<<DP[vec.size()][0][0]<<'\n';
        ans += DP[vec.size()][0][0];

    }
    cout<<ans<<'\n';

    return 0;
}