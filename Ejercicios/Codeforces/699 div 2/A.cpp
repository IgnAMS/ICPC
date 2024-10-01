#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int px,py; cin>>px>>py;
        string s; cin>>s;
        int U=0, D=0, R=0, L=0;
        rep(i,s.length()) {
            if(s[i]=='U') U++;
            if(s[i]=='D') D++;
            if(s[i]=='R') R++;
            if(s[i]=='L') L++;
        }
        if((px<0? L>=-px:R>=px) && (py<0? D>=-py:U>=py)) cout<<"YES\n";
        else cout<<"NO\n";
    }




    return 0;
}