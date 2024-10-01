#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        map<int,int> p; //distrito -> indice
        map<int,vector<int>> mapa; //distrito -> {lugares}
        rep(i,n){
            cin>>arr[i];
            if(!p.count(arr[i])){
                p.insert({arr[i],i});
            }
            mapa[arr[i]].push_back(i);
        }
        if(p.size()==1) {cout<<"NO\n"; continue;}
        int cit0= (p.begin()->ff);
        int cit2= (p.rbegin()->ff);
        vector<ii> ans; 
        for(auto& u: mapa){
            if(u.ff == cit0) continue;
            for(auto& v: u.ss){
                ans.push_back({p[cit0],v});
            }
        }
        for(auto& u: mapa[cit0]){
            if(u == p[cit0]) continue;
            ans.push_back({p[cit2],u});
        }
        cout<<"YES\n";
        rep(i,ans.size()){
            cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<"\n";
        }
    }



    return 0;
}