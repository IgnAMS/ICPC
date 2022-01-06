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
    ll L, C, N; 
    while(cin>>L and cin>>C>>N){
        //cerr<<L<<' '<<C<<' '<<N<<'\n';
        set<ii> S; 
        S.insert(ii(0LL, C));
        vector<int> Col(C+1, 0); Col[C] = L;
        //for(auto u : S) cout<<u.ff<<' '<<u.ss<<" - "; cout<<'\n';
        rep(i, N){
            ll p, x, a, b; cin>>p>>x>>a>>b;
            ll suma = Col[p];
            ll m1 = (a + suma * suma) % L;
            ll m2 = (a + (b + suma) * (b + suma)) % L;
            if(m1 > m2) swap(m1, m2);
            auto low = lower_bound(S.begin(), S.end(), ii(m1, 0)); // si o si va
            auto high = upper_bound(S.begin(), S.end(), ii(m2, 0)); // este es el end
            
            if(low == S.end()) low--; // lo muevo para incluir el rango
            if(low->first > m1) low--;

            vector<ii> E; // iteradores a eliminar
            for(auto it = low; it != high; it++){
                int aux = next(it) == S.end()? L-1 : next(it)->first;
                Col[it->second] -= (min(aux, int(m2)) - max(it->first, int(m1)) + 1); // elimino el rango
                E.emplace_back(it->first, it->second);
            }
            Col[x] += m2 - m1 + 1;
            ii plow = { low->first , low->second };
            int aux = high == S.end()? L: high->first;
            ii phigh = { aux, prev(high)->second };
            for(auto u : E) S.erase(u); // Elimino las cosas del set

            if(plow.ff + 1 < m1) S.insert(ii(plow.ff, plow.ss)); // Agrego si eran casos bordes
            if(m2 + 1 < phigh.ff) S.insert(ii(m2 + 1, phigh.ss)); // Agrego si eran casos bordes
            S.insert(ii(m1, x));
            //for(auto u : S) cout<<u.ff<<' '<<u.ss<<" - "; cout<<'\n';
            //rep(i, C+1) cout<<Col[i]<<' '; cout<<"\n\n";
        }
        int maxi = 0;
        rep(i, C+1) maxi = max(maxi, Col[i]);
        cout<<maxi<<'\n';
    }
    return 0;
}