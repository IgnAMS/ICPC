#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


struct FenwickTree{
    vector<ll> FT;
    FenwickTree(int n, ll c) { FT.resize(n+2);}

    ll query(int i){
        ll ans=0;
        for(; i; i-= i&(-i)){
            ans+=FT[i];
        }
        return ans;
    }

    ll query(int i, int j) {
        return query(j)-query(i-1); 
    }
    
    void update(int i, ll v){
        ll s = 0; //query puntual y update por rango
        //ll s = query(i,i); query -> rango y updates puntuales?
        for(; i<FT.size(); i += i&(-i)){
            FT[i] += v-s;
        }
    }

    void update(int i, int j, ll v){
        update(i,v);
        update(j+1,-v);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m,c;
    cin>>n>>m>>c;
    FenwickTree F= FenwickTree(n,c);

    while(m--){
        char car;
        ll u,v,k;
        cin>>car;
        if(car=='S'){
            cin>>u>>v>>k;
            F.update(u,v,k);
        }
        if(car=='Q'){
            cin>>u;
            cout<<c+F.query(u)<<"\n";
        }
    }



    return 0;
}