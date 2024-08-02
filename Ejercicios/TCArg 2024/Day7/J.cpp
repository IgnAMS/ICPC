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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int h, g; cin>>h>>g;
        int n = (1<<h) - 1;
        int A[n]; 
        unordered_map<int, int> Inv; Inv.reserve(n);
        rep(i, n) cin>>A[i], Inv[A[i]] = i;

        vector<vector<int>> S(n, vector<int>());
        ll ans = 0, level = h;
        vector<int> X(n, 0), T(n, 0);
        vector<pair<int,int>> Assign((1<<g) - 1);
        for(int i = n - 1; i >= 0; i--) {
            T[i] = 0;
            if(i + 2 <= (1<<(level))) level--;
            // cout<<"xd: "<<i<<' '<<h - level<<'\n';
            S[i].reserve(1<<(h - level - 1));
            // Soy una hoja
            if(2 * i + 2 >= n) {
                S[i].pb(A[i]);
                continue;
            }

            // No soy una hoja
            ll mn = max(T[2 * i + 1], T[2 * i + 2]);
            
            int j1 = 0, j2 = 0;
            bool unused = 0;
            while(j1 < S[2 * i + 1].size() or j2 < S[2 * i + 2].size()) {
                if(j1 == S[2 * i + 1].size()) S[i].pb(S[2 * i + 2][j2++]);
                else if(j2 == S[2 * i + 2].size()) S[i].pb(S[2 * i + 1][j1++]);
                // j1 < S[2 * i + 1].size()
                // j2 < S[2 * i + 2].size()
                else if(S[2 * i + 1][j1] < S[2 * i + 2][j2]) S[i].pb(S[2 * i + 1][j1++]);
                else S[i].pb(S[2 * i + 2][j2++]);
            }
            S[i].pb(A[i]);
            
            if(i < (1<<g) - 1) {
                ll x = *upper_bound(S[i].begin(), S[i].end(), mn);
                // cout<<"asigno "<<x<<' '<<Inv[x]<<" en "<<i<<'\n';
                T[i] = x;
                X[Inv[x]] = 1;
                Assign[i] = {x, Inv[x]};
                ans += x;
            }
            // Caso contrario T[i] = 0 por la linea 31
        }

        vector<int> Ans;
        // Saco todos los 0's
        for(int i = n - 1; i >= 0; i--) {
            // Soy hoja y no tengo hijos
            if(2 * i + 2 >= n) {
                if(X[i] == 0) Ans.pb(i);
                continue;
            }
            // No soy hoja y no tengo hijos 
            X[i] += X[2 * i + 1] + X[2 * i + 2];
            if(X[i] == 0) Ans.pb(i);
        }

        // Asigno todo lo que deba asignar
        sort(Assign.begin(), Assign.end());

        vector<int> V(n, 0);
        rep(i, n) V[i] = X[i];
        for(auto [num, u]: Assign) {
            int p = (u - 1) / 2;          
            while(u != p and (V[p] -= X[u]) == 0) {
                Ans.pb(p);
                u = p;
                p = (p - 1) / 2;
            }
        }
        cout<<ans<<'\n';
        for(auto u: Ans) cout<<u + 1<<' '; cout<<'\n';
    }

    return 0;
}