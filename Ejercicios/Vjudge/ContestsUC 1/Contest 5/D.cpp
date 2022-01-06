#include<bits/stdc++.h>
using namespace std; 
#define rep(i,n) for(int i=0;i<n;i++)

int k, n;
vector<int> aux,N;
set<vector<int>> Set;
vector<vector<int>> ans;
vector<bool> D;

void backtracing(int i, int s){
    if(s==k && !Set.count(aux)) {Set.insert(aux); ans.push_back(aux); return;}
    if(i>=n || s>k) return;
    for(int h=i;h<n;h++) if(!D[h]){
        aux.push_back(N[h]);
        D[h]=true;
        
        backtracing(h+1,s+N[h]);
        
        aux.pop_back();
        D[h]=false;
    }
    return;

}

int main(){
    while(cin>>k>>n){
        aux.clear();
        ans.clear();
        Set.clear();
        D.assign(n,false);
        N.resize(n);
        rep(i,n) cin>>N[i];
        sort(N.begin(),N.end(),greater<int>());
        //rep(i,n) cout<<N[i]<<" ";
        //cout<<endl;
        backtracing(0,0);
        cout<<"Sums of "<<k<<":"<<endl;
        if(ans.size()==0){ cout<<"NONE"<<endl; continue;}
        for(auto x: ans){
            for(int i=0;i<x.size();i++){
                cout<<x[i];
                if(i<x.size()-1) cout<<"+";
            }
            cout<<endl;
        }
    }


    return 0;
}