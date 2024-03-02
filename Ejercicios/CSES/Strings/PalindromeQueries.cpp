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


const int mxN = 2e5+5;

template<const int LIM, const int MOD, const int BASE>
struct Hash {
    vector<int> H, P;
    int n;

    struct ST {
        vl T = vl(4 * LIM, 0);
        void update(int i, ll x, int l = 0, int r = mxN, int u = 0) {
            if(l == r) { T[u] = x; }
            else {
                int m = (l + r) / 2;
                if(i <= m) update(i, x, l, m, 2 * u + 1);
                else update(i, x, m + 1, r, 2 * u + 2);
                T[u] = T[2 * u + 1] + T[2 * u + 2];
            }
             
        }
        ll query(int i, int j, int l = 0, int r = mxN, int u = 0) {
            if(i <= l and r <= j) return T[u];
            if(l > j or r < i) return 0;
            int m = (l + r) / 2;
            return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
        }
    } st;
 
    int binpow(int a, int b) {
        int res = 1;
        while(b) {
            if(b & 1) res = (1LL * res * a) % MOD;
            a = (1LL * a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
 
    Hash(const string& s) {
        H.resize(LIM); P.resize(LIM);
        n = s.length(); 
        int b = 1;
        H[0] = 0;
        st.update(0, 0);
        rep(i, n) {
            H[i + 1] = (H[i] + 1LL * b * (s[i] - 'a' + 1)) % MOD;
            st.update(i + 1, 1LL * b * (s[i] - 'a' + 1) % MOD);
            b = (1LL * b * BASE) % MOD;
        }
        P[n] = binpow(b, MOD - 2);
        for(int i = n - 1; i >= 0; i--) P[i] = (1LL * P[i + 1] * BASE) % MOD; 
    }
    int query(int l, int r) { 
        // return (1LL * (H[r] - H[l] + MOD) * P[l]) % MOD;
        return (1LL * (st.query(l + 1, r) % MOD) * P[l]) % MOD;
    }
    void update(int i, char c) {
        ll x = (1LL * binpow(BASE, i) * (c - 'a' + 1)) % MOD;
        st.update(i + 1, x);
    }
};


int main() { 
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    string s; cin>>s;
    
    Hash<200005, 1000000007, 123> H(s);
    
    string revs = s;
    reverse(revs.begin(), revs.end());
    Hash<200005, 1000000007, 123> revH(revs);

    while(m--) {
        int com; cin>>com;
        if(com == 1) {
            int i; char c; cin>>i>>c; i--;
            int revi = n - i - 1;
            H.update(i, c);
            revH.update(revi, c);
        }
        else {
            int a, b; cin>>a>>b; 
            int reva = n - a + 1, revb = n - b + 1;
            bool palindrome = (H.query(a, b) == revH.query(revb, reva));
            cout<<(palindrome? "YES": "NO")<<'\n';
        }
    }
    




    return 0;
}