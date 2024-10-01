#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        n = 2*n;
        vector<int> A(n); rep(i,n) cin>>A[i];
        sort(A.begin(), A.end());
        vector<int> B(n);
        rep(i, (n+1)/2){
            B[2*i] = A[i];
        }
        rep(i,n - (n+1)/2 ){
            B[2*i+1] = A[(n+1)/2 + i];
        }
        rep(i,n) cout<<B[i]<<" "; cout<<"\n";
    }






    return 0;
}