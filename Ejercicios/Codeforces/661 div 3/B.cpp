#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n],b[n];
        int mina=1e8;
        int minb=1e8;
        for(int i=0;i<n;i++) {cin>>a[i]; mina=min(mina,a[i]);}
        for(int i=0;i<n;i++) {cin>>b[i]; minb=min(minb,b[i]);}
        int cont=0;
        for(int i=0;i<n;i++){
            if(a[i]>mina && b[i]>minb){
                cont+=max(a[i]-mina,b[i]-minb);
                a[i]-=max(a[i]-mina,b[i]-minb);
                b[i]-=max(a[i]-mina,b[i]-minb);
            }
            if(a[i]>mina){
                cont+=a[i]-mina;
                a[i]-=a[i]-mina;
            }
            if(b[i]>minb){
                cont+=b[i]-minb;
                b[i]-=b[i]-minb;
            }
        }
        cout<<cont<<endl;
    }


    return 0;
}