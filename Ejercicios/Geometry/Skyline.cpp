#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> E; 
        rep(i, n){
            int a, b, c; cin>>a>>b>>c;
            E.push_back({a + 1, 0, i}); // Se abre en a 
            E.push_back({b, 1, i}); // Se cierra en b
        }
        sort(E.begin(), E.end());

        int t = 0, prev = 0, ans = 0;
        multiset<int> S;
        int i = 0;
        bool abrir = 0;
        while(i < E.size()){
            prev = t;
            t = E[i][0];
            cerr<<i<<'\n';
            if(E[i][1] == 0){
                if(S.size() > 1) ans += *next(S.rbegin()) * (t - prev);
                while(i < E.size() and E[i][0] == t and E[i][1] == 0) { // los que son de abrir
                    S.insert(E[i][2]);
                    i++;
                }
                abrir = 1;
            }
            else{
                vector<int> Eliminar;
                while(i < E.size() and E[i][0] == t and E[i][1] == 1) { // los que son de cerrar
                    Eliminar.push_back(E[i][2]);
                    i++;
                }
                if(S.size() > 1) ans += *next(S.rbegin()) * (t - prev + abrir);
                for(auto u : Eliminar) S.erase(S.find(u));
                abrir = 0;
            }
        }
        cout<<ans<<'\n';

    }

    return 0;
}