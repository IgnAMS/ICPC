#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

ll k;
vector<ll> N(10);


int main(){
    int t; cin>>t;
    while(t--){
        rep(i,10) cin>>N[i];
        cin>>k;
        vector<ll> A(10);
        rep(i,10) A[i]=i;
        bool ans=0;
        do{
            ll sum=0;
            rep(i,10) sum+=A[i]*N[i];
            if(sum<=k) {ans=1; break; } 
        } while(next_permutation(A.begin(), A.end()));
        if(!ans) cout<<-1<<"\n";
        else{
            rep(i,10) cout<<A[i]<<(i<9? " ":"");
        }
        cout<<"\n";

    }


    return 0;
}