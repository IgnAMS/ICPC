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

ll Comb[101][202]; // cajas, piedras
ll DP[100][200]; // casos beneficiosos
ll S, B;
ll MOD = 1000000007;

ll dp(ll b, ll s){ // la caja b en la que estoy y cuantas piedras me quedan 
    if(b == 1) return (log2(S) + 1e-18 < B-1); // tomo todo
    if(DP[b][s] != -1) return DP[b][s]; 

    DP[b][s] = 0; // lo marco y sigo
    if(log2(S) + 1e-18 < B-b) return 0;
    rep(i, s){
        // las cajas que estan adelante + las que elijo ahora < lo que se necesita para ganar
        if((S - s) + i < (1LL<<(B-b))) {
            cout<<"tengo "<<S-s+i<<" piedras adelante, estoy en la caja "<<b<<'\n';
            cout<<"gano "<<Comb[b-1][i]<<'\n';
            cout<<"pierdo "<<dp(b-1, i)<<'\n';
            DP[b][s] = (DP[b][s] + Comb[b-1][i]) % MOD; // le sumo todos los casos de atras
            DP[b][s] = (DP[b][s] - dp(b-1, i) + MOD) % MOD; // le resto la interseccion de los casos anteriores
        }
    }
    return DP[b][s];
}


ll comb(ll b, ll s){
    if(b == 1) return Comb[b][s] = 1;
    if(Comb[b][s] != -1) return Comb[b][s];
    Comb[b][s] = 0;
    rep(i, s+1){
        Comb[b][s] = (Comb[b][s] + comb(b-1, i)) % MOD;
    }
    return Comb[b][s];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(Comb, -1, sizeof Comb);
    comb(100-1, 200);

    while(cin>>S>>B){
        memset(DP, -1, sizeof DP);
        ll ans = 0;
        rep(i, S+1) cout<<i<<' '<<(1<<(B-1))<<'\n';
        rep(i, S+1) ans = (ans + dp(1, i)) % MOD;
        cout<<ans + dp(B-1, S)<<", respuesta\n";
    }




    return 0;
}