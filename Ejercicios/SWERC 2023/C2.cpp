#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(long long i=a; i<b; i++)
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


ll Mask[50];
ll n, m; 

string mask_to_string(ll mask, ll state) {
    string ans = "";
    rep(i, n) {
        if((mask & (1<<i)) and (state & (1<<i))) ans += char('0' + 2);
        else if(mask & (1<<i)) ans += char('0' + 1);
        else ans += '0';
    }
    return ans;
}

string mask_to_string(ll mask) {
    string ans = "";
    rep(i, max(n, m)) {
        if(mask & (1<<i)) ans += char('0' + 1);
        else ans += char('0');
    }
    return ans;
}


unordered_map<ll, double> DP[1<<18];

// dado un bitmask me da los que si estan dentro de este bitmask
ll lines[1<<18], not_lines[1<<18]; 


db dp(ll mask, ll state) {
    // Esto me dice cuantas lineas hay que cumplen que tienen las estaciones mask ^ state y las que no tienen las estaciones mask & state
    ll more_or_eq = __builtin_popcountll(lines[mask ^ state] & not_lines[mask & state]);
    if(more_or_eq == 0) return 1e10;
    if(more_or_eq == 1) {
        // cout<<mask_to_string(mask, state)<<' '<<mask<<' '<<state<<" es terminal, solo representa a "<<mask_to_string(lines[mask ^ state] & not_lines[mask & state])<<"\n";
        return 0.;
    }

    if(DP[mask].count(state)) return DP[mask][state];

    DP[mask][state] = 1e10;
    rep(i, n) if(!(mask & (1<<i))) {
        ll maskyes = mask | (1<<i), state_yes = state;
        ll maskno  = mask | (1<<i), state_no  = state | (1<<i);
        ll cont = __builtin_popcountll(lines[maskyes ^ state_yes] & not_lines[maskyes & state_yes]);
        // Si es que no me aportara nada, entonces no lo proceso
        if(cont == 0 or cont == more_or_eq) continue;
        // Caso contrario, me ayuda a discernir :)
        DP[mask][state] = min(
            DP[mask][state],
            dp(maskyes, state_yes) * db(cont) / db(more_or_eq) 
            + dp(maskno, state_no) * (db(more_or_eq - cont) / db(more_or_eq)) 
            + 1.0
        );
    }
    // cout<<mask_to_string(mask, state)<<' '<<DP[mask][state]<<'\n';
    return DP[mask][state];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    set<ll> S;
    rep(i, m) {
        int k; cin>>k;
        rep(j, k) {
            int x; cin>>x;
            Mask[i] |= (1<<x);
        }
        // Si hay dos mascaras con el mismo valor, claramente no es posible
        if(S.count(Mask[i])) {
            cout<<"not possible\n";
            return 0;
        }
        S.insert(Mask[i]);
    }

    for(ll mask = 0; mask < (1<<n); mask++) {
        lines[mask] = not_lines[mask] = 0;
        rep(j, m) {
            // No hay nada en mask que no este en la linea j
            if((mask & (~Mask[j])) == 0) lines[mask] |= (1LL<<j);
            // Todo lo que esta en mask no esta en la linea j
            if((mask & Mask[j]) == 0) not_lines[mask] |= (1LL<<j);
        }
        // cout<<mask_to_string(mask)<<' '<<mask_to_string(lines[mask])<<' '<<mask_to_string(not_lines[mask])<<'\n';
    }
    cout<<setprecision(8)<<fixed<<dp(0, 0)<<'\n';
    return 0;
}