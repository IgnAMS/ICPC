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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pll> X(n);
    rep(i, n) cin>>X[i].ff;
    rep(i, n) cin>>X[i].ss;
    sort(X.begin(), X.end());

    db l = 0, r = 1e9;
    // cout<<100 * 60000 * log2(60000)<<'\n';
    rep(_, 100) { 
        double m = (l + r) * 0.5;
        vector<pair<db, int>> E;
        rep(i, n) {
            E.pb({X[i].ff - X[i].ss * m, 0});
            E.pb({X[i].ff + X[i].ss * m, 1});
        }  
        sort(E.begin(), E.end());
        ll cont = 0;
        bool pos = 0;
        for(auto e: E) {
            if(e.ss == 0) cont++;
            else cont--;
            if(cont == n) pos = 1;
        }
        // cout<<m<<' '<<pos<<'\n';
        if(pos) r = m;
        else l = m;
    }
    cout<<setprecision(7)<<fixed<<(l + r) * 0.5<<'\n';







    return 0;
}