#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include <algorithm>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


string S[100];
const int MOD = 1e9+7;
int n, m, d0, d1, d2;

ll binpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % MOD; 
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return binpow(x, MOD - 2);
}

pll Adj[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pll Corner[] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

ll adjacent(int i, int j, char c) {
    int ans = 0;
    rep(h, 4) {
        int di = i + Adj[h].ff, dj = j + Adj[h].ss;
        if(0 <= di and di < n and 0 <= dj and dj < m and S[di][dj] == c) ans++;
    }
    return ans;
}
ll corner(int i, int j, char c) {
    int ans = 0;
    rep(h, 4) {
        int di = i + Corner[h].ff, dj = j + Corner[h].ss;
        if(0 <= di and di < n and 0 <= dj and dj < m and S[di][dj] == c) ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>d0>>d1>>d2;
    ll ans = 0;
    rep(i, n) {
        cin>>S[i];
    }
    rep(i, n) rep(j, m) {
        int adj_infected = adjacent(i, j, 'V'), adj_prob = adjacent(i, j, '?'),
            corner_infected = corner(i, j, 'V'), corner_prob = corner(i, j, '?');

        if(S[i][j] == '.') {
            // prob_d1 = (1<<adj_prob - 1 + bool(adj_infected)) / (1<<adj_infected)
            // prob_d2 = (1<<corner_prob - 1 + bool(corner_infected)) / (1<<corner_prob) * (1 - prob_d1)
            ll prob_d1 = ((1<<adj_prob) - 1 + bool(adj_infected)) * inv(1<<adj_prob) % MOD;
            ll prob_not_d1 = (1 - bool(adj_infected)) * inv(1<<adj_prob) % MOD;
            ll prob_d2 = ((1<<corner_prob) - 1 + bool(corner_infected)) * inv(1<<corner_prob) % MOD;
            prob_d2 = prob_d2 * prob_not_d1 % MOD;
            // cout<<"i: "<<i<<", j: "<<j<<", adj_inf: "<<adj_infected<<", adj_prob: "<<adj_prob<<", prob_d1: "<<prob_d1<<", prob_d2: "<<prob_d2<<"\n";
            ans += d1 * prob_d1 + d2 * prob_d2;
            ans %= MOD;
        }
        else if(S[i][j] == '?') {
            ll prob_d0 = inv(2);
            ll prob_not_d0 = inv(2);
            ll prob_d1 = (((1<<adj_prob) - 1 + bool(adj_infected)) * inv(1<<adj_prob)) % MOD;
            prob_d1 = (prob_not_d0 * prob_d1) % MOD;
            ll prob_not_d1 = (1 - bool(adj_infected)) * inv(1<<adj_prob) % MOD;
            ll prob_d2 = (((1<<corner_prob) - 1 + bool(corner_infected)) * inv(1<<corner_prob)) % MOD;
            prob_d2 = (((prob_d2 * prob_not_d1) % MOD) * prob_not_d0) % MOD;
            
            // cout<<"i: "<<i<<", j: "<<j<<", adj_inf: "<<adj_infected<<", adj_prob: "<<adj_prob<<", prob_d1: "<<prob_d1<<", prob_d2: "<<prob_d2<<"\n";
            ans += d0 * prob_d0 + d1 * prob_d1 + d2 * prob_d2;
            ans %= MOD;
        }
        else {
            ans += d0;
        }
    }
    cout<<ans<<"\n";

    


    return 0;
}