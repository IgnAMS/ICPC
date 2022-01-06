#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
#define ff first
#define ss second



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int A[n]; rep(i, n) cin>>A[i];
    map<int,int> mapa;
    multiset<int> S;
    int ans = 1;
    // dos opciones, son todos iguales excepto el ultimo
    rep(i, n){
        if(!mapa.count(A[i])) mapa[A[i]] = 0;
        mapa[A[i]]++;
        if(mapa[A[i]] != 1) 
            S.erase(S.find(mapa[A[i]] - 1)); S.insert(mapa[A[i]]);
        if(S.size() == 1) { ans = i+1; continue; }

        // for(auto u : S) cout<<u<<' '; cout<<'\n';
        // El de mas arriba es mas grande por una unidad
        int aux = *S.rbegin();
        S.erase(S.find(*S.rbegin())); S.insert(aux - 1);
        if(*S.rbegin() == *S.begin()) ans = i+1;
        S.erase(S.find(aux - 1)); S.insert(aux); 

        // El de mas abajo es 1 y el resto son iguales
        aux = *S.begin();
        if(aux != 1) continue;
        S.erase(S.find(*S.begin())); // borro el primero
        if(*S.begin() == *S.rbegin()) ans = i+1;
        S.insert(aux);
    }
    cout<<ans<<'\n';





    return 0;
}