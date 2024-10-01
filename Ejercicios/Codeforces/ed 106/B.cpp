#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        string linea; cin>>linea;
        int n=linea.length();
        bool ans=1;
        vector<bool> parceros(n,0);
        for(int i=n-2;i>=0;i--){
            if(linea[i]=='0' && linea[i+1]=='0') parceros[i]=1;
            else parceros[i]=parceros[i+1];
        }
        //rep(i,n) cout<<parceros[i]<<" "; cout<<"\n";
        for(int i=0;i<n-1;i++){
            if(linea[i]=='1' && linea[i+1]=='1' && parceros[i]){
                ans=0;
            }
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }





    return 0;
}