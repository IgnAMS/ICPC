#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)   
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A(n); rep(i,n) cin>>A[i];
        sort(A.begin(),A.end());
        bool flag=1;
        rep(i,n-1) if(A[i+1]-A[i]>1) flag=0;
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";

    }




    return 0;
}