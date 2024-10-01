#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll sum=0;
        ll A[n];
        rep(i,n) { cin>>A[i]; sum+=A[i]; }
        ll B[n];
        ll b=1;
        ll sum2=0;
        rep(i,n){
            ll b=1;
            B[i]=(1<<(int(log2(1e9))));
            for(int j=1;j<=log2(1e9); j++, b<<=1){
                B[i]= (abs(A[i]-b) < abs(A[i]-B[i])? b:B[i]);
            }
            sum2+=2*abs(B[i]-A[i]);
        }
        rep(i,n) cout<<B[i]<<" "; cout<<"\n";
        //cout<<sum<<" "<<sum2<<"\n";
    }



    return 0;
}