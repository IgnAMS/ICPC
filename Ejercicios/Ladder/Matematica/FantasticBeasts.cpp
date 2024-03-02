#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

pll euclid(ll A, ll B) {
    if (!B) return {1, 0};
    pll p = euclid(B, A % B);
    return {p.ss, p.ff - (A / B) * p.ss};
}

pll CRT(pll a, pll b) {
    if (a.ss < b.ss) swap(a, b);
    ll x, y; 
    tie(x, y) = euclid(a.ss, b.ss); 
    ll g = a.ss * x + b.ss * y, l = a.ss / g * b.ss;
    if ((b.ff - a.ff) % g) return {-1, -1}; // no solution
    x = (b.ff - a.ff) % b.ss * x % b.ss / g * a.ss + a.ff; 
    return {x + (x < 0) * l, l};
}

pll CRT(vector<pll> &v)
{
    int N = v.size(); pll ans = v[0];
    rep(i, N) if(i) {
        ans = CRT(ans, v[i]);
        if(ans.ff == -1) return ans;
    }
    return ans;
}

const ll inf = INT64_MAX;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll b, z; cin>>b>>z;
    ll C[b + 3][z + 3];
    rep(i, b) {
        rep(j, z + 1) cin>>C[i][j];
    }
    vl P(b);
    rep(i, b) P[i] = C[i][0];
    rep(i, z) {
        bool oc = 1;
        ll aux = P[0];
        rep(j, b) {
            if(P[j] != aux) oc = 0;
            P[j] = C[j][P[j]];
        }
        if(oc) {
            cout<<aux<<' '<<i<<'\n';
            return 0;
        }
    }
    
    ll P2[b][z + 3];
    ll L[b]; // length of the cycle
    rep(i, b) {
        L[i] = -1;
        P2[i][0] = P[i];
        repx(j, 1, z + 1) {
            P2[i][j] = C[i][P2[i][j - 1]];
            if(P2[i][j] == P2[i][0] and L[i] == -1) L[i] = j;
        }
    }


    ll ans = inf;
    vector<vector<pll>> E;
    rep(i, L[0]) {
        vector<pll> Ec;
        bool oc = 1;
        rep(j, b) {
            ll m = -1;
            rep(k, L[j]) {
                if(P2[j][k] == P2[0][i]) { 
                    m = k;
                    Ec.push_back({m, L[j]});
                    break; 
                }
            }
            if(m == -1) oc = 0;
        }
        if(oc) { // The element is in every cycle, then do CRT
            pll crt = CRT(Ec);
            if(crt.ff != -1) ans = min(ans, crt.ff);
        }
        E.push_back(Ec);
    } 
    if(ans == inf) cout<<"*\n";
    else cout<<P2[0][ans % L[0]]<<' '<<z + ans<<'\n';
    return 0;
}