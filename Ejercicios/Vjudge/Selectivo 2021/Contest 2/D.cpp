#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int, int> ii;
#define ff first
#define ss second

double eps =1e-5;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    vector<ii> A(4), B(4);
    int minx=1000, miny=1000, maxx=-1000, maxy=-1000;
    rep(i,4) {
        cin>>A[i].ff>>A[i].ss;
        minx= min(minx,A[i].ff); maxx=max(maxx, A[i].ff);
        miny= min(miny, A[i].ss); maxy=max(maxy, A[i].ss);
    }
    rep(i,4) cin>>B[i].ff>>B[i].ss;
    
    bool ans=0;

    rep(i,4){
        //chequeo si un vertice está en su dominio
        if(minx <= B[i].ff  && B[i].ff <= maxx && miny<= B[i].ss && B[i].ss <=maxy) ans=1;
    }

    

    rep(i,4){
        //cout<<"iteracion: "<<B[i].ff<<" "<<B[i].ss<<"\n";
        ii posi=B[i];
        ii posf=B[(i+1)%4];
        //cout<<posi.ff<<" "<<posi.ss<<"\n";
        int dy= B[(i+1)%4].ss-B[i].ss>0? 1:-1;
        int dx= B[(i+1)%4].ff-B[i].ff>0? 1:-1;
        while(dx>0? posi.ff<=posf.ff: posi.ff>=posf.ff){
            //cerr<<posi.ff<<" "<<posi.ss<<"\n";
            cout<<posi.ff<<" "<<posi.ss<<"\n";
            if(minx<=posi.ff && posi.ff<=maxx && miny<=posi.ss && posi.ss<=maxy) ans=1;
            posi.ff+= dx, posi.ss+=dy;
        }
    }
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";




    return 0;
}