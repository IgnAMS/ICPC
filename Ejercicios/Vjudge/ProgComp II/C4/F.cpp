#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
vector<vector<int>> g;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        g.assign(n,{});
        vector<vector<int>> groups;
        int ans=0;
        rep(i,n){
            int k; cin>>k; int aux;
            rep(j,k) { cin>>aux; g[i].push_back(aux-1); }
            if(k==0) {ans++; continue;}
            vector<int> lit=g[i]; lit.push_back(i);
            groups.push_back(lit);
        }
        

    }



    return 0;
}