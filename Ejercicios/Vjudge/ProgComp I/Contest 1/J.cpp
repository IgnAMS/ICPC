#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    string linea; cin>>linea;
    set<char> s;
    rep(i,linea.length()) s.insert(linea[i]);
    
    deque<char> dq;
    map<char,int> mapa;
    int mini=1e8;

    for(int j=0;j<linea.length();j++){
        dq.push_back(linea[j]);
        if(!mapa.count(linea[j])) mapa[linea[j]]=0;
        mapa[linea[j]]++;
        while(!dq.empty() && mapa[dq.front()]>1) { 
            //cout<<dq.front()<<" "<<mapa[dq.front()]<<"\n";
            mapa[dq.front()]--;
            dq.pop_front();
        }
        //for(int i=0;i<dq.size();i++) cout<<dq[i]<<" "; cout<<"\n";

        if(mapa.size()==s.size()) mini=min(mini,(int)dq.size());
    }
    cout<<mini<<"\n";
    




    return 0;
}