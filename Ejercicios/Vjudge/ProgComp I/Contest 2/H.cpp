#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int a,b; cin>>a>>b;
    int maxi=0;
    int aux=a;
    while(aux){
        maxi=max(aux%10,maxi);
        aux/=10;
    }
    aux=b;
    while(aux){
        maxi=max(aux%10,maxi);
        aux/=10;
    }
    maxi=max(maxi+1,2);
    //consigo la minima base
    int C[int(1e5)]; memset(C,0,sizeof(C));
    //rep(i,int(1e5)) cout<<C[i]<<" "; cout<<"\n";
    int c=0;
    while(a || b){
        C[c]+=(a%10)+(b%10);
        if(C[c]>=maxi) { C[c+1]++; C[c]%=maxi; } 
        a/=10, b/=10;
        c++;
    }
    //cout<<C[0]<<" "<<C[1]<<" "<<C[2]<<"\n";
    cout<<c+bool(C[c]>0)<<"\n";



}