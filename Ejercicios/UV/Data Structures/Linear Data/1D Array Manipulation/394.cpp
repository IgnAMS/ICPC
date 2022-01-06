#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

struct Array{
    vector<ll> C;
    int D;
    Array(ll B, vector<ll> &U, ll d, vector<ll> &L, ll cd){
        C.resize(D+1);
        C[d]=cd;
        D=d;
        for(int i=D-1;i>=1;i--) C[i]= C[i+1]*(U[i+1]-L[i+1]+1);
        
    }
    ll q(vector<ll>& Q){
        ll ans=C[0];
        rep(i,D) ans+=Q[i]*C[i+1];
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    map<string,vector<ll>> mapa;
    string name;
    ll B, cd, D;
    rep(i,n){
        cin>>name>>B>>cd>>D;
        vector<ll> L(D),U(D);
        rep(i,D) cin>>L[i]>>U[i];
        vector<ll> aux(D+1);
        aux[D]=cd;
        for(int i=D-1;i>=1;i--) { 
            aux[i]=aux[i+1]*(U[i]-L[i]+1);
        }
        aux[0]=B; rep(i,D) aux[0]-=aux[i+1]*L[i];
        mapa[name]= aux;
    }
    string aaa;
    while(q--){
        cin>>name;
        vector<ll>& u=mapa[name];
        //rep(i,u.size()) cout<<u[i]<<" "; cout<<"\n";
        vector<ll> aux(u.size()-1);
        rep(i,u.size()-1) cin>>aux[i];
        ll ans=0;
        ans+=u[0];
        rep(i,u.size()-1) ans+=u[i+1]*aux[i];
        //cout<<ans<<"\n";
        cout<<name<<"["; 
        rep(i,aux.size()) cout<<aux[i]<<(i<aux.size()-1? ", ":"");
        cout<<"] = "<<ans<<"\n"; 
    }



    return 0;
}