#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    vector<ll> A;
    A.push_back(1);
    ll aux=1;
    ll sum=1;
    while(sum<=1e18){
        aux= aux*2+1;
        sum+=aux*(aux+1)/2;
        A.push_back(sum);
    }
    for(ll&v : A) cout<<v<<" "; cout<<"\n";
    //cout<<A.size()<<"\n";
    int t; cin>>t;
    while(t--){
        ll x; cin>>x;
        int l=0, r=A.size()-1;
        //cout<<"x: "<<x<<"\n";
        while(r-l>1){
            int m=(l+r)/2;
            //cout<<A[m]<<"\n";
            if(A[m]>x){
                r=m;
            }
            else{
                l=m;
            }
        }
        cout<<l+1<<"\n";
    }



    return 0;
}