#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

long double eps=1e-6;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        double R,M,B;
        cin>>R>>B>>M;
        int cont=0;
        double rate=1.0+R/100.00;
        double aux2=rate;
        //cout<<setprecision(10)<<fixed<<rate<<"\n";
        ll aux1 = ll(rate*10000+eps); aux2= double(aux1/10000.00);
        rate=aux2;
        //cout<<setprecision(10)<<fixed<<rate<<"\n";
        
        bool flag=1;
        while(B>0){
            cont++;
            B=B*rate-M;
            if(cont>3 and B>1e10) { flag=0; break; }
            double aux2=B;
            ll aux1=ll(B*100+0.50+eps); aux2= double(aux1/100.00);
            B=aux2;
            if(cont>1200) { flag=0; break; }
        }
        if(flag) cout<<cont<<"\n";
        else cout<<"impossible\n";
    }


    return 0;
}