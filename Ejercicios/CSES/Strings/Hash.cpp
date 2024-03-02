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

template<const int LIM, const int MOD, const int BASE>
struct Hash {
    int binpow(int a, int b) {
        int res = 1;
        while(b) {
            if(b & 1) res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int H[LIM], P[LIM];
    void init(const string& s) {
        int n = s.size(), b = 1;
        H[0] = 0;
        rep(i, n) {
            H[i + 1] = (H[i] + 1LL * b * (s[i] - 'a' + 1)) % MOD;
            b = (1LL * b * BASE) % MOD;
        }
        P[n] = binpow(b, MOD - 2);
        for(int i = n - 1; i >= 0; i--) P[i] = (1LL * P[i + 1] * BASE) % MOD; 
    }
    int query(int l, int r) { return (1LL * (H[r] - H[l] + MOD) * P[l]) % MOD; }
};

struct MultiHash {    
    Hash<200200, 1000000007, 123> A; 
    Hash<200200, 1000000009, 1234> B;
    Hash <200200, 1000000021, 12345> C;

    void init(const string &s) {
        A.init(s); B.init(s); C.init(s);
    }

    vector<int> query(int l, int r) {
        vector<int> q;
        q.pb(A.query(l, r)); q.pb(B.query(l, r)); q.pb(C.query(l, r));
        return q; 
    }    
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);






    return 0;
}