#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef unsigned long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll A[n+1]; rep(i,n+1) cin>>A[i];
        ll d,k; cin>>d>>k;
        ll i=1, acc=0;
        while(acc+i*d<k) { acc+=i*d; i++; }
        ll aux=0;
        rep(j,n+1){
            ll mul=1;
            //rep(k,j) mul*=i;
            //aux+=A[j]*mul;
            aux+=A[j]*pow(i,j);
        }
        cout<<aux<<"\n";
        
        
    }



    return 0;
}