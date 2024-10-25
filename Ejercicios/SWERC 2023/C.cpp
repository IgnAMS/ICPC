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


ll Mask[50];
int n, m; 
ll Pot3[20];


string mask_to_string(ll mask) {
    string ans = "";
    rep(i, n) {
        ll val = ((mask / Pot3[i]) % 3);
        ans += char('0' + val);
    }
    return ans;
}

unordered_map<ll, double> DP;


db dp(ll mask) {
    // esta totalmente contenido
    ll more_or_eq = 0;
    vector<ll> X;
    rep(j, m) {
        bool inside = 1;
        bool lessb = 0;
        rep(i, n) {
            if(((Mask[j] / Pot3[i]) % 3) == 1 and ((mask / Pot3[i]) % 3) == 2) inside = 0;
            if(((Mask[j] / Pot3[i]) % 3) == 0 and ((mask / Pot3[i]) % 3) == 1) inside = 0;
            if(((Mask[j] / Pot3[i]) % 3) == 1 and ((mask / Pot3[i]) % 3) == 0) lessb = 1;
        }
        if(inside) {
            more_or_eq++;
            X.pb(j);
        }
    }
    if(more_or_eq == 0) return 1e10;
    if(more_or_eq == 1) {
        return 0.;
    }
    // caso contrario no ha terminado
    
    if(DP.count(mask)) return DP[mask];

    DP[mask] = 1e10;
    rep(i, n) if(((mask / Pot3[i]) % 3) == 0) {
        // opcion de si tomarlo
        ll maskyes = mask + Pot3[i], maskno = mask + 2 * Pot3[i], cont = 0;
        // cout<<"veo el bit "<<i<<" con la mascara "<<mask_to_string(mask)<<" mis vecinos son "<<mask_to_string(maskyes)<<' '<<mask_to_string(maskno)<<'\n';
        for(auto j: X) {
            if((Mask[j] / Pot3[i]) % 3 == 1) cont++;
        }
        DP[mask] = min(
            DP[mask], 
            dp(maskyes) * db(cont) / db(more_or_eq) + dp(maskno) * (db(more_or_eq - cont) / db(more_or_eq)) + 1.0
        );
    }
    // cout<<mask_to_string(mask)<<' '<<DP[mask]<<'\n';
    return DP[mask];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    set<ll> S;
    Pot3[0] = 1;
    repx(i, 1, 18) Pot3[i] = Pot3[i - 1] * 3LL;
    rep(i, m) {
        int k; cin>>k;
        rep(j, k) {
            int x; cin>>x;
            Mask[i] += Pot3[x];
        }
        if(S.count(Mask[i])) {
            cout<<"not possible\n";
            return 0;
        }
        S.insert(Mask[i]);
    }
    DP.reserve((1<<n) * m);
    cout<<setprecision(6)<<fixed<<dp(0)<<'\n';

    return 0;
}