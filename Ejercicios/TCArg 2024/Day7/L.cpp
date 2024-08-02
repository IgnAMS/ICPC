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
    ll n, x; cin>>n>>x;
    if(n <= x) {
        cout<<"-1\n";
        return 0;
    }
    // n > x
    set<pll> X;
    set<ll> S[n];
    set<ll> P[n];
    rep(i, n) {
        X.insert({x, i});
        repx(j, i * x, (i + 1) * x) P[i].insert(j);
    }

    rep(i, n) {
        bool auto_insert = 0;
        vector<pll> Houses;
        // Obtengo las casas con mayores
        rep(j, x) {
            auto [cont, house] = *X.rbegin();
            // cout<<"miro la casa "<<house<<" con "<<cont<<" perros para asignar a la casa "<<i<<'\n'; 
            X.erase(*X.rbegin());
            if(house == i) {
                j--;
                auto_insert = 1;
                continue;
            }
            Houses.pb({cont, house});
        }

        
        for(auto [cant, house]: Houses) {
            ll x = *P[house].begin();
            // cout<<"consigo el perro "<<x<<" de la casa "<<house<<" para asignarlo en la casa "<<i<<'\n';
            P[house].erase(x);
            S[i].insert(x);
            X.insert({cant - 1, house});
        }

        if(auto_insert) {
            X.insert({P[i].size(), i});
        }
    }
    rep(i, n) {
        repx(j, x * i, (i + 1) * x) cout<<j + 1<<' ';
        for(auto u: S[i]) cout<<u + 1<<' ';
        cout<<'\n';
    }







    return 0;
}