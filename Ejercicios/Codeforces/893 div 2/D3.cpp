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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        string s; cin>>s;

        ll pref[n + 1][k + 1], suf[n + 1][k + 1]; 
        ll DP[n + 1];
        memset(DP, -1, sizeof(DP));
        
        // longitud maxima es 0
        memset(pref, 0, sizeof(pref));
        memset(suf, 0, sizeof(suf));
        rep(i, n) rep(j, k + 1) {
            if(s[i] == '0') pref[i + 1][j] = pref[i][j] + 1;
            else if(j > 0) pref[i + 1][j] = pref[i][j - 1] + 1;
            DP[0] = max(DP[0], pref[i + 1][j]);
        }
        

        for(int i = n - 1; i >= 0; i--) rep(j, k + 1) {
            if(s[i] == '0') suf[i][j] = suf[i + 1][j] + 1;
            else if(j > 0) suf[i][j] = suf[i + 1][j - 1] + 1;
        }

        for(int i = n - 1; i >= 0; i--) rep(j, k + 1) {
            if(j) suf[i][j] = max({suf[i][j], suf[i][j - 1], suf[i + 1][j]});
            else suf[i][j] = max({suf[i][j], suf[i + 1][j]});
        }
        rep(i, n) rep(j, k + 1) {
            if(j) pref[i + 1][j] = max({pref[i + 1][j], pref[i + 1][j - 1], pref[i][j]});
            else pref[i + 1][j] = max({pref[i + 1][j], pref[i][j]});
        }
        
        
        int Acc[n + 1]; Acc[0] = 0;
        rep(i, n) Acc[i + 1] = Acc[i] + bool(s[i] == '0');
        // DP es la maxima cantidad de unos
        rep(i, n) repx(j, i, n) {
            ll gasto = Acc[j + 1] - Acc[i];
            if(gasto > k) continue;
            DP[j - i + 1] = max(DP[j - i + 1], max(suf[j + 1][k - gasto], pref[i][k - gasto]));
        }
        rep(i, n + 1) DP[0] = max(DP[0], pref[i][k]);
        
        
        repx(a, 1, n + 1) {
            ll ans = 0;
            repx(len, 0, n + 1) if(DP[len] != -1) ans = max(ans, ll(DP[len]) * ll(a) + ll(len));
            cout<<ans<<' ';
        }
        cout<<'\n';
    }


    return 0;
}