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
    ll L, C, N; cin>>L>>C>>N;
    set<ii> S; 
    S.insert(ii(0LL, 1)); S.insert(ii(L, C+4)); // siempre estara este super elemento
    vector<int> Col(C+1, 0); Col[1] = L;
    ll p, x, a, b, suma, m1, m2;
    rep(i, N){
        cin>>p>>x>>a>>b;
        suma = Col[p];
        m1 = (a + suma * suma) % L;
        m2 = (a + (b + suma) * (b + suma)) % L;
        if(m1 > m2) swap(m1, m2);
        auto low = lower_bound(S.begin(), S.end(), ii(m1, 0)); // si o si va
        auto high = upper_bound(S.begin(), S.end(), ii(m2, C+1)); // este es el end
        
        if(low == S.end()) low--; // lo muevo para incluir
        if(low->first > m1) low--;

        vector<ii> E; // iteradores a eliminar
        for(auto it = low; it != high; it++){
            Col[it->second] -= (next(it)->first - it->first); // elimino el segmento
            E.emplace_back(it->first, it->second);
        }
        Col[x] += m2 - m1 + 1;
        ii plow = { low->first, low->second };
        ii phigh = { high->first, prev(high)->second };
        for(auto u : E) S.erase(u); // Elimino las cosas del set
        
        if(plow.ff < m1) {
            S.insert(ii(plow.ff, plow.ss)); // Agrego si eran casos bordes
            Col[plow.ss] += m1 - plow.ff; 
        }
        if(m2 + 1 < phigh.ff){ 
            S.insert(ii(m2 + 1, phigh.ss)); // Agrego si eran casos bordes
            Col[phigh.ss] += phigh.ff - 1 - m2;
        }
        S.insert(ii(m1, x));
    }
    int maxi = 0;
    rep(i, C+1) maxi = max(maxi, Col[i]);
    cout<<maxi<<'\n';
    
    return 0;
}