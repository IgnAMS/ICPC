#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

ll MOD = 1e9 + 7;

ll solve(string s, int m, int d) {
    int n = s.length();
    ll z[n + 1][m + 1][2];
    rep(i, n + 1) rep(j, m + 1) rep(k, 2) z[i][j][k] = 0;
    z[0][0][1] = 1;
    rep(i, n) rep(j, m) rep(k, 2) {
        int tope = (k? int(s[i] - '0') : 9) + 1;
        rep(p, tope) {
            if(i == 0 and p == 0) continue;
            if(i % 2 == 0 and p == d) continue; // estoy en posicion impar y p == d
            if(i % 2 == 1 and p != d) continue; // estoy en posicion par y p != d
            int k_ = k && (p == int(s[i] - '0'));
            z[i + 1][(j * 10 + p) % m][k_] = (z[i + 1][(j * 10 + p) % m][k_] + z[i][j][k]) % MOD;
            // printf("z[%d, %d, %d], p: %d = %lld\n", i + 1, (j * 10 + p) % m, k_, p, z[i + 1][(j * 10 + p) % m][k_]);
            // cout<<i + 1<<' '<<(j * 10 + p) % m<<' '<<k_<<": "<<z[i + 1][(j * 10 + p) % m][k_]<<'\n';
        }
    }
    return (z[n][0][0] + z[n][0][1]) % MOD;
}

ll good(string s, int m, int d) {
    ll j = 0;
    bool oc = 0;
    rep(i, s.length()) {
        // posicion impar
        if(i % 2 == 0 and int(s[i] - '0') == d) oc = 1;
        if(i % 2 == 1 and int(s[i] - '0') != d) oc = 1;
        j = (j * 10 + int(s[i] - '0')) % m;  
    }
    return (j == 0 and !oc);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int m, d; cin>>m>>d;
    string a, b; cin>>a>>b;
    cout<<((solve(b, m, d) - solve(a, m, d) + MOD) % MOD + good(a, m, d)) % MOD<<'\n';

    return 0;
}