#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<ll, ll> ii;
#define ff first
#define ss second

double const eps = 1e-10;

int n;
vector<ii> X;

bool cond(double t){
    double maxr=-1e10;
    bool r=0;
    rep(i,n){
        if(X[i].ss>0){ r=1; maxr=max(X[i].ff+X[i].ss*t,maxr); }
        else { if(r && maxr>=X[i].ff+X[i].ss*t) return 1; }
    }
    return 0;
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cout.precision(13);
    X.resize(n);
    rep(i,n) cin>>X[i].ff>>X[i].ss;
    bool flag=0;
    bool posible=0;
    rep(i,n){
        if(X[i].ss>0) flag=1;
        if(X[i].ss<0 && flag) posible=1;
    }

    if(!posible) { cout<<-1<<"\n"; return 0; }

    double l=0, r=2*1e9, m;
    rep(i,60){
        m = (l+r)/2;
        //cout<<m<<"\n";
        if(cond(m)) r=m;
        else l=m;
    }
    cout<<(l+r)/2<<"\n";

    //cout<<time()<<"\n";

    return 0;
}