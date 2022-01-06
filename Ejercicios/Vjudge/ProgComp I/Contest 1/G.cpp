#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,ii> seg;
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<seg> X,Y;
    rep(i,0,4){
        ii a, b; cin>>a.ff>>a.ss>>b.ff>>b.ss;
        if(a.ff==b.ff) Y.push_back({min(a,b),max(a,b)}); //mismo x, por ende paralelo a Y
        else if(a.ss==b.ss) X.push_back({min(a,b),max(a,b)}); //mismo Y, por ende paralelo a X
    }
    if(X.size()!=2 || Y.size() !=2 || 
       X[0].ff.ss==X[1].ff.ss || Y[0].ff.ff==Y[1].ff.ff) {
        //no perpendicular o sin area
        cout<<"NO\n"; 
        return 0;
    }
    //X.ff sería el segmento de abajo y ss el de arriba
    //Y.ff seria el segmento de arriba de 
    sort(X.begin(),X.end()); sort(Y.begin(),Y.end());
    if(X[0].ff==Y[0].ff && X[0].ss==Y[1].ff && X[1].ff==Y[0].ss && X[1].ss==Y[1].ss)
        cout<<"YES\n";
    else cout<<"NO\n";



}