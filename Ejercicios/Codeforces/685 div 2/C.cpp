#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        string a,b; cin>>a>>b;
        int conta[27], contb[27];
        memset(conta,0,sizeof(conta));
        memset(contb,0,sizeof(contb));
        for(char& c: b) contb[c-'a']++;
        for(char& c: a) conta[c-'a']++;
        bool flag=0;
        //rep(i,26) cout<<conta[i]<<" "; cout<<"\n";
        //rep(i,26) cout<<contb[i]<<" "; cout<<"\n";

        for(int i=0;i<26;i++){
            //cout<<i<<" "<<conta[i]<<" "<<contb[i]<<"\n";
            if(conta[i]>=contb[i]){
                if((conta[i]-contb[i])%k!=0) { flag=1; break; }
                conta[i+1]+= (conta[i]-contb[i]);
            }
            else{ flag=1; break; }
        }
        if(flag) cout<<"No\n";
        else cout<<"Yes\n";
    }

    return 0;
}