#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    int n; cin>>n;
    vector<int> a(n),b(n),pos(n+1);
    rep(i,n) cin>>a[i];
    rep(i,n) {cin>>b[i]; pos[b[i]]=i;}
    
    //conts[dif]++ si tienen la misma dif
    vector<int> conts(n,0);
    int maxi=0;
    rep(i,n){
        int dif=(i-pos[a[i]]);
        if(dif<0) dif+=n;
        conts[dif]++;
        maxi=max(maxi,conts[dif]);
    }

    cout<<maxi<<"\n";



    return 0;
}