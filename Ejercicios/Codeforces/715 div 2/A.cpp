#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int A[n]; rep(i,n) cin>>A[i];
        vector<int> imp, par;
        rep(i,n) if(A[i]%2==0) par.push_back(A[i]); else imp.push_back(A[i]);
        rep(i,par.size()) cout<<par[i]<<" ";
        rep(i,imp.size()) cout<<imp[i]<<" ";
        cout<<"\n";
    }






    return 0;

}