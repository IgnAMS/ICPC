#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int x;
        vector<ii> A(n); 
        rep(i,n) { cin>>x; A[i]={x,i}; }
        sort(A.begin(),A.end());
        //rep(i,n) cout<<A[i].ss<<"\n";
        int ans=-1;
        rep(i,n){
            bool entro=0;
            while(i+1<n && A[i].ff==A[i+1].ff){
                i++;
                entro=1;
            }
            if(!entro) { ans=A[i].ss+1; break; }
        }
        cout<<ans<<"\n";
        //cout<<"\n";
    }





    return 0;
}


