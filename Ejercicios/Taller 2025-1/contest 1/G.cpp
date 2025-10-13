#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
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

// 3^9 = 19683 = 20000
ll DP[20000][2];
ll Pot3[10];
bool Restriccion[10][10];

// returns -1 if none wins, 0 if A wins, 1 if B wins
ll check_tablero(int tablero) {
    repx(jugador, 1, 3) {
        for(int i = 0; i <= 2; i++) {
            bool pos = 1;
            rep(offset, 3) {
                ll val = (tablero / Pot3[i + 3 * offset]) % 3;
                if(val != jugador) pos = 0;
            }
            if (pos) return jugador;
            pos = 1;
            rep(offset, 3) {
                ll val = (tablero / Pot3[3 * i + offset]) % 3;
                if(val != jugador) pos = 0;
            }
            if(pos)
                return jugador;
        }
        bool pos = 1;
        for(auto i : {0, 4, 8}) {
            ll val = (tablero / Pot3[i]) % 3;
            if(val != jugador)
                pos = 0;
        }
        if(pos) return jugador;
        pos = 1;
        for(auto i : {2, 4, 6}) {
            ll val = (tablero / Pot3[i]) % 3;
            if(val != jugador) pos = 0;
        }
        if(pos) return jugador;
    }
    return -1;
}

void print_tablero(int tablero) {
    rep(i, 9) {
        ll val = (tablero / Pot3[i]) % 3;
        cout<<val<<" ";
        if(i % 3 == 2) cout << '\n';
    }
    cout<<'\n';
}

// -1 if it is a draw, 0 if A wins, 1 if B wins
ll dp(int tablero, int turno) {
    if(DP[tablero][turno] != -2) return DP[tablero][turno];
    
    if(check_tablero(tablero) != -1) {
        // cout<<"Gana jugador! "<<check_tablero(tablero)<<"!\n";
        // print_tablero(tablero);
        // cout<<"-------------\n";
        return DP[tablero][turno] = !turno;
    }

    int any_jugable = 0;
    bool ganable = 0;
    bool empatable = 0;
    rep(i, 9) if ((tablero / Pot3[i]) % 3 == 0) {
        bool jugable = 1;
        rep(j, 9) if(Restriccion[j][i] and (tablero / Pot3[j]) % 3 == 0) jugable = 0;
        if(!jugable) continue;

        any_jugable++;
        ll jugada = dp(tablero + (1 + turno) * Pot3[i], !turno);
        if(jugada == -1) empatable = 1;
        if(jugada == turno) ganable = 1;
    }
    if(any_jugable == 0) DP[tablero][turno] = -1;
    else if(ganable) DP[tablero][turno] = turno;
    else if(empatable) DP[tablero][turno] = -1;
    else DP[tablero][turno] = !turno;

    // print_tablero(tablero);
    // cout<<DP[tablero][turno]<<' '<<any_jugable<<' '<<ganable<<' '<<empatable<<'\n';
    // cout<<"-------------\n";
    return DP[tablero][turno];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    Pot3[0] = 1;
    repx(i, 1, 10) Pot3[i] = Pot3[i - 1] * 3;
    rep(i, 20000) rep(j, 2) DP[i][j] = -2;
    rep(i, 10) rep(j, 10) Restriccion[i][j] = 0;
    rep(i, n) {
        int a, b; cin >> a >> b; a--, b--;
        // cout<<a<<' '<<b<<'\n';
        Restriccion[a][b] = 1;
    }
    ll ganador = dp(0, 0);
    if(ganador == -1) cout<<"E\n";
    else if(ganador == 0) cout<<"X\n";
    else cout<<"O\n";

    return 0;
}