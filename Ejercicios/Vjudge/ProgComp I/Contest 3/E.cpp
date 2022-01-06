#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int n, t;
vector<int> D, S;
double eps = 1e-12;


bool check(double c){
    double time=0;
    rep(i,n) time+=D[i]/(S[i]+c);
    //cout<<c<<" "<<time<<"\n";
    //cout<<bool(time>=t)<<"\n";
    if(time+eps>t) return true;
    return false;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(13);
    cin>>n>>t;
    D.resize(n), S.resize(n);
    rep(i,n) cin>>D[i]>>S[i];
    
    double mini=-1e4;
    rep(i,n) mini=max(mini, -1.0*S[i]);
    double l = mini-eps, r=1e7, m;
    //cout<<mini<<"\n";
    rep(_, 100000){
        m=(l+r)/2;
        //cerr<<l<<" "<<r<<" "<<m<<" "<<bool(check(m))<<"\n";
        if(check(m)) l=m;
        else r=m;
    }
    cout<<(l+r)/2<<"\n";




    return 0;
}