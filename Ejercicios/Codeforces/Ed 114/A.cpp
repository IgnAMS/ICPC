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
    map<int, vector<string>> mapa;
    map<int, int> aux;
    while(t--){
        int n; cin>>n;
        if(mapa.count(n)) {
            rep(i, n) cout<<mapa[n][(i + aux[n]) % n]<<'\n';
            aux[n] += 1;
            continue;
        }
        mapa[n] = vector<string>(n);
        aux[n] = 1;
        rep(i, n){
            string line = "";
            rep(j, i+1) line +="(";  rep(j, i+1) line += ")"; // abro i, y cierro i
            rep(j, n-i-1) line += "()";
            cout<<line<<'\n';
            mapa[n][i] = line;
        }
        



    }


    return 0;
}