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
    ll A[n];
    rep(i, n) cin>>A[i];


    vector<vl> X;
    vector<vl> Y;
    // F[i] = indice de X del vector que tiene a i en la posicion mas a la derecha posible
    map<ll, ll> mp;

    rep(i, n) {
        if(!mp.count(A[i] - 1) and !mp.count(A[i])) {
            mp[A[i]] = X.size();
            X.pb({A[i]});
            Y.pb({i});
        }
        if(mp.count(A[i] - 1)) {
            ll ind1 = lower_bound(X[mp[A[i] - 1]].begin(), X[mp[A[i] - 1]].end(), A[i]) - X[mp[A[i] - 1]].begin();
            if(mp.count(A[i])) {
                ll ind2 = lower_bound(X[mp[A[i]]].begin(), X[mp[A[i]]].end(), A[i]) - X[mp[A[i]]].begin();
                if(ind1 >= ind2) {
                    if(X[mp[A[i] - 1]].size() == ind1) {
                        X[mp[A[i] - 1]].pb(A[i]);
                        Y[mp[A[i] - 1]].pb(i);
                        mp[A[i]] = mp[A[i] - 1];
                    }
                }
            }
            else {
                if(X[mp[A[i] - 1]].size() == ind1) {
                    mp[A[i]] = mp[A[i] - 1];
                    X[mp[A[i] - 1]].pb(A[i]);
                    Y[mp[A[i] - 1]].pb(i);
                }
            }
        }
        
        // for(auto vec: X) {
        //     for(auto u: vec) cout<<u<<' '; cout<<'\n';
        // }
        // cout<<'\n';
    }

    ll best = 0;
    rep(i, X.size()) {
        if(X[i].size() > X[best].size()) best = i;
    }
    cout<<Y[best].size()<<'\n';
    for(auto u: Y[best]) cout<<u + 1<<' '; cout<<'\n';




    return 0;
}