#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

struct CustomCompare{
    bool operator()(const int& l, const int& r){
        return l%2 > r%2;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, l, r; cin>>n>>l>>r;
        multiset<int> L, R;
        rep(i,l) { int c; cin>>c; L.insert(c-1); }
        rep(i,r) { int c; cin>>c; R.insert(c-1); }

        // primero matare los que tienen costo 0
        queue<int> q;
        for(auto& u: L){
            if(R.count(u)) { q.push(u); R.erase(R.find(u)); }
        }
        while(!q.empty()) { L.erase(L.find(q.front())); q.pop(); }

        int ans=0;
        vector<int> CL(n, 0), CR(n, 0);
        for(auto& u: L) CL[u]++;
        for(auto& u: R) CR[u]++;
        int impL=0, impR=0;
        rep(i,n) impL+=CL[i]%2, impR+=CR[i]%2;
        int aux1=min(impL, impR), aux2=min(impL, impR);
        rep(i,n) { 
            if(CL[i]%2==1 && aux1) aux1--, CL[i]--;
            if(CR[i]%2==1 && aux2) aux2--, CR[i]--;
        }
        // elimine min imp pares cambiando sus colores, en algun par todos son pares
        ans+=min(impL, impR);
        int sumL=0, sumR=0;
        rep(i,n) sumL+=CL[i], sumR+=CR[i];
        ans+=min(sumL, sumR);
        aux1=min(sumL, sumR), aux2=min(sumL, sumR);
        // elimino una fila
        rep(i,n) { 
            if(CL[i]%2==1 && aux1) aux1--, CL[i]--;
            if(CR[i]%2==1 && aux2) aux2--, CR[i]--;
        }
        rep(i,n){
            int u1=aux1, u2=aux2;
            aux1= max(0, aux1-CL[i]), CL[i]= max(0, CL[i]-u1);
            aux2= max(0, aux2-CR[i]), CR[i]= max(0, CR[i]-u2);
        }

        rep(i,n){
            ans+= CL[i]/2 + CL[i]%2;
            ans+= CR[i]/2 + CR[i]%2;
        }
        
        cout<<ans<<"\n";
    }
}