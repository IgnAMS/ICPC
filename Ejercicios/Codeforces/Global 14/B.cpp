#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    set<ll> S;
    ll s=2;
    while(s<=1e9+1){
        S.insert(s);
        s*=2;
    } 
    s=1;
    while(2*s*s<=1e9+1) { 
        S.insert(2*s*s);
        S.insert(4*s*s);
        s++;
    }
    //for(auto& u:S) cout<<u<<" "; cout<<"\n";


    while(t--){
        int n; cin>>n;
        if(S.count(n)){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }




    return 0;
}