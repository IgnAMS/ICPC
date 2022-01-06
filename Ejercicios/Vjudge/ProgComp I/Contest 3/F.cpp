#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int n;
vector<ll> X, V; 

bool check(double t){
    double mini= X[0]-V[0]*t, maxi=X[0]+V[0]*t;
    rep(i,n) if(i){
        if(X[i]+V[i]*t < mini || maxi < X[i]-V[i]*t) return 0;
        mini=max(X[i]-V[i]*t, mini);
        maxi=min(X[i]+V[i]*t, maxi);
    }
    return 1;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(10);
    cin>>n; X.resize(n); V.resize(n);
    rep(i,n) cin>>X[i]; rep(i,n) cin>>V[i];

    double l=0, r=2e9, m;
    rep(_, 60){
        m=(l+r)/2;
        if(check(m)) r=m;
        else l=m;
    }
    cout<<(l+r)/2<<"\n";




    return 0;
}