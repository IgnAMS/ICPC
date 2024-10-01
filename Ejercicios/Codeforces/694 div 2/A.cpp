#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll n, x; cin>>n>>x;
        ll sum1 = 0, sum2 = 0;
        ll A[n]; rep(i,n) cin>>A[i];
        rep(i,n){
            sum1 += A[i] ;
            sum2 += A[i]/x + (A[i]%x !=0? 1:0);
        }
        sum1= sum1/x + (sum1%x != 0? 1:0);
        cout<<sum1<<" "<<sum2<<"\n";
    }




    return 0;
}