#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


int n; 
ll Q[n];


vector<array<ll, 3>> M1(int hora, int minuto, int angle) {
    vector<array<ll, 3>> P;
    rep(i, 12) {
        int new_hora = (hora + i * 30) % 360;
        // di la vuelta completa
        if(hora > new_hora) {
            if(hora <= minuto or minuto <= new_hora) break;
        }
        else if(hora <= minuto and minuto <= new_hora) break;
        int new_minute = minuto;
        while(new_minute != new_hora) {
            int ang1 = abs(new_minute)
        }
    }
}



ll DP[21][360][360];
ll dp(int i, int hora, int minuto) {
    if(i == n) return 0;
    if(DP[i][hora][minuto] != -1) return DP[i][hora][minuto];



}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string linea; cin>>linea;
    ll hora = 0, minuto = 0;
    bool b = 1;
    for(int i = 0; i < linea.length(); i++) {
        if(linea[i] == ':') b = 0;
        else if(b) hora = hora * 10 + (linea[i] - '0');
        else minuto = minuto * 10 + (linea[i] - '0');
    }







    return 0;
}