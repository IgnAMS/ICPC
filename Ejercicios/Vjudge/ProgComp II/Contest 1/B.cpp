#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin>>n>>q;

    vector<iii> eventos;
    //.ff eje x .ss.ff tipo .ss.ff altura o persona
    //types -> 0 abrir, 1 persona, 2 cerrar
    rep(i,n){
        ll h, si, ti;
        cin>>si>>ti>>h;
        eventos.push_back(iii(2*si-1-2*h, ii(0, h)));
        eventos.push_back(iii(2*ti-1-2*h, ii(2, h)));
    }

    rep(i,q){
        ll h;
        cin>>h;
        eventos.push_back(iii(2*h,ii(1,i)));
    }

    sort(eventos.begin(),eventos.end(),[&](iii &a, iii &b){
        if(a.ff==b.ff) return a.ss.ff < b.ss.ff;
        return a.ff < b.ff;
    });

    ll ans[q];

    multiset<int> xd;
    
    for(auto& x: eventos){
        if(x.ss.ff==0){
            xd.insert(x.ss.ss);
        }
        if(x.ss.ff==1){
            if(xd.size()==0){
                ans[x.ss.ss]=-1;
            }
            else{
                ans[x.ss.ss] = *xd.begin();
            }
        }

        if(x.ss.ff==2){
            xd.erase(xd.find(x.ss.ss));
        }
    }

    rep(i,q) cout<<ans[i]<<endl;



    return 0;
}