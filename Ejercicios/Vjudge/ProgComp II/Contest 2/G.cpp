#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int,char> ic;

int main(){
    int n; cin>>n;
    map<char,int> mapa;
    string str;
    cin>>str;
    set<char> s;
    rep(i,n) s.insert(str[i]);
    set<int> mins;
    int mini=1e7;
    rep(i,n){
        if(!mapa.count(str[i])){
            mapa.insert(make_pair(str[i],i));
            mins.insert(i);
        } 
        else{
            mins.erase(mapa[str[i]]);
            mapa[str[i]]=i;
            mins.insert(i);
        }
        if(s.size() == mapa.size()){
            mini=min(i-*mins.begin()+1,mini);
        }
    }
    cout<<mini<<"\n";

    return 0;
}