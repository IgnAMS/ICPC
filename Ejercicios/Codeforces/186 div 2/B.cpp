#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string linea; cin>>linea;
    int n=linea.length();
    int equal[n];
    int acc[n+1];
    memset(equal,0,sizeof(equal));
    memset(acc,0,sizeof(acc));

    rep(i,n-1) if(linea[i]==linea[i+1]) equal[i]++;
    acc[0]=equal[0];
    for(int i=1;i<=n;i++) acc[i]=equal[i-1]+acc[i-1];
    int m; cin>>m;

    while(m--){
        int a, b; cin>>a>>b; a--,b--;
        //cout<<acc[b]<<" "<<acc[a]<<endl;
        cout<<acc[b]-acc[a]<<endl;
    }

    return 0;
}