#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
#define ff first
#define ss second




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int k = 2;
        map<char, vector<int>> mapa;
        string linea; cin>>linea;
        rep(i, int(linea.length())) { 
            if(!mapa.count(linea[i])) mapa[linea[i]] = vector<int>(); 
            mapa[linea[i]].push_back(i);
            // cout<<linea[i] << ' ' << i<<'\n';
        }
        int h = 0;
        int xd = 0;
        vector<int> ans(linea.length(), 0);
        for(auto& u: mapa){
            rep(j, min((int)u.ss.size(), k)){
                ans[u.ss[j]] = h + 1; // al indice le doy el color
                h = (h+1) % k;
                if(h == 0) xd++;
                // cout<<"aaaaa\n";
            }
        }
        cout<<xd<<'\n';
    }



    return 0;
}