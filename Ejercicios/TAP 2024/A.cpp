#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

// turn = 0 es el primer jugador
// turn = 1 es el segundo jugador
// DP[mask][turn] = 2 si es que no hay posicion ganadora ni perdedora
// DP[mask][turn] = 1 si es que es posicion ganadora para el primer jugador 
// DP[mask][turn] = 0 si es que es posicion perdedora para el primer jugador
ll DP[20000][2]; // DP[3^9][turn]
// mask = 0 si no ha sido usado, 1 si ha sido usado por 1, 2 si ha sido usado por el jugador 2


ll Pot3[9];

vector<array<ll, 3>> Ganadora = {
    // Verticales
    {0, 3, 6}, 
    {1, 4, 7},
    {2, 5, 8},
    // Horizontales
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    // Diagonales
    {0, 4, 8},
    {2, 4, 6}
};


bool check_jugador(ll mask, ll turn) {
    ll x = (turn? 2: 1);
    for(auto& vec: Ganadora) {
        bool oc = 1;
        for(auto& u: vec) if((mask / Pot3[u]) % 3 != x) oc = 0;
        if(oc) return 1;
    }
    return 0;
}

set<ll> Restrictions[9];

ll dp(ll mask, ll turn) {
    if(DP[mask][turn] != -1) return DP[mask][turn];
    
    rep(b, 2) {
        ll val = check_jugador(mask, b);
        if(val == 1) {
            // cout<<"HOLA: "<<mask<<'\n';
            // rep(i, 9) {
            //     if(i % 3 == 0 and i) cout<<'\n';
            //     cout<<(mask / Pot3[i]) % 3<<' ';
            // }
            // cout<<"\n"<<!b<<"\n\n";
            return DP[mask][turn] = !b;
        }
    }
    
    DP[mask][turn] = 2;
    ll jugadas = 0, j1 = 0, j2 = 0;
    rep(i, 9) if((mask / Pot3[i]) % 3 == 0) {
        // Reviso si es que cumple las restricciones
        bool oc = 1;
        for(auto restriction: Restrictions[i]) {            
            if((mask / Pot3[restriction]) % 3 == 0) {
                oc = 0;
                break;
            }
        }
        if(oc == 0) continue;

        jugadas++;
        ll val = dp(mask + Pot3[i] * (turn? 2: 1), !turn);
        if(val == 1) j1++;
        if(val == 0) j2++; 
    }

    // Primer jugador
    if(turn == 0) {
        // Si existe jugada ganadora entonces gano
        if(j1) DP[mask][turn] = 1;
        // Si todas las jugadas son perdedoras entonces pierdo
        else if(j2 == jugadas and jugadas > 0) DP[mask][turn] = 0;
        // Caso contrairo, elijo una jugada de empate
        else DP[mask][turn] = 2;
    }
    // Segundo jugador
    else {
        // Si es que existe jugada perdedora, entonces marco como perder
        if(j2) DP[mask][turn] = 0;
        else if(j1 == jugadas and jugadas > 0) DP[mask][turn] = 1;
        else DP[mask][turn] = 2;
    }

    return DP[mask][turn];
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n) {
        ll a, b; cin>>a>>b; a--, b--;
        Restrictions[b].insert(a);
    }
    // for(auto u: Restrictions[1]) cout<<u<<' '; cout<<'\n';

    Pot3[0] = 1;
    repx(i, 1, 9) Pot3[i] = Pot3[i - 1] * 3;


    rep(i, 20000) rep(b, 2) DP[i][b] = -1;
    ll val = dp(0, 0);

    if(val == 1) cout<<"X\n";
    else if(val == 0) cout<<"O\n";
    else cout<<"E\n";


    return 0;
}

