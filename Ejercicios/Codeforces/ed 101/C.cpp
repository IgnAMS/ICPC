#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        ll H[n]; rep(i,n) cin>>H[i];
        ll prev=H[0];
        ll next= H[0]+k-1;
        bool flag=1;
        for(int i=1;i<n;i++){
            //cout<<"el elemento "<<i+1<<" puede estar entre: "<<prev<<" y "<<next<<"\n";
            if(!(prev <= H[i] && H[i] <= next)) { 
                //cout<<"fallo en: "<<i<<"\n";
                flag=0;
            }
            int aux=prev;
            if(H[i-1]-2*(k-1)==H[i]){
                prev=H[i];
                next=H[i]+2*(k-1);
                continue;
            }
            
            prev= max({ll(0),H[i]-2*(k-1),prev-(k-1)});
            next= min(next+(k-1),H[i]+2*(k-1));
            prev= min(prev,H[i]+k-1);
        }
        cout<<(flag? "YES\n":"NO\n");
    }



    return 0;
}