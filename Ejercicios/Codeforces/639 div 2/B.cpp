#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    vector<ll> pir;
    pir.push_back(2);
    for(ll i=2; ll(pir[i-2]+3*i-1)<=1e10; i++){
        pir.push_back(pir[i-2]+(i-1)+2*i);
    } 
    int s=pir.size();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int cont=0;
        while(n>=2){
            cont++;
            int l=0;
            int r=s-1;
            int m;
            while(l<r){
                m=(l+r)/2;
                if(pir[m]>n){
                    r=m;
                }
                else{
                    l=m+1;
                }
            }
            //r sera el primero que es mayor 
            //por ende r-1 es el primero que sera menor o igual
            //cout<<n<<" "<<pir[r-1]<<endl;
            n-=pir[r-1];
        }
        cout<<cont<<endl;
        
    }

    return 0;
}