#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 C.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, l, k; cin>>n>>l>>k;
    vi X(n+1); rep(i, n) cin>>X[i]; X[n] = l;
    vi V(n); rep(i, n) cin>>V[i];
    set<vi> S;
    map<ll, ll> mapa;
    repx(i, 1, n){
        ll dist = X[i+1] - X[i];
        S.insert({dist * (V[i-1] - V[i]), i});
        cout<<"anado "<<dist * (V[i-1] - V[i])<<'\n';
        cout<<dist<<' '<< (V[i-1] - V[i])<<'\n';
        mapa[i] = dist * (V[i] - V[i-1]);
    }
    ll ans = 0;
    rep(i, n) ans += (X[i+1] - X[i]) * V[i];
    vi L(n), R(n), E(n); 
    rep(i, n) L[i] = i-1;
    rep(i, n) R[i] = i+1;
    rep(i, k) if(!S.empty()){
        vi aux = *S.begin();
        if(aux[0] < 0){
            cout<<"gano: "<<aux[0]<<'\n';
            ans += aux[0];
            int x = aux[1];
            R[L[aux[1]]] = R[aux[1]];
            if(L[aux[1]] != 0){
                ll dist = X[R[aux[1]]] - X[L[aux[1]]];
                ll dv = V[L[L[aux[1]]]] - V[L[aux[1]]];
                cerr<<"L[x]: "<<L[aux[1]]<<'\n';
                S.insert({dist * dv, L[aux[1]]});
                cout<<"el nuevo seg "<<L[aux[1]]<<' '<<R[aux[1]]<<' '<<dist * dv<<'\n';
                cerr<<L[aux[1]]<<' '<<aux[1]<<'\n';
                S.erase(S.find({mapa[L[aux[1]]], L[aux[1]]}));
                cerr<<"aca muero\n";
                mapa[L[aux[1]]] = dist * dv;
                cerr<<"esto lo mata???\n";
            }
            cerr<<"adio\n";
            S.erase(S.find(aux));
            cerr<<"termine\n";
        }
    }
    cout<<ans<<'\n';





    return 0;
}