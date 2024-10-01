#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second



int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A(n); 
        rep(i, n) cin>>A[i]; 
        bool oc = 1;
        int ans = 0;
        int imp = 0, par = 0;
        rep(i, n){
            if(A[i] % 2 and i % 2 == 0) imp++;
            if(A[i] % 2 == 0 and i % 2) par++; 
        }
        if(par == imp) cout<<imp<<'\n';
        else cout<<"-1\n";


    }

    return 0;
}