#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
#define ff first
#define ss second


map<char,pair<int,int>> mapa;

int dist(char a, char b){ 
    return abs(mapa[a].ff-mapa[b].ff)+abs(mapa[a].ss-mapa[b].ss);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<string> X={ "qwertyuiop", "asdfghjkl", "zxcvbnm"};
    rep(i,0,X.size()) rep(j,0,X[i].size()) mapa[X[i][j]]={i,j};
    
    int t; cin>>t;
    while(t--){
        string line; cin>>line;
        int l; cin>>l;
        vector<pair<int,string>> P;
        string aux;
        rep(i,0,l){
            cin>>aux;
            int c=0;
            rep(j,0,line.length()) 
                c+=dist(line[j],aux[j]);
            P.push_back({c,aux});
        }
        sort(P.begin(),P.end());
        rep(i,0,l) cout<<P[i].ss<<" "<<P[i].ff<<"\n";
    }



    return 0;
}