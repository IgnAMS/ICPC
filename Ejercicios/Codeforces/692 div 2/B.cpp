#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        bool flag=0;
        ll i;
        for(i=n;i<=1e18;i++){
            ll aux=i;
            //cerr<<aux<<"\n";
            while(aux!=0 && aux%10==0) aux/=10;
            while(i%(aux%10)==0){
                //cerr<<"aaaaa\n";
                aux/=10;
                while(aux!=0 && aux%10==0) aux/=10;
                if(aux==0) { flag=1; break; } 
            }
            
            if(flag) break;
        }
        cout<<i<<"\n";
    }



    return 0;
}