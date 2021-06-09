#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;


int main(){ 
    ios::sync_with_stdio(0); cin.tie(0);
    map<char,int> mapa;
    mapa['W'] = 64; mapa['H'] = 32; mapa['Q'] = 16; mapa['E'] = 8;
    mapa['S'] = 4; mapa['T'] = 2; mapa['X'] = 1;
    string linea; 
    while(cin>>linea && linea != "*"){
        int ans=0;
        int cont=0;
        for(auto& c: linea){
            if(c == '/') { if(cont==64) ans++; cont = 0; }
            else cont += mapa[c];
        }
        cout<<ans<<"\n";
    }



    return 0;
}