#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, m, d; cin>>n>>m>>d;
        int mini = min(n,m); // cantidad maxima de pockets
        int sobra = abs(n-m)/mini + bool(abs(n-m)%mini);
        if(sobra > d) cout<<"NO\n";
        else cout<<"YES\n";

    }




    return 0;
}