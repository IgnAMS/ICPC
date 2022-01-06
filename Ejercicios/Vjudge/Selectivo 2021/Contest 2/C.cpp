#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<char> s(n), t(n);
    rep(i,n) cin>>s[i];
    rep(i,n) cin>>t[i];
    vector<int> ans;
    rep(i,n){
        if(t[i]!=s[i]){
            int j=i;
            while(s[j]!=t[i] && j<n) j++;
            if(j==n){
                cout<<-1<<"\n";
                return 0;
            }

            for(int k=j; k>i; k--) {
                swap(s[k],s[k-1]);
                ans.push_back(k);
                if(ans.size()>10000){
                    cout<<-1<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<ans.size()<<"\n";
    rep(i,ans.size()) cout<<ans[i]<<" "; cout<<"\n";






    return 0;
}