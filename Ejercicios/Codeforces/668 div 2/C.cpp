#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s;
        cin>>s;
        int cont0=0,cont1=0,preg=0;
        bool possible=true;
        rep(i,k){
            if(s[i]=='0') cont0++;
            else if(s[i]=='1') cont1++;
            else preg++;
        }
        if(abs(cont0-cont1)>preg) possible=false;
        for(int i=k;i<n;i++){
            if(s[i]=='0') cont0++;
            else if(s[i]=='1') cont1++;
            else preg++;
            if(s[i-k]=='0') cont0--;
            else if(s[i-k]=='1') cont1--;
            else preg--;
            
            if(abs(cont0-cont1)>preg) possible=false;
        }
        if(possible) cout<<"YES\n";
        else cout<<

    }



    return 0;
}