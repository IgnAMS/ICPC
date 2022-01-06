#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int d; cin>>d;
        string names[d];
        int l[d],r[d];
        rep(i,d) cin>>names[i]>>l[i]>>r[i];
        int q; cin>>q;
        while(q--){
            int cont=0;
            string ans;
            int h; cin>>h;
            rep(i,d) if(l[i]<=h && h<=r[i]) { ans=names[i]; cont++; }
            if(cont!=1) cout<<"UNDETERMINED\n";
            else cout<<ans<<"\n";
        }
        if(t!=0) cout<<"\n";
    }


    return 0;
}