#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        map<char, int> mapa;
        deque<char> dq;
        int ans= 200000 +5;
        rep(i,s.size()){
            dq.push_back(s[i]);
            if(!mapa.count(dq.back())) mapa[dq.back()]=0;
            mapa[dq.back()]++;
            while(!dq.empty() && mapa[dq.front()] > 1) { mapa[dq.front()] --; dq.pop_front(); }
            if(mapa.size()==3) ans=min(ans, int(dq.size()));
        }
        if(ans==200000+5) cout<<0<<"\n";
        else cout<<ans<<"\n";

    }

    return 0;
}