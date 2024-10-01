#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

long double eps=1e-12;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> A(n); rep(i,n) cin>>A[i];
        int x=n;
        for(int k=n-1;k>=0;x=k--){
            if(A[k]!=k+1) break;
        }
        //cout<<x<<"\n";
        long double ans=0;
        long double big=1.0;
        rep(i,m){
            int a; long double b;
            cin>>a>>b;
            if(a>=x){
                //cout<<"sumo: "<<b*big<<"\n";
                ans+=b*big;
                big*=(1.0-b+eps);
            }
        }
        if(x==0) ans=1.0;
        cout<<setprecision(7)<<fixed<<min((long double)1.000,ans)<<"\n";
    }



    return 0;
}