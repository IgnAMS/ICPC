#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int x=n/k;
        int asd=0;
        rep(i,x){
            rep(i,k) cout<<(asd==0? 'a': asd==1? 'b':'c');
            asd= (asd+1)%3;
        }
        rep(i,n-k*x) cout<<(asd==0? 'a': asd==1? 'b':'c');
        cout<<"\n";
    }



    return 0;
}