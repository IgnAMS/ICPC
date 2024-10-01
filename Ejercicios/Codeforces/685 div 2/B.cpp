#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, q; cin>>n>>q;
        string s; cin>>s;
        while(q--){
            int l,r; cin>>l>>r; l--, r--;
            bool flag=0;
            for(int i=0;i<l;i++) if(s[i]==s[l]) flag=1;
            for(int i=r+1;i<n;i++) if(s[i]==s[r]) flag=1;
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

    return 0;
}