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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k; 
        ll A[n][n];
        rep(i, n) repx(j, i, n) cin>>A[i][j];
        
        vl DP[n];
        rep(i, n) {
            // los vl de pq son del tipo: [valor, de donde vengo, indice en el vector de donde vengo]
            priority_queue<array<ll, 3>> pq;
            
            // Primero añado lo que si puedo extender segmento [j, i] + el mejor segmento de j - 2
            for(int j = 0; j <= i; j++) {
                if(j >= 2) pq.push({A[j][i] + DP[j - 2][0], j - 2, 0});
                else pq.push({A[j][i], -1, 0});
            }

            // No creo un intervalo
            if(i) pq.push({DP[i - 1][0], i - 1, 0});
            else pq.push({0, -1, 0});

            while(DP[i].size() < k and !pq.empty()) {
                auto [val, j, ind] = pq.top(); pq.pop();
                DP[i].pb(val);

                if(j == -1) continue;
                if(ind + 1 == DP[j].size()) continue;
                
                if(j == i - 1) pq.push({DP[i - 1][ind + 1], i - 1, ind + 1});
                else if(j == i) continue;
                else pq.push({A[j + 2][i] + DP[j][ind + 1], j, ind + 1});
            }
        }
        for(auto u: DP[n - 1]) cout<<u<<' '; cout<<'\n';
    }



    return 0;
}