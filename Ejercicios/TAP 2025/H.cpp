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


vl get_primes(vl A) {
    vl P = {};
    sort(A.begin(), A.end());
    for(auto u: A) {
        for(auto p: P) {
            while(u % p == 0) u /= p;
        }
        if(u != 1) P.pb(u);
    }
    return P;
}

vl combinations = {};
void back_trakc_comb(int i, int x, ll curr, vl& P, vl& Pot) {
    // peor de los casos es como 20 * 20 lo cual no es terrible
    if(i == P.size()) {
        combinations.pb(curr);
        return;
    }
    if(x < Pot[i]) back_trakc_comb(i, x + 1, curr * P[i], P, Pot);
    back_trakc_comb(i + 1, 0, curr, P, Pot);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n);
    ll mcm = 1;
    set<ll> S;
    rep(i, n) {
        cin>>A[i];
        S.insert(A[i]);
        ll g = __gcd(mcm, A[i]);
        mcm = mcm / g * A[i];
    }
    sort(A.begin(), A.end());
    
    if(mcm == 1) {
        cout<<"*\n"; 
        return 0;
    }

    if(A[0] != 1) {
        cout<<mcm<<' '<<1<<'\n';
        return 0;
    }

    if(n == 2) {
        ll sqr = ll(sqrt(A[1]) + 1e-15);
        if(sqr * sqr == A[1]) cout<<A[1]<<' '<<sqr<<'\n';
        else cout<<A[1] * A[1]<<' '<<A[1] * A[1]<<'\n';
        return 0;
    }

    // 2
    // 1, 4
    // ans: 2

    // 4
    // 1, 2, 4, 8
    // ans: 16
    
    // 3
    // 1, 4, 8
    // ans: 8

    // 3
    // 1, 2, 8
    // ans: 8

    // 5
    // 1 4 5 10 20
    // ans: 20

    if(A[n - 1] == mcm) {
        // 1, 4, 8 -> {4, 2}
        vl P = get_primes(A);
        // {4, 2} -> {2}
        P = get_primes(P);

        map<ll, ll> powers;
        for(auto p: P) powers[p] = 1;
        for(auto u: A) {
            for(auto p: P) {
                int cont = 0;
                while(u % p == 0) u /= p, cont++;
                powers[p] = max(powers[p], 1LL * cont);
            }
        }
        vl Pot = {};
        for(auto [p, pot]: powers) Pot.pb(pot);

        back_trakc_comb(0, 0, 1, P, Pot);
        for(auto comb: combinations) {
            if(!S.count(comb)) {
                cout<<mcm<<' '<<comb<<'\n';
                return 0;
            }
        }

        // 1, 2, 4, 8 -> 16
        cout<<A[n - 1] * A[1]<<' '<<A[n - 1] * A[1]<<'\n';
    }
    // Faltaba solo X
    else {
        cout<<mcm<<' '<<mcm<<'\n';
    }


    return 0;
}