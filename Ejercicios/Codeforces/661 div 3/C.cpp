#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; 
        cin>>n;
        ll conts[51],a[50];
        memset(conts,0,sizeof(conts));
        for(int i=0;i<n;i++) {cin>>a[i];conts[a[i]]++;}
        ll cont=0;
        ll maxi=0;

        for(int i=2;i<=100;i++){
            cont=0;
            int j=1;
            if(i>51){
                j=i-50;
            }
            for(;j<=i/2;j++){
                if(1<=i-j && i-j<=50){
                    if(i-j==j) {
                        cont+=conts[j]/2;
                    }
                    else{
                        cont+=min(conts[j],conts[i-j]);
                    } 
                }
            }
            maxi=max(maxi,cont);
            
        }
        //cout<<"imrpime algo?"<<endl;
        cout<<maxi<<endl;
    }

    return 0;
}