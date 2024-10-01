#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string linea; cin>>linea;
        int T=0, M=0;
        bool inv=0;
        rep(i,n){
            if(linea[i]=='T') T++;
            if(linea[i]=='M') { 
                M++;
                if(T<M) inv=1;
            }
        }
        T=0, M=0;
        for(int i=n-1;i>=0;i--){
            if(linea[i]=='T') T++;
            if(linea[i]=='M') { 
                M++;
                if(T<M) inv=1;
            }
        }
        if(2*M == T && !inv) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}