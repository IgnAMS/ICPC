#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    while(cin>>n && n){
        vector<string> s(n); 
        int mini=1e5;
        int ans=0;
        getline(cin,s[0]);
        rep(i,n){
            getline(cin,s[i]);
            int j=0;
            int l,r;
            while(j<25 && s[i][j]=='X') j++;
            l=j;
            if(j==24) { mini=0; continue; }
            while(j<25 && s[i][j]!='X') j++;
            mini=min(mini,j-l);
            ans+=j-l;
        } 
        cout<<ans-mini*n<<"\n";
        
    }


    return 0;
}