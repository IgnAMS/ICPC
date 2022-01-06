#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

template<int SZ> struct Sieve
{ 
    bitset<SZ> I; vi P;
    Sieve(){
        I.set();
        for (int i = 2; i * i < SZ; i++) if (I[i])
            for (int j = i * i; j < SZ; j += i) I[j] = 0;
        rep(i, SZ) if (i > 1 && I[i]) P.pb(i);
    }
};

vi Pot;
void fact_prime(ll n, int sign, vi &P){
    int id = 0;
    for(auto u: P) if(u <= n){
        ll x = u;
        while(n >= x) Pot[id] += sign * (n / x), x = x * u;
        id++; 
    }
}

const ll MOD = 1e9 + 7;

inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }

ll binPow(ll a, ll b, const ll M)
{
    if (b == 0) return 1;
    ll r = binPow(a, b / 2, M); r = mul(r, r, M);
    return (b & 1) ? mul(r, a, M) : r;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string line;
    Sieve<1000000> S; // aproximadamente 10^5 elementos
    while(cin>>line){
        Pot.assign(S.P.size(), 0);
        fact_prime(line.length(), 1, S.P);
        map<char, int> mapa;
        rep(i, line.size()){
            if(!mapa.count(line[i])) mapa[line[i]] = 0;
            mapa[line[i]]++;
        }
        for(auto u: mapa) fact_prime(u.ss, -1, S.P);
        ll mini = min(Pot[0], Pot[2]); // minimo entre 2 y 5
        Pot[0] -= mini, Pot[2] -= mini;
        
        ll ans = 1;
        rep(i, Pot.size()){
            ans = (binPow(S.P[i], Pot[i], 10) * ans) % 10;
        }
        cout<<ans<<'\n';
    
    }

    return 0;
}