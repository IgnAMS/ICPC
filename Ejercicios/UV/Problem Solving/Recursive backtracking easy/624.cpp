#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int t, n;
vector<int> cd;
vector<int> ans;
vector<int> aux;
vector<bool> v;
int maxi=0;
void backtrack(int sum, int x){
    if(x==n){
        if(sum>maxi){
            ans=aux;
            maxi=sum;
        }
        return;
    }
    //no lo tomo
    backtrack(sum,x+1);
    //lo tomo
    if(cd[x]+sum <= t){
        aux.push_back(cd[x]);
        backtrack(sum+cd[x],x+1);
        aux.pop_back();
    }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>t>>n){
        cd.resize(n); rep(i,n) cin>>cd[i];
        v.assign(n,0);
        ans.clear(); aux.clear();
        maxi=0;
        backtrack(0,0);
        int time=0;
        rep(i,ans.size()){
            cout<<ans[i]<<" ";
            time+=ans[i];
        }
        cout<<"sum:"<<time<<"\n";
    }   



    return 0;
}