#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n1; cin>>n1;
        ll A[n1+1]; rep(i,n1+1) cin>>A[i];
        int n2; cin>>n2;
        ll B[n2+1]; rep(i,n2+1) cin>>B[i];
        //cout<<n1<<"\n"; rep(i,n1+1) cout<<A[i]<<" "; cout<<"\n";
        ll C[n1+n2+1]; memset(C,0,sizeof(C));
        rep(i,n1+1) rep(j,n2+1){
            C[i+j] += A[i]*B[j]; 
        }
        cout<<n1+n2<<"\n";
        rep(i,n1+n2+1) cout<<C[i]<<" "; cout<<"\n";
    }




    return 0;
}