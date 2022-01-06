#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ll> S(n); rep(i,n) cin>>S[i];
    sort(S.begin(), S.end());

    int q; cin>>q;
    while(q--){
        ll l, r; cin>>l>>r;
        ll sum=r-l+1;
        //esto es cuadratico, 10^10, no me sirve :c 
        rep(i,n) if(i){
            if(S[i] <= S[i-1]+(r-l+1)) sum-=S[i-1]+(r-l+1)-S[i];
            sum+=r-l+1;
        } 
        cout<<sum<<" ";
    }





    return 0;
}