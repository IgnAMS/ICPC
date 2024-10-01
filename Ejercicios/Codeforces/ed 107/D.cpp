#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin>>n>>k;
    int cont=0;
    for(char c='a';c<'a'+k;c++){
        rep(i,3) if(cont++<n) cout<<c;
    }
    map<char, set<char>> mapa;
    rep(i,k) rep(j,k) if(i!=j && j!=i+1) {
        mapa[char('a'+i)].insert(char('a'+j));
        //cout<<"\n"<<char('a'+i)<<" "<<char('a'+j)<<"\n";
    }
    
    char d='a'+k-1;
    while(cont++<n && mapa.size()>0){
        char aux='.';
        for(auto& u: mapa[d]){
            if(mapa.count(u)) { aux=u; break; }
        }
        if(aux=='.') aux=*mapa[d].begin();
        cout<<aux;
        mapa[d].erase(aux); 
        if(mapa[d].size()==0) mapa.erase(d);
        d=aux;
    }
    while(cont++<n) cout<<'a';
    cout<<"\n";

    



    return 0;
}