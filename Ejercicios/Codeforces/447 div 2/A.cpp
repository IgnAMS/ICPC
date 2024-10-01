#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    string linea; cin>>linea;
    int n=linea.length();
    int contq=0;
    int Qs[n];
    memset(Qs,0,sizeof(Qs));
    Qs[n-1]= linea[n-1]=='Q'? 1:0;

    for(int i=n-2;i>=0;i--){
        Qs[i]=Qs[i+1]+ (linea[i]=='Q'? 1:0);
    }
    
    bool q=false;
    ll ans=0;
    vector<int> As;
    rep(i,n){   
        if(linea[i]=='A'){
            As.push_back(i);
        }
    }
    rep(i,n-1){

        if(linea[i]=='Q'){
            for(auto x: As){
                if(x>i){
                    ans+=Qs[x];
                }
            }
        } 
    }
    cout<<ans<<endl;


    return 0;
}