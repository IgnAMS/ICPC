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

ll n;
string s;

string T[1000005];
int DP[1000005];
int L[1000005], R[1000005];
const ll MOD[] = {998244353, 1000000007};

ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>s;
    rep(i, (1<<n)) { 
        if(2 * i + 1 < s.length() and s[2 * i + 1] > s[2 * i + 2]) {
            L[i] = 2 * i + 2;
            R[i] = 2 * i + 1;
        }
        else L[i] = 2 * i + 1, R[i] = 2 * i + 2;
    }

    ll level = 0;
    for(int i = s.length() - 1; i >= 0; i--) {
        if(i < (1<<(n - level)) - 1) level++;

        if(2 * i + 1 < s.length()) {
            ll duplicate = (T[2 * i + 1] != T[2 * i + 2]);
            T[i] = min(T[2 * i + 1] + s[i] + T[2 * i + 2], T[2 * i + 2] + s[i] + T[2 * i + 1]);
            // cout<<i<<' '<<T[2 * i + 1]<<' '<<T[2 * i + 2]<<' '<<duplicate<<'\n';
            DP[i] = duplicate + DP[L[i]] + DP[R[i]];
        }
        else {
            T[i] = s[i];
            DP[i] = 0;
        }
    }
    cout<<binpow(2, DP[0], MOD[0])<<'\n';

    return 0;
}