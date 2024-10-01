#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, m, k; cin>>n>>m>>k;
        int ans = (n-1)*1 + (m-1)*n;
        if(ans==k) cout<<"YES\n";
        else cout<<"NO\n";
    }




    return 0;
}