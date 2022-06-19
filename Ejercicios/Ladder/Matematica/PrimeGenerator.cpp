#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define pb push_back
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

template<int SZ> struct Sieve { 
    bitset<SZ> I; vi P;
    Sieve() {
        I.set();
        I[1] = 0;
        for (int i = 2; i * i < SZ; i++) if (I[i])
            for (int j = i * i; j < SZ; j += i) I[j] = 0;
        rep(i, SZ) if (i > 1 && I[i]) P.pb(i);
    }
};

Sieve<100000> S;

bool prime(ll x) {
    if(x < 100000) return S.I[x];
    for(auto& u: S.P) if(x % u == 0) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    // 10^5 * 10^4 ~ 10^9
    while(t--) {
        int m, n; cin>>m>>n;
        repx(i, m, n + 1) if(prime(i)) cout<<i<<'\n';
        if(t) cout<<'\n';
    }
    



    return 0;
}