#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
ll k;
ll A[10],N[10];
bool D[10]; 
bool backtrack(ll i, ll s){
    if(s>k) return false;
    if(i==10 && s<=k) return true;
    rep(d,10) if(!D[d]){
        A[i]=d; D[d]=true;
        //cout<<s<<" "<<d<<" "<<i<<endl;
        if(backtrack(i+1,s+d*N[i])) return 1;
        D[d]=false;
    } 
    return false;
}


int main(){
    int t; cin>>t;
    while(t--){
        rep(i,10) cin>>N[i];
        cin>>k;
        if(backtrack(0,0)){
            rep(i,10) cout<<A[i]<<" ";
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }


    return 0;
}