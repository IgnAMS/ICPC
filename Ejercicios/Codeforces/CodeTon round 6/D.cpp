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
        int n; cin>>n;
        vl C(n); rep(i, n) cin>>C[i];
        int k; cin>>k;

        vector<pll> S;
        rep(i, n) {
            while(!S.empty() and S.back().ff >= C[i]) S.pop_back();
            S.pb({C[i], i});
        }
        // for(auto u: S) cout<<u.ff<<' '<<u.ss<<'\n';

        ll ind = 0;
        ll sobra = k % S[0].ff;
        ll compra = k / S[0].ff;
        ll tam = S[0].ff;
        vector<pll> Aux;
        Aux.pb({S[0].ss, compra});
        for(int i = 1; i< S.size(); i++) {
            auto vec = Aux.back();
            ll aux = min(compra, (compra * tam + sobra) / S[i].ff);
            if(aux >= compra) {
                // cout<<"compro "<<compra<<" en "<<S[i].ss<<'\n';
                ind = i;
                sobra = (compra * tam + sobra) % S[i].ff;
                tam = S[i].ff;
                Aux.pb({S[i].ss, compra});
            }
            else {
                aux = min(compra, sobra / (S[i].ff - tam));
                Aux.pb({S[i].ss, aux});
                // cout<<"compro "<<aux<<" en "<<S[i].ss<<'\n';
                compra = aux;
                sobra = sobra % (S[i].ff - tam);
                tam = S[i].ff;
            }
        }
        int i = 0;
        rep(j, n) {
            while(i < Aux.size() and j > Aux[i].ff) i++;
            if(i < Aux.size()) cout<<Aux[i].ss<<' ';
            else cout<<"0 ";
        }
        cout<<'\n';
    }

    return 0;
}   