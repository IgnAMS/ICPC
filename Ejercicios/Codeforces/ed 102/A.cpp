#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n,d; cin>>n>>d;
        int A[n];
        bool oc=1;
        rep(i,n) { cin>>A[i]; oc= oc && A[i]<=d; }
        rep(i,n){
            rep(j,n){
                if(i!=j && A[i]+A[j]<=d) oc=1;
            }
        }
        if(oc) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}