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

const int mxN = 106;
int n;
ll A[mxN];


unordered_map<ll, ll> G;
int dp(ll mask) {
    if(mask == 0) return 0;
    if(G.count(mask)) return G[mask];

    vl X;
    rep(i, 30) if((1<<i) <= mask) {
        // cerr<<"itero en "<<i<<'\n';
        ll right = mask >> (i+1);
        ll left = (mask & ((1<<i) - 1));
        // cerr<<mask<<' '<<left<<' '<<right<<'\n';
        X.pb(dp(left | right));
    }
    sort(X.begin(), X.end());
    int mex = X.size();
    rep(i, (int)X.size() - 1) {
        if(X[i] + 1 < X[i + 1]) {
            mex = X[i] + 1;
            break;
        }
        if(X[i] == X[i + 1]) mex--;
    }
    if(X[0] != 0) mex = 0;
    // cout<<"G[u]: ";
    // cerr<<X.size()<<'\n';
    // for(auto u: X) cout<<u<<' '; cout<<'\n'; 
    // cout<<"mex: "<<mex<<'\n';
    
    return G[mask] = mex;
}

int solve(ll p) {
    int mask = 0;
    rep(i, n) {
        for(ll d = p, cont = 0; d <= A[i]; d *= p, cont++) {
            if(A[i] % d == 0 and A[i] % (d * p) != 0) {
                mask |= (1<<cont);
                break;
            }
        }
    }
    return dp(mask);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>A[i];
    G.reserve(100000);
    set<int> Div, Primes;
    // Consigo los numeros primos :)

    // 10^5 * 10^2 ~ 10^7 
    rep(i, n) {
        for(ll d = 2; d * d <= A[i]; d++) {
            if(A[i] % d == 0) Div.insert(d), Div.insert(A[i] / d);
        }
        if(A[i] != 1) Div.insert(A[i]);
    }

    int ans = 0;
    // 100 * 10 <= 10^4 
    for(auto d: Div) {
        bool prime = 1;
        for(auto p: Primes) if(d % p == 0) prime = 0;
        if(!prime) continue;
        
        Primes.insert(d);
        // Para cada primo consigo su grundy number
        int x = solve(d);
        ans ^= x;
    }
    if(ans) cout<<"Mojtaba\n";
    else cout<<"Arpa\n";

    return 0;
}