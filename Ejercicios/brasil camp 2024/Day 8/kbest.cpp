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


const int mxN = 2e5+5, M = 1e9+7;
ll v[mxN], w[mxN], n, k;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    cin >> n >> k;
    rep(i, n) cin >> v[i] >> w[i];
    db l = 0, r = 1e15;
    rep(_, 80) {
        db m = (l + r) * 0.5;
        vector<pair<db, int>> X;
        rep(i, n) X.pb({db(v[i]) - m * db(w[i]), i});
        sort(X.begin(), X.end());
        reverse(X.begin(), X.end());
        
        db suma = 0;
        rep(i, k) suma += X[i].ff;
        if(suma >= 0) l = m;
        else r = m;
    }
    l = (l + r) * 0.5;
    vector<pair<db, int>> X;
    rep(i, n) X.pb({db(v[i]) - l * db(w[i]), i});
    sort(X.begin(), X.end());
    reverse(X.begin(), X.end());
    
    vl Ans;
    rep(i, k) Ans.pb(X[i].ss);
    // rep(i, n) cout<<X[i].ff<<' '<<X[i].ss<<'\n';
    sort(Ans.begin(), Ans.end());
    rep(i, k) cout<<Ans[i] + 1<<" \n"[i == k - 1];  
    return 0;
}