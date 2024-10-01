#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define ff first
#define ss second

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int h; 
        map<int,int> mapa;
        rep(i,n){
            cin>>h;
            if(!mapa.count(h)) mapa[h]=0;
            mapa[h]++;
        }
        int cont=0;
        int last=0; //los que he matado hasta ahora
        vector<int> vec;
        for(auto& u: mapa) vec.push_back(u.ss);
        sort(vec.begin(),vec.end(),greater<int>());
        for(int& u:vec){
            last += 
            cont=abs(cont-u);
        }
        cout<<cont<<"\n";
    }




    return 0;
}