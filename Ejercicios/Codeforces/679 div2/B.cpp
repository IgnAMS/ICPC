#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        map<multiset<int>,vector<int>> filas;
        vector<vector<int>> col(m,vector<int>(n));
        
        rep(i,n){
            multiset<int> auxm;
            vector<int> aux(m);
            rep(j,m) { cin>>aux[j]; auxm.insert(aux[j]);}
            filas.insert(make_pair(auxm,aux));
        }

        rep(i,m){
            rep(j,n) cin>>col[i][j];
        }
        //cerr<<"vivo aca\n";
        rep(i,n){
            multiset<int> aux;
            for(auto& v: col) aux.insert(v[i]);
            vector<int>& a=filas[aux];
            rep(j,m) cout<<a[j]<<" ";
            cout<<"\n";
        }
    }



    return 0;
}