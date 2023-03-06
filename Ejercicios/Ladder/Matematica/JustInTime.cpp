#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

ll segmentedSieve(ll L, ll R) {
    // generate all primes up to sqrt(R)
    // cout<<L<<' '<<R<<'\n'; 
    ll lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vl primes;
    repx(i, 2, lim + 1) {
        if (!mark[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = 1;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    ll mx = 0;
    rep(i, R - L + 1) if(isPrime[i]) mx = L + i;
    return mx;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    cout<<segmentedSieve(max(2LL, n - 1000000LL), n)<<'\n';


    return 0;
}