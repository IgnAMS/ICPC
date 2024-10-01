#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,x; cin>>n>>x;

    ll arr[n];
    ll sum=0;
    rep(i,n) cin>>arr[i];
    ll accmin=0;
    ll kadmin=0;
    ll accmax=0;
    ll kadmax=0;
    int lmin=0,rmin=0,s1=0;
    int lmax=0,rmax=0,s2=0;

    rep(i,n){
        if(accmax>kadmax){
            rmax=i;
            lmax=s1;
            kadmax=accmax;
        }
        if(accmin<kadmin){
            rmin=i;
            lmin=s2;
            kadmin=accmin;
        }
        accmax+=arr[i];
        accmin+=arr[i];
        if(accmax<0){
            accmax=0;
            s1=i+1;
        }
        if(accmin>0){
            accmin=0;
            s2=i+1;
        }
    }
    if(accmin<kadmin){
        rmin=n-1;
        lmin=s2;
        kadmin=accmin;
    }
    if(accmax>kadmax){
        rmax=n-1;
        lmax=s1;
        kadmax=accmax;
    }

    if(x==0) {cout<<kadmax<<endl; return 0;}
    
    if(x>0){
        for(int i=lmax && kadmax!=0;i<=rmax;i++) arr[i]*=x;
    }
    else{
        for(int i=lmin;i<=rmin && kadmin!=0 ;i++) arr[i]*=x;
    }

    //rep(i,n) cout<<arr[i]<<" "; cout<<endl;

    kadmax=0, accmax=0;
    rep(i,n){
        kadmax=max(kadmax,accmax);
        accmax+=arr[i];
        if(accmax<0) accmax=0;
    }
    kadmax=max(kadmax,accmax);

    cout<<kadmax<<endl;
    

    return 0;
}