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
    vector<int> H, P;
 
    int binpow(int a, int b) {
        int res = 1;
        while(b) {
            if(b & 1) res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
 
    void init(const string& s) {
        H.resize(LIM); P.resize(LIM);
        int n = s.length(), b = 1;
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; 
    bool xd = 0;
    while(getline(cin, s)) {
        if(xd) cout<<'\n';
        xd = 1;
        string s2 = "";
        for(auto c: s) if(c != ' ') s2 += c;
        s = s2;
        int n = s.length();

        Hash<1004, 1000000007, 123> H;
        H.init(s);
        unordered_map<ll, ll> mp[n];
        rep(i, n) mp[i].reserve(n);
        rep(i, n) repx(j, i, n) {
            ll val = H.query(i, j + 1);
            int largo = j - i;
            if(!mp[largo].count(val)) mp[largo][val] = 0;
            mp[largo][val]++;
        }

        rep(i, n) {
            ll mx = 0;
            for(auto [a, b]: mp[i]) mx = max(mx, b);
            if(mx <= 1) break;
            cout<<mx<<'\n';
        }
    }


    return 0;
}