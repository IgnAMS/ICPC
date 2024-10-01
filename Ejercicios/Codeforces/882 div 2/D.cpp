#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin>>n>>m>>q;
    string s; cin>>s;
    set<ll> S; rep(i, n) S.insert(i);
    vl T;
    vl P(n, n);
    rep(i, m) {
        ll l, r; cin>>l>>r; l--, r--;
        while(true) {
            auto it = S.lower_bound(l);
            if(it == S.end()) break;
            if(*it > r) break;
            cerr<<*it<<'\n';
            P[*it] = T.size();
            T.pb(*it);
            S.erase(it);
        }
    }

    // Cada elemento está en zeros, zeros_replaced o no está

    // NT
    set<pll> Ones_NT;           // 1
    set<pll> OnesReplaced_NT;   // 1 -> 0
    
    
    // T
    set<pll> Zeros_T;           // 0
    set<pll> Ones_T;            // 1 
    set<pll> OnesReplaced_T;    // 1 -> 0
    set<pll> ZerosReplaced_T;   // 0 -> 1
    

    rep(i, q) {
        int x; cin>>x; x--;
        if(S.count(x)) {
            // No esta en T, por lo que si era un 1 y estaba reemplazando se convierte en 0
            if(s[x] == '1') {
                if(OnesReplaced_NT.count(pll(n, x))) {
                    // Elimino quien lo reemplazaba
                    eliminar = *ZerosReplaced_T.rbegin();
                    Zeros_T.append(eliminar);
                    ZerosReplaced_T.erase(ZerosReplaced_T.rbegin());
                    // Lo saco de la lista
                    OnesReplaced_NT.erase(pll(n, x));
                }
                // Lo saco de la lista
                else Ones_NT.erase(pll(n, x));
            }
            // Lo agrego a la lista
            else Ones_NT.insert(pll(n, x));
        }
        else {
            if(s[x] == '1') {
                // Si estaba reemplazando saco a quien lo estaba reemplazando y lo saco de los que compartia
                if(OnesReplaced_T.count(pll(P[x], x))) {
                    eliminar = *ZerosReplaced_T;
                    Zeros_T.append(eliminar);
                    ZerosReplaced_T.erase(ZerosReplaced_T.rbegin());
                    OnesReplaced_T.erase(pll(P[x], x));
                }
                // Si no compartia lo saco de la listas de 1's 
                else Ones_T.erase(pll(P[x], x));
                Zeros_T.insert(pll(P[x], x));
            }
            else {
                // Si me habian compartido entonces saco a quien me compartio
                if(ZerosReplaced_T.count(pll(P[x], x))) {
                    if(OnesReplaced_T.size()) OnesReplaced_T.erase(OnesReplaced_T.begin());
                    else OnesReplaced_NT.erase(OnesReplaced_NT.begin());
                }
                // Si no me compartian simplemente me saco de la lista
                else Zeros_T.erase(pll(P[x], x))
                // Me añado como un 1
                Ones_T.insert(pll(P[x], x));
            }
        }

        ll stop = 0;
        while(Zeros_T.size() or OnesReplaced_T.size() and !stop) {
            // El elemento a marcar como 1 será el que tenga menor posicion
            if(*Zeros_T.begin().ff < *OnesReplaced_T.begin().ff) {
                auto compartido = *Zeros_T.begin();
                if(Ones_NT.size()) {
                    // Cambio el NT
                    auto compartidor = *Ones_NT.begin();
                    Ones_NT.erase(compartidor);
                    OnesReplaced_NT.insert(compartidor);

                    // Cambio el T
                    Zeros_T.erase(compartido);
                    ZerosReplaced.insert(compartido);
                }
                else { 
                    // Saco el mas lejano de {ZerosReplaced_T, Ones_T}
                    // En este caso esta mas lejos el OnesReplaced_T
                    pll eliminar;
                    bool where;
                    if(OnesReplaced_T.size() and Ones_T.size() and *ZerosReplaced_T.rbegin().ff > *Ones_T.rbegin().ff) {
                        eliminar = *ZerosReplaced_T.rbegin();
                        where = 0;
                    }
                    else if(ZerosReplaced_T.size() and Ones_T.size()) eliminar = *Ones_T.rbegin(), where = 1;
                    else if(ZerosReplaced_T.size()) eliminar = *ZerosReplaced_T.rbegin(), where = 0;
                    else if(Ones_T.size()) eliminar = *Ontes_T.rbegin(), where = 1;
                    else {
                        stop = 1;
                        continue;
                    }
                    // No me conviene cambiar
                    if(eliminar.ff < compartido.ff) {
                        stop = 1;
                        continue;
                    }

                    // El compartidor es de Ones_T
                    if(where) {
                        Ones_T.erase(eliminar);
                        OnesReplaced_T.insert(eliminar);
                    }
                    else {
                        ZerosReplaced_T.erase(compartidor);
                        Zeros_T.insert(compartidor);
                    }

                }
                
                // Cambio el T
                Zeros_T.erase(compartido);
                ZerosReplaced.insert(compartido);
            }
            else {

            }
        }

    }




    return 0;
}