#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<ll> ans;
    vector<ll> A(50,0);
    A[0]=1;
    ll top=1;
    ll sq=2;
    ll xd=2;
    ll cont=0;
    while(cont++<50){
        bool cond=1;
        while(cond){
            rep(i,top){
                if(A[i]+xd == sq*sq) { 
                    //cout<<"en "<<i<<" puedo colocar a "<<xd<<"\n";
                    A[i]=xd++; 
                }
            }
            cond=0;
            rep(i,top) if(A[i]+xd == sq*sq) cond=1;
            
            rep(i,top) if(!cond && A[i]+xd==(sq+1)*(sq+1)) { sq++; cond = 1; }
            
        }
        //cout<<xd-1<<"\n";
        ans.push_back(xd-1);
        if(top<50) { 
            //cout<<"coloco a "<<xd<<" en "<<top<<"\n"; 
            A[top++]=xd++; 
        }
    }
    //rep(i,ans.size()) cout<<i+1<<" "<<ans[i]<<"\n";
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<ans[n-1]<<"\n";
    }


    return 0;
}