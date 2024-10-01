#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int c1=0, c2=0;
        bool flag=0;
        int ans=0;
        for(int i=0; i<s.length(); i++){
            char c=s[i];
            if(c=='(') c1++;
            if(c=='[') c2++;
            if(c==')'){
                if(c1>0) ans++;
                c1--;
            }
            if(c==']'){
                if(c2>0) ans++;
                c2--;
            }
            if(c1<0) c1=0;
            if(c2<0) c2=0;
        }
        cout<<ans<<"\n";
    }



    return 0;
}
