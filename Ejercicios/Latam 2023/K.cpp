#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<int> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1<<24;
int DP[mxN];
int First[301][301];
int P[mxN];
int n, k; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>k;
    int V[n]; 
    rep(i, n) cin>>V[i], V[i]--;

    // Si no aparece entonces termino
    vl X(k, 0);
    rep(i, n) X[V[i]] = 1;
    rep(i, k) if(X[i] == 0) {
        cout<<i + 1<<' ';
        rep(j, k) if(j != i) cout<<j + 1<<' '; 
        cout<<'\n';
        return 0; 
    }

    if(k >= 21) {
        // Encuentro el que esta mas lejano las suficientes veces
        vl X(k, 0), curr;
        int ind = 0;
        rep(i, k) {
            vl last(k, n);
            repx(j, ind, n) {
                if(X[V[j]] == 0) last[V[j]] = min(last[V[j]], j); 
            }
            int lejano = -1;
            rep(j, k) {
                if(X[j] == 0 and lejano == -1) lejano = j;
                else if(X[j] == 0 and last[lejano] < last[j]) lejano = j; 
            }
            ind = last[lejano] + 1;
            X[lejano] = 1;
            curr.pb(lejano);
            if(ind >= n) break;
        }
        for(auto u: curr) cout<<u + 1<<' ';
        rep(j, k) if(X[j] == 0) cout<<j + 1<<' ';
        cout<<'\n';
    }
    else {
        // Construyo el firsts
        rep(j, k) First[j][n] = n;
        for(int i = n - 1; i >= 0; i--) {
            First[V[i]][i] = i;
            rep(j, k) if(j != V[i]) First[j][i] = First[j][i + 1];
        }

        // Construyo mi DP con el bitmask
        rep(mask, (1<<k)) {
            DP[mask] = 0;
            rep(i, k) if(mask & (1<<i)) {
                int x = DP[mask ^ (1<<i)];
                if(x < n and First[i][x] + 1 > DP[mask]) {            
                    DP[mask] = First[i][x] + 1;
                    P[mask] = i;
                }
                else if(x >= n) DP[mask] = n + 1, P[mask] = i;
            }
        }

        // cerr<<(1<<23) * 23<<'\n';
        int val = DP[(1<<k) - 1];
        if(val <= n) cout<<"*\n";
        else {
            int mask = (1<<k) - 1;
            vl curr; curr.reserve(k);
            while(mask) {
                // cout<<"anado a "<<P[mask]<<'\n';
                curr.pb(P[mask]);
                mask ^= (1<<P[mask]);
            }
            reverse(curr.begin(), curr.end());
            for(auto u: curr) cout<<u + 1<<' '; cout<<'\n';
        }
    }

    return 0;
}